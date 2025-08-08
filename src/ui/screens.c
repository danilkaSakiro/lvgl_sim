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

void create_screen_off_state() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.off_state = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)2);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)2);
    lv_obj_add_event_cb(obj, action_power_on, LV_EVENT_PRESSED, (void *)2);
    
    tick_screen_off_state();
}

void delete_screen_off_state() {
    lv_obj_delete(objects.off_state);
    objects.off_state = 0;
}

void tick_screen_off_state() {
}

void create_screen_on_state_mainscreen() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_mainscreen = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)3);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)3);
    {
        lv_obj_t *parent_obj = obj;
        {
            // real_temperature_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temperature_value = obj;
            lv_obj_set_pos(obj, 320, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.7 ");
        }
        {
            // button_tool
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_tool = obj;
            lv_obj_set_pos(obj, 376, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_menu, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_tools, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_power
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_power = obj;
            lv_obj_set_pos(obj, 37, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_power_off, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_power, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_temp = obj;
            lv_obj_set_pos(obj, 191, 176);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25.0");
        }
        {
            // Time_main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_main = obj;
            lv_obj_set_pos(obj, 29, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 259, 60);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_tree);
        }
        {
            // button_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_temp = obj;
            lv_obj_set_pos(obj, 150, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_set_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_temp, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_fan = obj;
            lv_obj_set_pos(obj, 263, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_set_fan_mode, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_fan, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 7, 350);
            lv_obj_set_size(obj, 473, 1);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 465, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 83, 131);
            lv_obj_set_size(obj, 321, 46);
            static lv_point_precise_t line_points[] = {
                { 0, 50 },
                { 150, 0 },
                { 300, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 282, 164);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 357, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "°C");
        }
        {
            // button_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_timer = obj;
            lv_obj_set_pos(obj, 376, 31);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_timer, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Humadity
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.humadity = obj;
            lv_obj_set_pos(obj, 107, 240);
            lv_obj_set_size(obj, 70, 70);
            lv_image_set_src(obj, &img_humadity);
        }
        {
            // Get_humadity
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_humadity = obj;
            lv_obj_set_pos(obj, 113, 306);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "10 %");
        }
        {
            // Get_CO2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_co2 = obj;
            lv_obj_set_pos(obj, 192, 306);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "600 ppm");
        }
        {
            // CO2
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.co2 = obj;
            lv_obj_set_pos(obj, 210, 240);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_co2);
        }
        {
            // PM2.5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pm2_5 = obj;
            lv_obj_set_pos(obj, 313, 260);
            lv_obj_set_size(obj, 73, 42);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "PM2.5");
        }
        {
            // Get_pm25
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_pm25 = obj;
            lv_obj_set_pos(obj, 307, 306);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12 mkg/m3");
        }
    }
    
    tick_screen_on_state_mainscreen();
}

void delete_screen_on_state_mainscreen() {
    lv_obj_delete(objects.on_state_mainscreen);
    objects.on_state_mainscreen = 0;
    objects.real_temperature_value = 0;
    objects.button_tool = 0;
    objects.button_power = 0;
    objects.main_temp = 0;
    objects.time_main = 0;
    objects.button_temp = 0;
    objects.button_fan = 0;
    objects.button_timer = 0;
    objects.humadity = 0;
    objects.get_humadity = 0;
    objects.get_co2 = 0;
    objects.co2 = 0;
    objects.pm2_5 = 0;
    objects.get_pm25 = 0;
}

void tick_screen_on_state_mainscreen() {
}

