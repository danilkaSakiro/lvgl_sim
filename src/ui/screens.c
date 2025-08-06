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
            // Set_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temp = obj;
            lv_obj_set_pos(obj, 87, 126);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Set:");
        }
        {
            // real_temperature
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temperature = obj;
            lv_obj_set_pos(obj, 315, 187);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.7 °C");
        }
        {
            // Button1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button1 = obj;
            lv_obj_set_pos(obj, 331, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_button1_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj0 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-3");
                }
            }
        }
        {
            // Button2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button2 = obj;
            lv_obj_set_pos(obj, 407, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_button2_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+3");
                }
            }
        }
        {
            // tool
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.tool = obj;
            lv_obj_set_pos(obj, 36, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_tools_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_tools40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // fanTools
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.fan_tools = obj;
            lv_obj_set_pos(obj, 104, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_fan_tool_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_fan_tool, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj2 = obj;
            lv_obj_set_pos(obj, 252, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_button3_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_state, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // set_temperature
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temperature = obj;
            lv_obj_set_pos(obj, 90, 168);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.0 °C ");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj3 = obj;
            lv_obj_set_pos(obj, 0, 433);
            lv_obj_set_size(obj, 480, 47);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff868686), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Tim
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.tim = obj;
            lv_obj_set_pos(obj, 8, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Timer:");
        }
        {
            // Start_Timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.start_timer = obj;
            lv_obj_set_pos(obj, 157, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "13:48");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 109, 436);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_clock);
        }
        {
            // Mod
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mod = obj;
            lv_obj_set_pos(obj, 234, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "MODE");
        }
        {
            // Real_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temp = obj;
            lv_obj_set_pos(obj, 315, 166);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // Conf
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.conf = obj;
            lv_obj_set_pos(obj, 176, 363);
            lv_obj_set_size(obj, 50, 50);
            // lv_obj_add_event_cb(obj, action_confirm_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // Set_temp_from_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temp_from_timer = obj;
            lv_obj_set_pos(obj, 331, 442);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.7 °C");
        }
        {
            // Fan_mode_from_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fan_mode_from_timer = obj;
            lv_obj_set_pos(obj, 434, 442);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FAN\nMODE");
        }
        {
            // Time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time = obj;
            lv_obj_set_pos(obj, 363, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
    }
    
    tick_screen_main();
}

void delete_screen_main() {
    lv_obj_delete(objects.main);
    objects.main = 0;
    objects.set_temp = 0;
    objects.real_temperature = 0;
    objects.button1 = 0;
    objects.obj0 = 0;
    objects.button2 = 0;
    objects.obj1 = 0;
    objects.tool = 0;
    objects.fan_tools = 0;
    objects.obj2 = 0;
    objects.set_temperature = 0;
    objects.obj3 = 0;
    objects.tim = 0;
    objects.start_timer = 0;
    objects.mod = 0;
    objects.real_temp = 0;
    objects.conf = 0;
    objects.obj4 = 0;
    objects.set_temp_from_timer = 0;
    objects.fan_mode_from_timer = 0;
    objects.time = 0;
}

void tick_screen_main() {
}

void create_screen_second() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.second = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)2);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)2);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Set_temp_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temp_1 = obj;
            lv_obj_set_pos(obj, 99, 80);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Set:");
        }
        {
            // temperature_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temperature_1 = obj;
            lv_obj_set_pos(obj, 309, 135);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.7 °C");
        }
        {
            // Button1_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button1_1 = obj;
            lv_obj_set_pos(obj, 331, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_button1_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "-3");
                }
            }
        }
        {
            // Button2_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button2_1 = obj;
            lv_obj_set_pos(obj, 407, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_button2_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "+3");
                }
            }
        }
        {
            // tool_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.tool_1 = obj;
            lv_obj_set_pos(obj, 36, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_tools_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_tools40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // fanTools_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.fan_tools_1 = obj;
            lv_obj_set_pos(obj, 104, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_add_event_cb(obj, action_fan_tool_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_fan_tool, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj7 = obj;
            lv_obj_set_pos(obj, 252, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_state, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 99, 128);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23.0 °C ");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj8 = obj;
            lv_obj_set_pos(obj, 0, 433);
            lv_obj_set_size(obj, 480, 47);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff868686), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(obj, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Tim_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.tim_1 = obj;
            lv_obj_set_pos(obj, 8, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Timer:");
        }
        {
            // Time_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_1 = obj;
            lv_obj_set_pos(obj, 157, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "13:48");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 109, 436);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_clock);
        }
        {
            // Mod_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.mod_1 = obj;
            lv_obj_set_pos(obj, 234, 441);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "MODE");
        }
        {
            // Real_temp_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temp_1 = obj;
            lv_obj_set_pos(obj, 309, 107);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // Conf_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.conf_1 = obj;
            lv_obj_set_pos(obj, 176, 363);
            lv_obj_set_size(obj, 50, 50);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj9 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // Set_temp_from_timer_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temp_from_timer_1 = obj;
            lv_obj_set_pos(obj, 331, 442);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.7 °C");
        }
        {
            // Fan_mode_from_timer_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fan_mode_from_timer_1 = obj;
            lv_obj_set_pos(obj, 434, 442);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "FAN\nMODE");
        }
    }
    
    tick_screen_second();
}

