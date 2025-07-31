#ifndef EEZ_LVGL_UI_SCREENS_H
#define EEZ_LVGL_UI_SCREENS_H

#include <lvgl/lvgl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _objects_t {
    lv_obj_t *blank;
    lv_obj_t *main;
    lv_obj_t *second;
    lv_obj_t *button1;
    lv_obj_t *button2;
    lv_obj_t *button4;
    lv_obj_t *button3;
    lv_obj_t *random1;
    lv_obj_t *random2;
    lv_obj_t *random3;
    lv_obj_t *arc;
    lv_obj_t *button5;
    lv_obj_t *arc_val;
    lv_obj_t *odd_even;
} objects_t;

extern objects_t objects;

enum ScreensEnum {
    SCREEN_ID_BLANK = 1,
    SCREEN_ID_MAIN = 2,
    SCREEN_ID_SECOND = 3,
};

void create_screen_blank();
void delete_screen_blank();
void tick_screen_blank();

void create_screen_main();
void delete_screen_main();
void tick_screen_main();

void create_screen_second();
void delete_screen_second();
void tick_screen_second();

void create_screen_by_id(enum ScreensEnum screenId);
void delete_screen_by_id(enum ScreensEnum screenId);
void tick_screen_by_id(enum ScreensEnum screenId);
void tick_screen(int screen_index);

void create_screens();


#ifdef __cplusplus
}
#endif

#endif /*EEZ_LVGL_UI_SCREENS_H*/