void create_screen_on_state_change_temp() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_change_temp = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)4);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)4);
    {
        lv_obj_t *parent_obj = obj;
        {
            // back_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.back_temp = obj;
            lv_obj_set_pos(obj, 37, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_go_mainscreen, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_back, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // set_temperature_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temperature_value = obj;
            lv_obj_set_pos(obj, 136, 235);
            lv_obj_set_size(obj, 98, 52);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Time_main_1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_main_1 = obj;
            lv_obj_set_pos(obj, 29, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            // inc_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.inc_temp = obj;
            lv_obj_set_pos(obj, 150, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_inc_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_up, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // dec_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.dec_temp = obj;
            lv_obj_set_pos(obj, 263, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_dec_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_down, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 7, 350);
            lv_obj_set_size(obj, 473, 1);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 465, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 195, 237);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_22, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 136, 206);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Set:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 278, 235);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // real_temp_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temp_value = obj;
            lv_obj_set_pos(obj, 278, 254);
            lv_obj_set_size(obj, 59, 33);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23.6");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 333, 245);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            // button_conf_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_conf_temp = obj;
            lv_obj_set_pos(obj, 376, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_confirm, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 171, 174);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "OK");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 83, 131);
            lv_obj_set_size(obj, 321, 46);
            static lv_point_precise_t line_points[] = {
                { 0, 50 },
                { 150, 0 },
                { 300, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_on_state_change_temp();
}

void delete_screen_on_state_change_temp() {
    lv_obj_delete(objects.on_state_change_temp);
    objects.on_state_change_temp = 0;
    objects.back_temp = 0;
    objects.set_temperature_value = 0;
    objects.time_main_1 = 0;
    objects.inc_temp = 0;
    objects.dec_temp = 0;
    objects.real_temp_value = 0;
    objects.button_conf_temp = 0;
    objects.obj0 = 0;
}

void tick_screen_on_state_change_temp() {
}

void create_screen_on_state_change_rpm() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_change_rpm = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)5);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)5);
    {
        lv_obj_t *parent_obj = obj;
        {
            // back_rpm
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.back_rpm = obj;
            lv_obj_set_pos(obj, 37, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_go_mainscreen, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_fan, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // set_rpm_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_rpm_value = obj;
            lv_obj_set_pos(obj, 158, 235);
            lv_obj_set_size(obj, 27, 52);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Time_main_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_main_2 = obj;
            lv_obj_set_pos(obj, 29, 41);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            // inc_rpm
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.inc_rpm = obj;
            lv_obj_set_pos(obj, 150, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_inc_rpm, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_up, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // dec_rpm
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.dec_rpm = obj;
            lv_obj_set_pos(obj, 263, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_dec_rpm, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_down, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 7, 350);
            lv_obj_set_size(obj, 473, 1);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 465, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 142, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Set:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 278, 235);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // real_rpm_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_rpm_value = obj;
            lv_obj_set_pos(obj, 286, 254);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "2");
        }
        {
            // button_conf_rpm
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_conf_rpm = obj;
            lv_obj_set_pos(obj, 376, 379);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_confirm, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.obj1 = obj;
            lv_obj_set_pos(obj, 171, 174);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "OK");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 83, 131);
            lv_obj_set_size(obj, 321, 46);
            static lv_point_precise_t line_points[] = {
                { 0, 50 },
                { 150, 0 },
                { 300, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 3, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_on_state_change_rpm();
}

void delete_screen_on_state_change_rpm() {
    lv_obj_delete(objects.on_state_change_rpm);
    objects.on_state_change_rpm = 0;
    objects.back_rpm = 0;
    objects.set_rpm_value = 0;
    objects.time_main_2 = 0;
    objects.inc_rpm = 0;
    objects.dec_rpm = 0;
    objects.real_rpm_value = 0;
    objects.button_conf_rpm = 0;
    objects.obj1 = 0;
}

void tick_screen_on_state_change_rpm() {
}

void create_screen_tools() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.tools = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)6);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)6);
    {
        lv_obj_t *parent_obj = obj;
        {
            // WiFi_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.wi_fi_settings = obj;
            lv_obj_set_pos(obj, 76, 87);
            lv_obj_set_size(obj, 70, 70);
            lv_obj_add_event_cb(obj, action_wi_fi_action, LV_EVENT_PRESSED, (void *)0);
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
            lv_obj_add_event_cb(obj, action_brightness_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_brightness, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
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
            lv_obj_add_event_cb(obj, action_sound_action, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_sound, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj3 = obj;
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
            lv_obj_add_event_cb(obj, action_lang_action, LV_EVENT_PRESSED, (void *)0);
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
            lv_obj_add_event_cb(obj, action_window_action, LV_EVENT_PRESSED, (void *)0);
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
            lv_obj_add_event_cb(obj, action_aboba_action, LV_EVENT_PRESSED, (void *)0);
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
            // button_back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_back = obj;
            lv_obj_set_pos(obj, 193, 364);
            lv_obj_set_size(obj, 100, 50);
            lv_obj_add_event_cb(obj, action_menu_out, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
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
    objects.obj2 = 0;
    objects.sound_settings = 0;
    objects.obj3 = 0;
    objects.language_settings = 0;
    objects.language = 0;
    objects.window_settings = 0;
    objects.window = 0;
    objects.aboba_settings = 0;
    objects.aboba = 0;
    objects.button_back = 0;
    objects.obj4 = 0;
}

void tick_screen_tools() {
}

void create_screen_clock_settings() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.clock_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)7);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)7);
    
    tick_screen_clock_settings();
}