void delete_screen_second() {
    lv_obj_delete(objects.second);
    objects.second = 0;
    objects.set_temp_1 = 0;
    objects.temperature_1 = 0;
    objects.button1_1 = 0;
    objects.obj5 = 0;
    objects.button2_1 = 0;
    objects.obj6 = 0;
    objects.tool_1 = 0;
    objects.fan_tools_1 = 0;
    objects.obj7 = 0;
    objects.obj8 = 0;
    objects.tim_1 = 0;
    objects.time_1 = 0;
    objects.mod_1 = 0;
    objects.real_temp_1 = 0;
    objects.conf_1 = 0;
    objects.obj9 = 0;
    objects.set_temp_from_timer_1 = 0;
    objects.fan_mode_from_timer_1 = 0;
}

void tick_screen_second() {
}

void create_screen_tools() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.tools = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)4);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)4);
    {
        lv_obj_t *parent_obj = obj;
        {
            // WiFi_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.wi_fi_settings = obj;
            lv_obj_set_pos(obj, 76, 87);
            lv_obj_set_size(obj, 70, 70);
            // lv_obj_add_event_cb(obj, action_wi_fi_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_wi_fi, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // WI-FI
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.wi_fi = obj;
                    lv_obj_set_pos(obj, 0, 52);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffdd0c0c), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "WI-FI");
                }
            }
        }
        {
            // Brightness_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.brightness_settings = obj;
            lv_obj_set_pos(obj, 205, 87);
            lv_obj_set_size(obj, 70, 70);
            // lv_obj_add_event_cb(obj, action_brightness_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_brightness, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj10 = obj;
                    lv_obj_set_pos(obj, 0, 35);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffbf1717), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Btightness");
                }
            }
        }
        {
            // Sound_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.sound_settings = obj;
            lv_obj_set_pos(obj, 345, 87);
            lv_obj_set_size(obj, 70, 70);
            // lv_obj_add_event_cb(obj, action_sound_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_sound, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj11 = obj;
                    lv_obj_set_pos(obj, 1, 35);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Sound");
                }
            }
        }
        {
            // Language_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.language_settings = obj;
            lv_obj_set_pos(obj, 76, 206);
            lv_obj_set_size(obj, 70, 70);
            // lv_obj_add_event_cb(obj, action_lang_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_language, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // language
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.language = obj;
                    lv_obj_set_pos(obj, -11, 53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffc70000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Language");
                }
            }
        }
        {
            // Window_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.window_settings = obj;
            lv_obj_set_pos(obj, 208, 207);
            lv_obj_set_size(obj, 70, 70);
            // lv_obj_add_event_cb(obj, action_window_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_window, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Window
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.window = obj;
                    lv_obj_set_pos(obj, -5, 52);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Window");
                }
            }
        }
        {
            // ABOBA_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.aboba_settings = obj;
            lv_obj_set_pos(obj, 346, 206);
            lv_obj_set_size(obj, 70, 70);
            // lv_obj_add_event_cb(obj, action_aboba_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // Aboba
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.aboba = obj;
                    lv_obj_set_pos(obj, 6, 19);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "KTO?");
                }
            }
        }
        {
            // button5_1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button5_1 = obj;
            lv_obj_set_pos(obj, 193, 364);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_button5_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj12 = obj;
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "main_scr");
                }
            }
        }
    }
    
    tick_screen_tools();
}

void delete_screen_tools() {
    lv_obj_delete(objects.tools);
    objects.tools = 0;
    objects.wi_fi_settings = 0;
    objects.wi_fi = 0;
    objects.brightness_settings = 0;
    objects.obj10 = 0;
    objects.sound_settings = 0;
    objects.obj11 = 0;
    objects.language_settings = 0;
    objects.language = 0;
    objects.window_settings = 0;
    objects.window = 0;
    objects.aboba_settings = 0;
    objects.aboba = 0;
    objects.button5_1 = 0;
    objects.obj12 = 0;
}

void tick_screen_tools() {
}

void create_screen_wi_fi_setting() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.wi_fi_setting = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    
    tick_screen_wi_fi_setting();
}

void delete_screen_wi_fi_setting() {
    lv_obj_delete(objects.wi_fi_setting);
    objects.wi_fi_setting = 0;
}

void tick_screen_wi_fi_setting() {
}



typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_blank,
    create_screen_main,
    create_screen_second,
    create_screen_tools,
    create_screen_wi_fi_setting,
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
    delete_screen_tools,
    delete_screen_wi_fi_setting,
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
    tick_screen_tools,
    tick_screen_wi_fi_setting,
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
    create_screen_wi_fi_setting();
}
