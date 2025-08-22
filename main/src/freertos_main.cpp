/**
 * @file    Freertos main file
 * @author  MootSeeker
 * @date    2024-09-02
 * @brief   Main file for FreeRTOS tasks and hooks.
 * @license MIT License
 */

#include "lvgl/src/osal/lv_os.h"

#if LV_USE_OS == LV_OS_FREERTOS

#include "lvgl.h"
#include <cstdio>  // For printf in C++

#include "lvgl/lvgl.h"
#include "lvgl/examples/lv_examples.h"
#include "lvgl/demos/lv_demos.h"

#include "EventSystem.hpp"

#include "StateMachine.hpp"
#include "../States/OffState.hpp"
#include "../States/MainState.hpp"
#include "../States/TempState.hpp"
#include "../States/TempConfirmState.hpp"
#include "../States/FanState.hpp"
#include "../States/FanConfirmState.hpp"
#include "../States/MenuState.hpp"
#include "../States/ClockState.hpp"
#include "../States/TimerState.hpp"
#include "../States/TimerParametrsState.hpp"
#include "../States/ConfigurationState.hpp"
#include "../States/ToolState.hpp"
#include "../States/GrafikState.hpp"
#include "../States/DispetcherState.hpp"
#include "../States/ThemesState.hpp"
#include "../States/VisualState.hpp"

#include "ui.h"
#include "screen_manager.hpp"
#include "esp_lvgl_port.h"
// namespace
// {
//     SemaphoreHandle_t _mux = nullptr;
// };

#define TASK_LIST_BUFFER_SIZE 512
static char pcTaskListBuffer[TASK_LIST_BUFFER_SIZE];

static size_t initHeap = 0;

void vShowTaskList(void)
{
    // Собираем отчёт в буфер
    vTaskList(pcTaskListBuffer);

    size_t freeNow = xPortGetFreeHeapSize();
    size_t freeMin = xPortGetMinimumEverFreeHeapSize();

    if (initHeap == 0)
        initHeap = freeNow;

    // Выводим его по UART (или через printf, если он направлен в UART)

    // printf("Name          State   Prio Stack Num\r\n");
    printf("****************************************\r\n");
    // printf("%s\r\n", pcTaskListBuffer);
    // printf("Free Heap: %ld;  Minimum Heap: %ld\r\n", freeNow, freeMin);
    printf("============= Free Heap: %ld\r\n", initHeap - freeNow);
}

lv_display_t * hal_init(int32_t w, int32_t h);
// ........................................................................................................
/**
 * @brief   Malloc failed hook
 *
 * This function is called when a memory allocation (malloc) fails. It logs the available heap size and enters
 * an infinite loop to halt the system.
 *
 * @param   None
 * @return  None
 */
extern "C" void vApplicationMallocFailedHook(void)
{
    printf("Malloc failed! Available heap: %ld bytes\n", xPortGetFreeHeapSize());
    for( ;; );
}

// ........................................................................................................
/**
 * @brief   Idle hook
 *
 * This function is called when the system is idle. It can be used for low-power mode operations or other
 * maintenance tasks that need to run when the CPU is not busy.
 *
 * @param   None
 * @return  None
 */
extern "C" void vApplicationIdleHook(void) {}

// ........................................................................................................
/**
 * @brief   Stack overflow hook
 *
 * This function is called when a stack overflow is detected in a task. It logs the task name and enters
 * an infinite loop to halt the system.
 *
 * @param   xTask        Handle of the task that caused the stack overflow
 * @param   pcTaskName   Name of the task that caused the stack overflow
 * @return  None
 */
extern "C" void vApplicationStackOverflowHook(TaskHandle_t xTask, char *pcTaskName)
{
    printf("Stack overflow in task %s\n", pcTaskName);
    for(;;);
}

// ........................................................................................................
/**
 * @brief   Tick hook
 *
 * This function is called on each tick interrupt. It can be used to execute periodic operations
 * that need to occur at a fixed time interval.
 *
 * @param   None
 * @return  None
 */
extern "C" void vApplicationTickHook(void) {}

// ........................................................................................................
/**
 * @brief   Create Hello World screen
 *
 * This function creates a simple LVGL screen with a "Hello, World!" label centered on the screen.
 *
 * @param   None
 * @return  None
 */
void create_hello_world_screen()
{
    /* Create a new screen object */
    lv_obj_t *screen = lv_obj_create(NULL);
    if (screen == NULL){
        printf("Error: Failed to create screen object\n");
        /* Return if screen creation fails */
        return;
    }

    /* Create a new label object on the screen */
    lv_obj_t *label = lv_label_create(screen);
    if (label == NULL){
        printf("Error: Failed to create label object\n");
        /* Return if label creation fails */
        return;
    }

    /* Set the text of the label to "Hello, World!" */
    lv_label_set_text(label, "Hello, World!");

    /* Align the label to the center of the screen */
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    /* Load the created screen and make it visible */
    lv_scr_load(screen);
}