void delete_screen_clock_settings() {
    lv_obj_delete(objects.clock_settings);
    objects.clock_settings = 0;
}

void tick_screen_clock_settings() {
}

void create_screen_timer_settings() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.timer_settings = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)8);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)8);
    
    tick_screen_timer_settings();
}

void delete_screen_timer_settings() {
    lv_obj_delete(objects.timer_settings);
    objects.timer_settings = 0;
}

void tick_screen_timer_settings() {
}

void create_screen_sound_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.sound_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)9);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)9);
    
    tick_screen_sound_menu();
}

void delete_screen_sound_menu() {
    lv_obj_delete(objects.sound_menu);
    objects.sound_menu = 0;
}

void tick_screen_sound_menu() {
}

void create_screen_language_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.language_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)10);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)10);
    
    tick_screen_language_menu();
}

void delete_screen_language_menu() {
    lv_obj_delete(objects.language_menu);
    objects.language_menu = 0;
}

void tick_screen_language_menu() {
}

void create_screen_window_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.window_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)11);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)11);
    
    tick_screen_window_menu();
}

void delete_screen_window_menu() {
    lv_obj_delete(objects.window_menu);
    objects.window_menu = 0;
}

void tick_screen_window_menu() {
}

void create_screen_aboba_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.aboba_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 480, 480);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)12);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)12);
    
    tick_screen_aboba_menu();
}

void delete_screen_aboba_menu() {
    lv_obj_delete(objects.aboba_menu);
    objects.aboba_menu = 0;
}

void tick_screen_aboba_menu() {
}



typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_blank,
    create_screen_off_state,
    create_screen_on_state_mainscreen,
    create_screen_on_state_change_temp,
    create_screen_on_state_change_rpm,
    create_screen_tools,
    create_screen_clock_settings,
    create_screen_timer_settings,
    create_screen_sound_menu,
    create_screen_language_menu,
    create_screen_window_menu,
    create_screen_aboba_menu,
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
    delete_screen_off_state,
    delete_screen_on_state_mainscreen,
    delete_screen_on_state_change_temp,
    delete_screen_on_state_change_rpm,
    delete_screen_tools,
    delete_screen_clock_settings,
    delete_screen_timer_settings,
    delete_screen_sound_menu,
    delete_screen_language_menu,
    delete_screen_window_menu,
    delete_screen_aboba_menu,
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
    tick_screen_off_state,
    tick_screen_on_state_mainscreen,
    tick_screen_on_state_change_temp,
    tick_screen_on_state_change_rpm,
    tick_screen_tools,
    tick_screen_clock_settings,
    tick_screen_timer_settings,
    tick_screen_sound_menu,
    tick_screen_language_menu,
    tick_screen_window_menu,
    tick_screen_aboba_menu,
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
