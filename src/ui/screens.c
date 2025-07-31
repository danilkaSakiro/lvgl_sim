#include <string.h>

#include "screens.h"
#include "images.h"
#include "fonts.h"
#include "actions.h"
#include "vars.h"
#include "styles.h"
#include "ui.h"

#include <string.h>

objects_t objects;
lv_obj_t *tick_value_change_obj;
uint32_t active_theme_index = 0;

void create_screen_blank() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.blank = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    
    tick_screen_blank();
}

void delete_screen_blank() {
    lv_obj_delete(objects.blank);
    objects.blank = 0;
}

void tick_screen_blank() {
}

void create_screen_main() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.main = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)2);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)2);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 196, 232);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Hello, world!");
        }
        {
            // Button1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button1 = obj;
            lv_obj_set_pos(obj, 66, 34);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button1_action, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "random1");
                }
            }
        }
        {
            // Button2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button2 = obj;
            lv_obj_set_pos(obj, 306, 34);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button2_action, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "random2");
                }
            }
        }
        {
            // Button4
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button4 = obj;
            lv_obj_set_pos(obj, 306, 385);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button4_action, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "second_scr");
                }
            }
        }
        {
            // Button3
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button3 = obj;
            lv_obj_set_pos(obj, 66, 385);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button3_action, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "random3");
                }
            }
        }
        {
            // random1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.random1 = obj;
            lv_obj_set_pos(obj, 112, 98);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // random2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.random2 = obj;
            lv_obj_set_pos(obj, 353, 99);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // random3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.random3 = obj;
            lv_obj_set_pos(obj, 109, 358);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
    }
    
    tick_screen_main();
}

void delete_screen_main() {
    lv_obj_delete(objects.main);
    objects.main = 0;
    objects.button1 = 0;
    objects.button2 = 0;
    objects.button4 = 0;
    objects.button3 = 0;
    objects.random1 = 0;
    objects.random2 = 0;
    objects.random3 = 0;
}

void tick_screen_main() {
}

void create_screen_second() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.second = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)3);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)3);
    {
        lv_obj_t *parent_obj = obj;
        {
            // arc
            lv_obj_t *obj = lv_arc_create(parent_obj);
            objects.arc = obj;
            lv_obj_set_pos(obj, 44, 55);
            lv_obj_set_size(obj, 392, 371);
            lv_arc_set_value(obj, 25);
            lv_obj_add_event_cb(obj, action_arc_value, LV_EVENT_VALUE_CHANGED, (void *)0);
        }
        {
            // button5
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button5 = obj;
            lv_obj_set_pos(obj, 178, 240);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button5_action, LV_EVENT_PRESSED, (void *)0);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "main_scr");
                }
            }
        }
        {
            // arc_val
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.arc_val = obj;
            lv_obj_set_pos(obj, 219, 137);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
        {
            // odd_even
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.odd_even = obj;
            lv_obj_set_pos(obj, 219, 182);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "0");
        }
    }
    
    tick_screen_second();
}

void delete_screen_second() {
    lv_obj_delete(objects.second);
    objects.second = 0;
    objects.arc = 0;
    objects.button5 = 0;
    objects.arc_val = 0;
    objects.odd_even = 0;
}

void tick_screen_second() {
}



typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_blank,
    create_screen_main,
    create_screen_second,
};
void create_screen(int screen_index) {
    create_screen_funcs[screen_index]();
}
void create_screen_by_id(enum ScreensEnum screenId) {
    create_screen_funcs[screenId - 1]();
}

typedef void (*delete_screen_func_t)();
delete_screen_func_t delete_screen_funcs[] = {
    delete_screen_blank,
    delete_screen_main,
    delete_screen_second,
};
void delete_screen(int screen_index) {
    delete_screen_funcs[screen_index]();
}
void delete_screen_by_id(enum ScreensEnum screenId) {
    delete_screen_funcs[screenId - 1]();
}

typedef void (*tick_screen_func_t)();
tick_screen_func_t tick_screen_funcs[] = {
    tick_screen_blank,
    tick_screen_main,
    tick_screen_second,
};
void tick_screen(int screen_index) {
    tick_screen_funcs[screen_index]();
}
void tick_screen_by_id(enum ScreensEnum screenId) {
    tick_screen_funcs[screenId - 1]();
}

void create_screens() {
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    
    create_screen_blank();
}