// ........................................................................................................
/**
 * @brief   LVGL task
 *
 * This task initializes LVGL and runs the main loop, periodically calling the LVGL task handler.
 * It is responsible for managing the LVGL state and rendering updates.
 *
 * @param   pvParameters   Task parameters (not used in this example)
 * @return  None
 */
void lvgl_task(void *pvParameters)
{
    lv_init();
    hal_init(1024, 600);

    lvgl_port_init();
    screen_manager::init();

    ui_init();

    StateMachine::changeState(StatesID::off_state);

    while (true){
        lvgl_port_lock(0);
        lv_timer_handler(); /* Handle LVGL tasks */
        lvgl_port_unlock();
        vTaskDelay(pdMS_TO_TICKS(33)); /* Short delay for the RTOS scheduler */
    }
}

// ........................................................................................................
/**
 * @brief   Another task
 *
 * This task simulates some background work by periodically printing a message.
 *
 * @param   pvParameters   Task parameters (not used in this example)
 * @return  None
 */
StateMachine fms;

void another_task(void *pvParameters)
{
    vTaskDelay(pdMS_TO_TICKS(1000));

    while (true){
        vShowTaskList();
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}

// ........................................................................................................
/**
 * @brief   FreeRTOS main function
 *
 * This function sets up and starts the FreeRTOS tasks, including the LVGL task and another demo task.
 *
 * @param   None
 * @return  None
 */


extern "C" void freertos_main()
{
    EventSystem::init();
    EventSystem::subscribe(&fms);

    StateMachine::registerState<OffState>(StatesID::off_state);
    StateMachine::registerState<MainState>(StatesID::main_onstate);
    StateMachine::registerState<TempState>(StatesID::temp_onstate);
    StateMachine::registerState<TempConfirmState>(StatesID::confirm_temp_onstate);
    StateMachine::registerState<FanState>(StatesID::fan_onstate);
    StateMachine::registerState<FanConfirmState>(StatesID::confirm_fan_onstate);
    StateMachine::registerState<MenuState>(StatesID::menu);
    StateMachine::registerState<ClockState>(StatesID::clock_state);
    StateMachine::registerState<TimerState>(StatesID::timer_state);
    StateMachine::registerState<TimerParametrsState>(StatesID::timer_patametr_state);
    StateMachine::registerState<MenuState>(StatesID::main_with_timer_state);
    StateMachine::registerState<MenuState>(StatesID::tool_state);
    StateMachine::registerState<ConfigurationState>(StatesID::configuration_state);
    StateMachine::registerState<GrafikState>(StatesID::grafik_state);
    StateMachine::registerState<MenuState>(StatesID::dispetcher_state);
    StateMachine::registerState<MenuState>(StatesID::themes_state);
    StateMachine::registerState<MenuState>(StatesID::visual_state);

    /* Create the LVGL task */
    if (xTaskCreate(lvgl_task, "LVGL Task", 8192, nullptr, 3, nullptr) != pdPASS) {
        printf("Error creating LVGL task\n");
        /* Error handling */
    }

    /* Create another task */
    // if (xTaskCreate(another_task, "Another Task", 8192, nullptr, 3, nullptr) != pdPASS) {
    //     printf("Error creating another task\n");
    //     /* Error handling */
    // }

    /* Start the scheduler */
    vTaskStartScheduler();
}

lv_display_t * hal_init(int32_t w, int32_t h)
{
    lv_group_set_default(lv_group_create());

    lv_display_t * disp = lv_sdl_window_create(w, h);

    lv_indev_t * mouse = lv_sdl_mouse_create();
    lv_indev_set_group(mouse, lv_group_get_default());
    lv_indev_set_display(mouse, disp);
    lv_display_set_default(disp);

    LV_IMAGE_DECLARE(mouse_cursor_icon); /*Declare the image file.*/
    lv_obj_t * cursor_obj;
    cursor_obj = lv_image_create(lv_screen_active()); /*Create an image object for the cursor */
    lv_image_set_src(cursor_obj, &mouse_cursor_icon);           /*Set the image source*/
    lv_indev_set_cursor(mouse, cursor_obj);             /*Connect the image  object to the driver*/

    lv_indev_t * mousewheel = lv_sdl_mousewheel_create();
    lv_indev_set_display(mousewheel, disp);
    lv_indev_set_group(mousewheel, lv_group_get_default());

    lv_indev_t * kb = lv_sdl_keyboard_create();
    lv_indev_set_display(kb, disp);
    lv_indev_set_group(kb, lv_group_get_default());

    return disp;
}

#endif
