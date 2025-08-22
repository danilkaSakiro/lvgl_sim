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
    lv_obj_set_size(obj, 1024, 600);
    
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
    lv_obj_set_size(obj, 1024, 600);
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
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)3);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)3);
    {
        lv_obj_t *parent_obj = obj;
        {
            // button_tool
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_tool = obj;
            lv_obj_set_pos(obj, 801, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_go_to_menu, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_tool, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_power
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_power = obj;
            lv_obj_set_pos(obj, 107, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_power_off, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_power, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_temp = obj;
            lv_obj_set_pos(obj, 487, 164);
            lv_obj_set_size(obj, 75, 55);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Time_main
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_main = obj;
            lv_obj_set_pos(obj, 142, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 665, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_tree);
        }
        {
            // button_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_temp = obj;
            lv_obj_set_pos(obj, 337, 442);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_set_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_temp, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_fan = obj;
            lv_obj_set_pos(obj, 569, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_set_fan_mode, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_fan, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Humadity
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.humadity = obj;
            lv_obj_set_pos(obj, 350, 303);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_humadity);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Get_humadity
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_humadity = obj;
            lv_obj_set_pos(obj, 342, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "10 %");
        }
        {
            // Get_CO2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_co2 = obj;
            lv_obj_set_pos(obj, 452, 385);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "600 ppm");
        }
        {
            // PM2.5
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pm2_5 = obj;
            lv_obj_set_pos(obj, 637, 319);
            lv_obj_set_size(obj, 118, 42);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "PM2.5");
        }
        {
            // Get_pm25
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_pm25 = obj;
            lv_obj_set_pos(obj, 634, 385);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12 mkg/m3");
        }
        {
            // Get_visual
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_visual = obj;
            lv_obj_set_pos(obj, 132, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "20 %");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 549, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 286, 107);
            lv_obj_set_size(obj, 506, 57);
            static lv_point_precise_t line_points[] = {
                { 1, 50 },
                { 251, 0 },
                { 501, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 141, 257);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_visual);
            lv_image_set_scale(obj, 200);
        }
        {
            // CO2
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.co2 = obj;
            lv_obj_set_pos(obj, 480, 319);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_co2);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main_real_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_real_temp = obj;
            lv_obj_set_pos(obj, 731, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 775, 52);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            // Timer
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.timer = obj;
            lv_obj_set_pos(obj, 849, 45);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_timer_menu);
        }
    }
    
    tick_screen_on_state_mainscreen();
}

void delete_screen_on_state_mainscreen() {
    lv_obj_delete(objects.on_state_mainscreen);
    objects.on_state_mainscreen = 0;
    objects.button_tool = 0;
    objects.button_power = 0;
    objects.main_temp = 0;
    objects.time_main = 0;
    objects.button_temp = 0;
    objects.button_fan = 0;
    objects.humadity = 0;
    objects.get_humadity = 0;
    objects.get_co2 = 0;
    objects.pm2_5 = 0;
    objects.get_pm25 = 0;
    objects.get_visual = 0;
    objects.co2 = 0;
    objects.main_real_temp = 0;
    objects.timer = 0;
}

void tick_screen_on_state_mainscreen() {
}

void create_screen_on_state_change_temp() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_change_temp = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)4);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)4);
    lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            // back_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.back_temp = obj;
            lv_obj_set_pos(obj, 107, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_back_to_mainscreen_from_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_add_state(obj, LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_backtemp, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // set_temperature_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_temperature_value = obj;
            lv_obj_set_pos(obj, 368, 285);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_align(obj, LV_TEXT_ALIGN_AUTO, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Time_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_temp = obj;
            lv_obj_set_pos(obj, 142, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            // inc_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.inc_temp = obj;
            lv_obj_set_pos(obj, 336, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_inc_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_inc, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // dec_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.dec_temp = obj;
            lv_obj_set_pos(obj, 585, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_dec_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_dec, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 417, 262);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 351, 198);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Set:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 598, 204);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // real_temp_value
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temp_value = obj;
            lv_obj_set_pos(obj, 616, 285);
            lv_obj_set_size(obj, 59, 48);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 657, 264);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_32, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 286, 107);
            lv_obj_set_size(obj, 506, 57);
            static lv_point_precise_t line_points[] = {
                { 1, 50 },
                { 251, 0 },
                { 501, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_conf_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_conf_temp = obj;
            lv_obj_set_pos(obj, 807, 464);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_confirm_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
    }
    
    tick_screen_on_state_change_temp();
}

void delete_screen_on_state_change_temp() {
    lv_obj_delete(objects.on_state_change_temp);
    objects.on_state_change_temp = 0;
    objects.back_temp = 0;
    objects.set_temperature_value = 0;
    objects.time_temp = 0;
    objects.inc_temp = 0;
    objects.dec_temp = 0;
    objects.real_temp_value = 0;
    objects.button_conf_temp = 0;
}

void tick_screen_on_state_change_temp() {
}

void create_screen_on_state_confirm_temp() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_confirm_temp = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)5);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)5);
    lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_cancel_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_cancel_temp = obj;
            lv_obj_set_pos(obj, 680, 456);
            lv_obj_set_size(obj, 260, 120);
            lv_obj_add_event_cb(obj, action_cancel_temperature_change, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "CANCEL");
                }
            }
        }
        {
            // nochange_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.nochange_temp = obj;
            lv_obj_set_pos(obj, 340, 456);
            lv_obj_set_size(obj, 200, 120);
            lv_obj_add_event_cb(obj, action_nochange_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NO");
                }
            }
        }
        {
            // change_temp
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.change_temp = obj;
            lv_obj_set_pos(obj, 80, 456);
            lv_obj_set_size(obj, 200, 120);
            lv_obj_add_event_cb(obj, action_change_temp, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "YES");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 285, 215);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SAVED CHANGES?");
        }
    }
    
    tick_screen_on_state_confirm_temp();
}

void delete_screen_on_state_confirm_temp() {
    lv_obj_delete(objects.on_state_confirm_temp);
    objects.on_state_confirm_temp = 0;
    objects.button_cancel_temp = 0;
    objects.nochange_temp = 0;
    objects.change_temp = 0;
}

void tick_screen_on_state_confirm_temp() {
}

void create_screen_on_state_change_fan() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_change_fan = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)6);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)6);
    {
        lv_obj_t *parent_obj = obj;
        {
            // back_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.back_fan = obj;
            lv_obj_set_pos(obj, 82, 469);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_back_to_mainscreen_from_fan, LV_EVENT_PRESSED, (void *)0);
            lv_obj_add_state(obj, LV_STATE_PRESSED);
            lv_obj_set_style_bg_image_src(obj, &img_backfan, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // set_fan_mode
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.set_fan_mode = obj;
            lv_obj_set_pos(obj, 623, 280);
            lv_obj_set_size(obj, 26, 52);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "");
        }
        {
            // Time_main_2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_main_2 = obj;
            lv_obj_set_pos(obj, 142, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            // inc_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.inc_fan = obj;
            lv_obj_set_pos(obj, 322, 469);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_inc_fan, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_inc, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // dec_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.dec_fan = obj;
            lv_obj_set_pos(obj, 589, 469);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_dec_fan, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_dec, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj0 = obj;
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xfffafafa), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 591, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Set:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 322, 199);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // real_fan_mode
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_fan_mode = obj;
            lv_obj_set_pos(obj, 367, 280);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "2");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 259, 107);
            lv_obj_set_size(obj, 506, 57);
            static lv_point_precise_t line_points[] = {
                { 1, 50 },
                { 251, 0 },
                { 501, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_align(obj, LV_ALIGN_DEFAULT, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Real_fan
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.real_fan = obj;
            lv_obj_set_pos(obj, 765, 178);
            lv_obj_set_size(obj, 215, 240);
            lv_scale_set_mode(obj, LV_SCALE_MODE_VERTICAL_LEFT);
            lv_scale_set_range(obj, 0, 9);
            lv_scale_set_total_tick_count(obj, 25);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, false);
            lv_obj_add_event_cb(obj, action_set_fan_mode, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_length(obj, 120, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff51cad5), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 210, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff51cad5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Set_fan
            lv_obj_t *obj = lv_scale_create(parent_obj);
            objects.set_fan = obj;
            lv_obj_set_pos(obj, 34, 178);
            lv_obj_set_size(obj, 215, 240);
            lv_scale_set_mode(obj, LV_SCALE_MODE_VERTICAL_RIGHT);
            lv_scale_set_range(obj, 0, 9);
            lv_scale_set_total_tick_count(obj, 25);
            lv_scale_set_major_tick_every(obj, 5);
            lv_scale_set_label_show(obj, false);
            // lv_obj_add_event_cb(obj, action_get_fan_mode, LV_EVENT_VALUE_CHANGED, (void *)0);
            lv_obj_set_style_length(obj, 120, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff51cad5), LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 4, LV_PART_ITEMS | LV_STATE_DEFAULT);
            lv_obj_set_style_length(obj, 210, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff51cad5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_width(obj, 4, LV_PART_INDICATOR | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_conf_rpm
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_conf_rpm = obj;
            lv_obj_set_pos(obj, 799, 469);
            lv_obj_set_size(obj, 120, 120);
            lv_obj_add_event_cb(obj, action_confirm_fan, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
    }
    
    tick_screen_on_state_change_fan();
}

void delete_screen_on_state_change_fan() {
    lv_obj_delete(objects.on_state_change_fan);
    objects.on_state_change_fan = 0;
    objects.back_fan = 0;
    objects.set_fan_mode = 0;
    objects.time_main_2 = 0;
    objects.inc_fan = 0;
    objects.dec_fan = 0;
    objects.obj0 = 0;
    objects.real_fan_mode = 0;
    objects.real_fan = 0;
    objects.set_fan = 0;
    objects.button_conf_rpm = 0;
}

void tick_screen_on_state_change_fan() {
}

void create_screen_on_state_confirm_fan() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_confirm_fan = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)7);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)7);
    lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_cancel_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_cancel_fan = obj;
            lv_obj_set_pos(obj, 680, 456);
            lv_obj_set_size(obj, 260, 120);
            lv_obj_add_event_cb(obj, action_cancel_fan_change, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "CANCEL");
                }
            }
        }
        {
            // nochange_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.nochange_fan = obj;
            lv_obj_set_pos(obj, 340, 456);
            lv_obj_set_size(obj, 200, 120);
            lv_obj_add_event_cb(obj, action_nochange_fan, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NO");
                }
            }
        }
        {
            // change_fan
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.change_fan = obj;
            lv_obj_set_pos(obj, 80, 456);
            lv_obj_set_size(obj, 200, 120);
            lv_obj_add_event_cb(obj, action_change_fan, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "YES");
                }
            }
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 285, 215);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "SAVED CHANGES?");
        }
    }
    
    tick_screen_on_state_confirm_fan();
}

void delete_screen_on_state_confirm_fan() {
    lv_obj_delete(objects.on_state_confirm_fan);
    objects.on_state_confirm_fan = 0;
    objects.button_cancel_fan = 0;
    objects.nochange_fan = 0;
    objects.change_fan = 0;
}

void tick_screen_on_state_confirm_fan() {
}

void create_screen_tools() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.tools = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)8);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)8);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Clock_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.clock_settings = obj;
            lv_obj_set_pos(obj, 132, 16);
            lv_obj_set_size(obj, 110, 160);
            lv_obj_add_event_cb(obj, action_time_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_clock, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj1 = obj;
                    lv_obj_set_pos(obj, 0, 65);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Clock");
                }
            }
        }
        {
            // Timer_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.timer_settings = obj;
            lv_obj_set_pos(obj, 462, 16);
            lv_obj_set_size(obj, 110, 160);
            lv_obj_add_event_cb(obj, action_timer_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_timer_menu, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj2 = obj;
                    lv_obj_set_pos(obj, 0, 66);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Timer");
                }
            }
        }
        {
            // Configuration_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.configuration_settings = obj;
            lv_obj_set_pos(obj, 757, 16);
            lv_obj_set_size(obj, 180, 160);
            lv_obj_add_event_cb(obj, action_configuration_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_configuration, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj3 = obj;
                    lv_obj_set_pos(obj, -15, 122);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Configuration");
                }
            }
        }
        {
            // Tool_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.tool_settings = obj;
            lv_obj_set_pos(obj, 122, 220);
            lv_obj_set_size(obj, 130, 160);
            lv_obj_add_event_cb(obj, action_change_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_tool_menu, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj4 = obj;
                    lv_obj_set_pos(obj, 20, 124);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Tool");
                }
            }
        }
        {
            // Grafik_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.grafik_settings = obj;
            lv_obj_set_pos(obj, 457, 217);
            lv_obj_set_size(obj, 120, 160);
            lv_obj_add_event_cb(obj, action_grafik_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_grafik, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj5 = obj;
                    lv_obj_set_pos(obj, 0, 66);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Grafik");
                }
            }
        }
        {
            // Dispetcher_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.dispetcher_settings = obj;
            lv_obj_set_pos(obj, 772, 217);
            lv_obj_set_size(obj, 150, 160);
            lv_obj_add_event_cb(obj, action_dispetcher_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_dispetcher, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj6 = obj;
                    lv_obj_set_pos(obj, -12, 120);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Dispetcher");
                }
            }
        }
        {
            // Theme_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.theme_settings = obj;
            lv_obj_set_pos(obj, 127, 408);
            lv_obj_set_size(obj, 120, 160);
            lv_obj_add_event_cb(obj, action_thems_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_tems, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj7 = obj;
                    lv_obj_set_pos(obj, -1, 66);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Themes");
                }
            }
        }
        {
            // Visual_settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.visual_settings = obj;
            lv_obj_set_pos(obj, 418, 423);
            lv_obj_set_size(obj, 200, 130);
            lv_obj_add_event_cb(obj, action_visual_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_visual_settings, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.obj8 = obj;
                    lv_obj_set_pos(obj, -1, 53);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Visual");
                }
            }
        }
        {
            // button_back
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_back = obj;
            lv_obj_set_pos(obj, 787, 408);
            lv_obj_set_size(obj, 120, 160);
            lv_obj_add_event_cb(obj, action_menu_out, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_menu_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_tools();
}

void delete_screen_tools() {
    lv_obj_delete(objects.tools);
    objects.tools = 0;
    objects.clock_settings = 0;
    objects.obj1 = 0;
    objects.timer_settings = 0;
    objects.obj2 = 0;
    objects.configuration_settings = 0;
    objects.obj3 = 0;
    objects.tool_settings = 0;
    objects.obj4 = 0;
    objects.grafik_settings = 0;
    objects.obj5 = 0;
    objects.dispetcher_settings = 0;
    objects.obj6 = 0;
    objects.theme_settings = 0;
    objects.obj7 = 0;
    objects.visual_settings = 0;
    objects.obj8 = 0;
    objects.button_back = 0;
}

void tick_screen_tools() {
}

void create_screen_clock_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.clock_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)9);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)9);
    {
        lv_obj_t *parent_obj = obj;
        {
            // Date
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.date = obj;
            lv_obj_set_pos(obj, 158, 284);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "20.10.2025");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj9 = obj;
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xfffafafa), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // out_clock
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.out_clock = obj;
            lv_obj_set_pos(obj, 104, 442);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_out_clock, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 531, 15);
            lv_obj_set_size(obj, 10, 419);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 0, 500 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time = obj;
            lv_obj_set_pos(obj, 729, 284);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj10 = obj;
            lv_obj_set_pos(obj, 344, 442);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_inc_clock_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_inc, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj11 = obj;
            lv_obj_set_pos(obj, 579, 442);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_dec_clock_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_dec, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_conf_time
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_conf_time = obj;
            lv_obj_set_pos(obj, 799, 442);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_confirm_clock, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.obj12 = obj;
            lv_obj_set_pos(obj, 179, 54);
            lv_obj_set_size(obj, 200, 200);
            lv_image_set_src(obj, &img_calendar);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 681, 54);
            lv_obj_set_size(obj, 200, 200);
            lv_image_set_src(obj, &img_change_time);
        }
    }
    
    tick_screen_clock_menu();
}

void delete_screen_clock_menu() {
    lv_obj_delete(objects.clock_menu);
    objects.clock_menu = 0;
    objects.date = 0;
    objects.obj9 = 0;
    objects.out_clock = 0;
    objects.time = 0;
    objects.obj10 = 0;
    objects.obj11 = 0;
    objects.button_conf_time = 0;
    objects.obj12 = 0;
}

void tick_screen_clock_menu() {
}

void create_screen_timer_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.timer_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)10);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)10);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj13 = obj;
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xfffafafa), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj14 = obj;
            lv_obj_set_pos(obj, 78, 54);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_mon, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Mon");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj15 = obj;
            lv_obj_set_pos(obj, 312, 55);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_tue, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Tue");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj16 = obj;
            lv_obj_set_pos(obj, 558, 54);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_wed, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Wed");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj17 = obj;
            lv_obj_set_pos(obj, 792, 54);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_thu, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Thu");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj18 = obj;
            lv_obj_set_pos(obj, 78, 243);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_fri, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Fri");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj19 = obj;
            lv_obj_set_pos(obj, 312, 243);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_sat, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Sat");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj20 = obj;
            lv_obj_set_pos(obj, 558, 243);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_sun, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "Sun");
                }
            }
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj21 = obj;
            lv_obj_set_pos(obj, 792, 243);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_select_onetime, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_decor(obj, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN | LV_STATE_PRESSED);
                    lv_label_set_text(obj, "OFF");
                }
            }
        }
        {
            // out_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.out_timer = obj;
            lv_obj_set_pos(obj, 447, 451);
            lv_obj_set_size(obj, 130, 130);
            lv_obj_add_event_cb(obj, action_out_timer_tool, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_timer_menu();
}

void delete_screen_timer_menu() {
    lv_obj_delete(objects.timer_menu);
    objects.timer_menu = 0;
    objects.obj13 = 0;
    objects.obj14 = 0;
    objects.obj15 = 0;
    objects.obj16 = 0;
    objects.obj17 = 0;
    objects.obj18 = 0;
    objects.obj19 = 0;
    objects.obj20 = 0;
    objects.obj21 = 0;
    objects.out_timer = 0;
}

void tick_screen_timer_menu() {
}

void create_screen_timer_parametr_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.timer_parametr_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)11);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)11);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj22 = obj;
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xfffafafa), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // out_parametr_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.out_parametr_timer = obj;
            lv_obj_set_pos(obj, 99, 463);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_back_timer, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // up
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.up = obj;
            lv_obj_set_pos(obj, 310, 463);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_change_timer_mode_up, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_inc, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // down
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.down = obj;
            lv_obj_set_pos(obj, 548, 463);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_change_timer_mode_down, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_dec, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // confirm_timer_parametrs
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.confirm_timer_parametrs = obj;
            lv_obj_set_pos(obj, 779, 463);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_confirm_timer_mode, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
        {
            // time_start_timer
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.time_start_timer = obj;
            lv_obj_set_pos(obj, 213, 43);
            lv_obj_set_size(obj, 90, 90);
            lv_image_set_src(obj, &img_change_time);
            lv_image_set_scale(obj, 128);
        }
        {
            // temp_start_timer
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.temp_start_timer = obj;
            lv_obj_set_pos(obj, 467, 43);
            lv_obj_set_size(obj, 90, 90);
            lv_image_set_src(obj, &img_temp_timer);
            lv_image_set_scale(obj, 220);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 742, 39);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_fan_timer);
            lv_image_set_scale(obj, 200);
        }
        {
            // timer_mode1
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode1 = obj;
            lv_obj_set_pos(obj, 71, 157);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "1");
        }
        {
            // timer_mode2
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode2 = obj;
            lv_obj_set_pos(obj, 67, 223);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "2");
        }
        {
            // timer_mode3
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode3 = obj;
            lv_obj_set_pos(obj, 67, 281);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "3");
        }
        {
            // timer_mode4
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode4 = obj;
            lv_obj_set_pos(obj, 64, 344);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "4");
        }
        {
            // timer_mode2_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode2_time = obj;
            lv_obj_set_pos(obj, 206, 223);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "06:00");
        }
        {
            // timer_mode2_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode2_temp = obj;
            lv_obj_set_pos(obj, 491, 223);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25");
        }
        {
            // timer_mode2_fan_mode
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode2_fan_mode = obj;
            lv_obj_set_pos(obj, 757, 223);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "N/A");
        }
        {
            // timer_mode3_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode3_time = obj;
            lv_obj_set_pos(obj, 213, 281);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:00");
        }
        {
            // timer_mode3_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode3_temp = obj;
            lv_obj_set_pos(obj, 491, 280);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25");
        }
        {
            // timer_mode3_fan_mode
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode3_fan_mode = obj;
            lv_obj_set_pos(obj, 757, 280);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "N/A");
        }
        {
            // timer_mode4_time
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode4_time = obj;
            lv_obj_set_pos(obj, 211, 343);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "18:00");
        }
        {
            // timer_mode4_temp
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode4_temp = obj;
            lv_obj_set_pos(obj, 491, 344);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25");
        }
        {
            // timer_mode4_fan_mode
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.timer_mode4_fan_mode = obj;
            lv_obj_set_pos(obj, 757, 344);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "N/A");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 550, 223);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 550, 281);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 550, 344);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_obj_create(parent_obj);
            objects.obj23 = obj;
            lv_obj_set_pos(obj, 206, 157);
            lv_obj_set_size(obj, 619, 40);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    // timer_mode1_time
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.timer_mode1_time = obj;
                    lv_obj_set_pos(obj, -22, -22);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "00:00");
                }
                {
                    // timer_mode1_temp
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.timer_mode1_temp = obj;
                    lv_obj_set_pos(obj, 263, -22);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "25");
                }
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 322, -21);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "°C");
                }
                {
                    // timer_mode1_fan_mode
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    objects.timer_mode1_fan_mode = obj;
                    lv_obj_set_pos(obj, 529, -21);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "N/A");
                }
            }
        }
    }
    
    tick_screen_timer_parametr_menu();
}

void delete_screen_timer_parametr_menu() {
    lv_obj_delete(objects.timer_parametr_menu);
    objects.timer_parametr_menu = 0;
    objects.obj22 = 0;
    objects.out_parametr_timer = 0;
    objects.up = 0;
    objects.down = 0;
    objects.confirm_timer_parametrs = 0;
    objects.time_start_timer = 0;
    objects.temp_start_timer = 0;
    objects.timer_mode1 = 0;
    objects.timer_mode2 = 0;
    objects.timer_mode3 = 0;
    objects.timer_mode4 = 0;
    objects.timer_mode2_time = 0;
    objects.timer_mode2_temp = 0;
    objects.timer_mode2_fan_mode = 0;
    objects.timer_mode3_time = 0;
    objects.timer_mode3_temp = 0;
    objects.timer_mode3_fan_mode = 0;
    objects.timer_mode4_time = 0;
    objects.timer_mode4_temp = 0;
    objects.timer_mode4_fan_mode = 0;
    objects.obj23 = 0;
    objects.timer_mode1_time = 0;
    objects.timer_mode1_temp = 0;
    objects.timer_mode1_fan_mode = 0;
}

void tick_screen_timer_parametr_menu() {
}

void create_screen_on_state_mainscreen_with_timer() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.on_state_mainscreen_with_timer = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)12);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)12);
    {
        lv_obj_t *parent_obj = obj;
        {
            // button_tool_with_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_tool_with_timer = obj;
            lv_obj_set_pos(obj, 801, 464);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_go_to_menu_with_timer, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_tool, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_power_with_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_power_with_timer = obj;
            lv_obj_set_pos(obj, 107, 464);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_power_off_with_timer, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_power, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main_temp_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_temp_with_timer = obj;
            lv_obj_set_pos(obj, 493, 164);
            lv_obj_set_size(obj, 56, 55);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "25");
        }
        {
            // Time_main_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.time_main_with_timer = obj;
            lv_obj_set_pos(obj, 142, 85);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_40, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12:12");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 665, 58);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_tree);
        }
        {
            // button_temp_with_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_temp_with_timer = obj;
            lv_obj_set_pos(obj, 337, 442);
            lv_obj_set_size(obj, 150, 150);
            // lv_obj_add_event_cb(obj, action_set_temp_with_timer, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_temp, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // button_fan_with_timer
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.button_fan_with_timer = obj;
            lv_obj_set_pos(obj, 569, 464);
            lv_obj_set_size(obj, 120, 120);
            // lv_obj_add_event_cb(obj, action_set_fan_mode_with_timer, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_fan, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Humadity_with_timer
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.humadity_with_timer = obj;
            lv_obj_set_pos(obj, 350, 303);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_humadity);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Get_humadity_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_humadity_with_timer = obj;
            lv_obj_set_pos(obj, 342, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "10 %");
        }
        {
            // Get_CO2_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_co2_with_timer = obj;
            lv_obj_set_pos(obj, 452, 385);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "600 ppm");
        }
        {
            // PM2.5_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.pm2_5_with_timer = obj;
            lv_obj_set_pos(obj, 637, 319);
            lv_obj_set_size(obj, 118, 42);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "PM2.5");
        }
        {
            // Get_pm25_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_pm25_with_timer = obj;
            lv_obj_set_pos(obj, 634, 385);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_26, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12 mkg/m3");
        }
        {
            // Get_visual_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_visual_with_timer = obj;
            lv_obj_set_pos(obj, 132, 383);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "20 %");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 23, 437);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 549, 145);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_34, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 286, 107);
            lv_obj_set_size(obj, 506, 57);
            static lv_point_precise_t line_points[] = {
                { 1, 50 },
                { 251, 0 },
                { 501, 50 }
            };
            lv_line_set_points(obj, line_points, 3);
            lv_obj_set_style_line_width(obj, 5, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 141, 257);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_visual);
            lv_image_set_scale(obj, 200);
        }
        {
            // CO2_with_timer
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.co2_with_timer = obj;
            lv_obj_set_pos(obj, 480, 319);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_co2);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff000000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Main_real_temp_with_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.main_real_temp_with_timer = obj;
            lv_obj_set_pos(obj, 731, 77);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 775, 52);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_30, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 801, 141);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_start_timer);
            lv_image_set_scale(obj, 180);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 803, 210);
            lv_obj_set_size(obj, 65, 65);
            lv_image_set_src(obj, &img_temp_timer);
            lv_image_set_scale(obj, 165);
        }
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 808, 281);
            lv_obj_set_size(obj, 55, 55);
            lv_image_set_src(obj, &img_fann_timer);
            lv_image_set_scale(obj, 154);
        }
        {
            // start_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.start_timer = obj;
            lv_obj_set_pos(obj, 879, 162);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "01:35");
        }
        {
            // temp_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.temp_timer = obj;
            lv_obj_set_pos(obj, 879, 229);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "22");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 910, 229);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "°C");
        }
        {
            // fan_timer
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.fan_timer = obj;
            lv_obj_set_pos(obj, 881, 295);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "1");
        }
        {
            // Timer_with_timer
            lv_obj_t *obj = lv_image_create(parent_obj);
            objects.timer_with_timer = obj;
            lv_obj_set_pos(obj, 840, 35);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_timer);
        }
    }
    
    tick_screen_on_state_mainscreen_with_timer();
}

void delete_screen_on_state_mainscreen_with_timer() {
    lv_obj_delete(objects.on_state_mainscreen_with_timer);
    objects.on_state_mainscreen_with_timer = 0;
    objects.button_tool_with_timer = 0;
    objects.button_power_with_timer = 0;
    objects.main_temp_with_timer = 0;
    objects.time_main_with_timer = 0;
    objects.button_temp_with_timer = 0;
    objects.button_fan_with_timer = 0;
    objects.humadity_with_timer = 0;
    objects.get_humadity_with_timer = 0;
    objects.get_co2_with_timer = 0;
    objects.pm2_5_with_timer = 0;
    objects.get_pm25_with_timer = 0;
    objects.get_visual_with_timer = 0;
    objects.co2_with_timer = 0;
    objects.main_real_temp_with_timer = 0;
    objects.start_timer = 0;
    objects.temp_timer = 0;
    objects.fan_timer = 0;
    objects.timer_with_timer = 0;
}

void tick_screen_on_state_mainscreen_with_timer() {
}

void create_screen_setting_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.setting_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)13);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)13);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_arc_create(parent_obj);
            lv_obj_set_pos(obj, 412, 108);
            lv_obj_set_size(obj, 200, 200);
            lv_arc_set_value(obj, 25);
        }
        {
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.obj24 = obj;
            lv_obj_set_pos(obj, 437, 374);
            lv_obj_set_size(obj, 150, 150);
            lv_obj_add_event_cb(obj, action_out_setting, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_setting_menu();
}

void delete_screen_setting_menu() {
    lv_obj_delete(objects.setting_menu);
    objects.setting_menu = 0;
    objects.obj24 = 0;
}

void tick_screen_setting_menu() {
}

void create_screen_configuration_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.configuration_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)14);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)14);
    lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 247, 55);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Configuration system");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 26, 128);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 375, 442);
            lv_obj_set_size(obj, 623, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // out_configuration
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.out_configuration = obj;
            lv_obj_set_pos(obj, 413, 459);
            lv_obj_set_size(obj, 500, 120);
            lv_obj_add_event_cb(obj, action_out_configuration, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // Configuration
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.configuration = obj;
            lv_obj_set_pos(obj, 96, 149);
            lv_obj_set_size(obj, 260, 100);
            lv_obj_add_event_cb(obj, action_open_configuration, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Configuration");
                }
            }
        }
        {
            // Settings
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.settings = obj;
            lv_obj_set_pos(obj, 452, 149);
            lv_obj_set_size(obj, 200, 100);
            lv_obj_add_event_cb(obj, action_open_settings, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Settings");
                }
            }
        }
        {
            // PID_regulator
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.pid_regulator = obj;
            lv_obj_set_pos(obj, 737, 149);
            lv_obj_set_size(obj, 200, 100);
            lv_obj_add_event_cb(obj, action_open_pid, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "PID");
                }
            }
        }
        {
            // Temps_datchik
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.temps_datchik = obj;
            lv_obj_set_pos(obj, 106, 292);
            lv_obj_set_size(obj, 240, 100);
            lv_obj_add_event_cb(obj, action_open_temps_datchiks, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Tips temps\ndatchik");
                }
            }
        }
        {
            // Calibration
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.calibration = obj;
            lv_obj_set_pos(obj, 442, 292);
            lv_obj_set_size(obj, 220, 100);
            lv_obj_add_event_cb(obj, action_open_calibration, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Calibration");
                }
            }
        }
        {
            // Real_datchik_value
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.real_datchik_value = obj;
            lv_obj_set_pos(obj, 712, 292);
            lv_obj_set_size(obj, 250, 100);
            lv_obj_add_event_cb(obj, action_open_real_datchiks_value, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Real datchik\nvalue");
                }
            }
        }
        {
            // Modbus
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.modbus = obj;
            lv_obj_set_pos(obj, 101, 459);
            lv_obj_set_size(obj, 250, 100);
            lv_obj_add_event_cb(obj, action_open_modbus_parameters, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_36, LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "Modbus\nparameters");
                }
            }
        }
    }
    
    tick_screen_configuration_menu();
}

void delete_screen_configuration_menu() {
    lv_obj_delete(objects.configuration_menu);
    objects.configuration_menu = 0;
    objects.out_configuration = 0;
    objects.configuration = 0;
    objects.settings = 0;
    objects.pid_regulator = 0;
    objects.temps_datchik = 0;
    objects.calibration = 0;
    objects.real_datchik_value = 0;
    objects.modbus = 0;
}

void tick_screen_configuration_menu() {
}

void create_screen_grafik_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.grafik_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)15);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)15);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_chart_create(parent_obj);
            objects.obj25 = obj;
            lv_obj_set_pos(obj, 99, 47);
            lv_obj_set_size(obj, 882, 362);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_BOTTOM|LV_BORDER_SIDE_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_chart_series_t *ser1 = lv_chart_add_series(obj, lv_palette_main(LV_PALETTE_GREEN), LV_CHART_AXIS_PRIMARY_Y);
            lv_chart_series_t *ser2 = lv_chart_add_series(obj, lv_palette_main(LV_PALETTE_RED), LV_CHART_AXIS_SECONDARY_Y);
            int32_t *ser2_y_points = lv_chart_get_series_y_array(obj, ser2);

            uint32_t i;
            for (i = 0; i < 10; i++)
            {
                /*Set the next points on 'ser1'*/
                lv_chart_set_next_value(obj, ser1, (int32_t)lv_rand(10, 50));

                /*Directly set points on 'ser2'*/
                ser2_y_points[i] = (int32_t)lv_rand(50, 90);
            }

            lv_chart_refresh(obj); /*Required after direct set*/
        }
        {
            // out_grafik
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.out_grafik = obj;
            lv_obj_set_pos(obj, 481, 426);
            lv_obj_set_size(obj, 500, 150);
            lv_obj_add_event_cb(obj, action_out_grafik, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_side(obj, LV_BORDER_SIDE_FULL, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(obj, lv_color_hex(0xffffffff), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_width(obj, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj26 = obj;
            lv_obj_set_pos(obj, 99, 453);
            lv_obj_set_size(obj, 140, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 140, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff2ec237), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj27 = obj;
            lv_obj_set_pos(obj, 100, 500);
            lv_obj_set_size(obj, 140, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 140, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xffff0000), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            objects.obj28 = obj;
            lv_obj_set_pos(obj, 100, 544);
            lv_obj_set_size(obj, 140, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 140, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_line_color(obj, lv_color_hex(0xff609bff), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 256, 440);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Target:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 256, 487);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "On room:");
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 256, 531);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Real:");
        }
        {
            // target_temp_grafik
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.target_temp_grafik = obj;
            lv_obj_set_pos(obj, 383, 440);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "23");
        }
        {
            // onroom_temp_grafik
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.onroom_temp_grafik = obj;
            lv_obj_set_pos(obj, 383, 487);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "18");
        }
        {
            // real_temp_grafik
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.real_temp_grafik = obj;
            lv_obj_set_pos(obj, 383, 531);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "20");
        }
    }
    
    tick_screen_grafik_menu();
}

void delete_screen_grafik_menu() {
    lv_obj_delete(objects.grafik_menu);
    objects.grafik_menu = 0;
    objects.obj25 = 0;
    objects.out_grafik = 0;
    objects.obj26 = 0;
    objects.obj27 = 0;
    objects.obj28 = 0;
    objects.target_temp_grafik = 0;
    objects.onroom_temp_grafik = 0;
    objects.real_temp_grafik = 0;
}

void tick_screen_grafik_menu() {
}

void create_screen_dispetcher_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.dispetcher_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)16);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)16);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_image_create(parent_obj);
            lv_obj_set_pos(obj, 464, 252);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_image_set_src(obj, &img_fan_timer);
            lv_image_set_scale(obj, 556);
        }
        {
            // out_dispetcher
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.out_dispetcher = obj;
            lv_obj_set_pos(obj, 437, 444);
            lv_obj_set_size(obj, 150, 100);
            lv_obj_add_event_cb(obj, action_out_dispetcher, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_image_src(obj, &img_clock_out, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
    }
    
    tick_screen_dispetcher_menu();
}

void delete_screen_dispetcher_menu() {
    lv_obj_delete(objects.dispetcher_menu);
    objects.dispetcher_menu = 0;
    objects.out_dispetcher = 0;
}

void tick_screen_dispetcher_menu() {
}

void create_screen_themes_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.themes_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)17);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)17);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 316, 274);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Change theme?");
        }
        {
            // change_theme
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.change_theme = obj;
            lv_obj_set_pos(obj, 316, 347);
            lv_obj_set_size(obj, 150, 80);
            lv_obj_add_event_cb(obj, action_change_theme, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "YES");
                }
            }
        }
        {
            // nochange_theme
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.nochange_theme = obj;
            lv_obj_set_pos(obj, 559, 347);
            lv_obj_set_size(obj, 150, 80);
            lv_obj_add_event_cb(obj, action_nochange_theme, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_42, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "NO");
                }
            }
        }
    }
    
    tick_screen_themes_menu();
}

void delete_screen_themes_menu() {
    lv_obj_delete(objects.themes_menu);
    objects.themes_menu = 0;
    objects.change_theme = 0;
    objects.nochange_theme = 0;
}

void tick_screen_themes_menu() {
}

void create_screen_visual_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.visual_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)18);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)18);
    
    tick_screen_visual_menu();
}

void delete_screen_visual_menu() {
    lv_obj_delete(objects.visual_menu);
    objects.visual_menu = 0;
}

void tick_screen_visual_menu() {
}

void create_screen_pasword_menu() {
    lv_obj_t *obj = lv_obj_create(0);
    objects.pasword_menu = obj;
    lv_obj_set_pos(obj, 0, 0);
    lv_obj_set_size(obj, 1024, 600);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_LOADED, (void *)19);
    lv_obj_add_event_cb(obj, action_screen, LV_EVENT_SCREEN_UNLOADED, (void *)19);
    {
        lv_obj_t *parent_obj = obj;
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 26, 128);
            lv_obj_set_size(obj, 972, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 972, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            lv_obj_t *obj = lv_label_create(parent_obj);
            lv_obj_set_pos(obj, 322, 55);
            lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "Enter password");
        }
        {
            lv_obj_t *obj = lv_line_create(parent_obj);
            lv_obj_set_pos(obj, 26, 270);
            lv_obj_set_size(obj, 685, 5);
            static lv_point_precise_t line_points[] = {
                { 0, 0 },
                { 685, 0 }
            };
            lv_line_set_points(obj, line_points, 2);
            lv_obj_set_style_line_width(obj, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // backspace
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.backspace = obj;
            lv_obj_set_pos(obj, 787, 160);
            lv_obj_set_size(obj, 150, 100);
            // lv_obj_add_event_cb(obj, action_backspace, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_image_src(obj, &img_backspace, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
        }
        {
            // get_password
            lv_obj_t *obj = lv_label_create(parent_obj);
            objects.get_password = obj;
            lv_obj_set_pos(obj, 91, 195);
            lv_obj_set_size(obj, 596, 65);
            lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_label_set_text(obj, "12345677");
        }
        {
            // n1
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n1 = obj;
            lv_obj_set_pos(obj, 60, 320);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_1, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "1");
                }
            }
        }
        {
            // n2
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n2 = obj;
            lv_obj_set_pos(obj, 210, 320);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_2, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "2");
                }
            }
        }
        {
            // n3
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n3 = obj;
            lv_obj_set_pos(obj, 360, 320);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_3, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "3");
                }
            }
        }
        {
            // n4
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n4 = obj;
            lv_obj_set_pos(obj, 510, 320);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_4, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "4");
                }
            }
        }
        {
            // n5
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n5 = obj;
            lv_obj_set_pos(obj, 660, 320);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_5, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "5");
                }
            }
        }
        {
            // n6
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n6 = obj;
            lv_obj_set_pos(obj, 810, 320);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_6, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "6");
                }
            }
        }
        {
            // n7
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n7 = obj;
            lv_obj_set_pos(obj, 60, 438);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_7, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "7");
                }
            }
        }
        {
            // n8
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n8 = obj;
            lv_obj_set_pos(obj, 211, 438);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_8, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "8");
                }
            }
        }
        {
            // n9
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n9 = obj;
            lv_obj_set_pos(obj, 362, 438);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_9, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "9");
                }
            }
        }
        {
            // n0
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.n0 = obj;
            lv_obj_set_pos(obj, 510, 438);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_0, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "0");
                }
            }
        }
        {
            // _
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects._ = obj;
            lv_obj_set_pos(obj, 660, 438);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_write_underline, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "_");
                }
            }
        }
        {
            // confirm_pass
            lv_obj_t *obj = lv_button_create(parent_obj);
            objects.confirm_pass = obj;
            lv_obj_set_pos(obj, 810, 438);
            lv_obj_set_size(obj, 130, 90);
            // lv_obj_add_event_cb(obj, action_enter_password, LV_EVENT_PRESSED, (void *)0);
            lv_obj_set_style_bg_color(obj, lv_color_hex(0xff15171a), LV_PART_MAIN | LV_STATE_DEFAULT);
            {
                lv_obj_t *parent_obj = obj;
                {
                    lv_obj_t *obj = lv_label_create(parent_obj);
                    lv_obj_set_pos(obj, 0, 0);
                    lv_obj_set_size(obj, LV_SIZE_CONTENT, LV_SIZE_CONTENT);
                    lv_obj_set_style_align(obj, LV_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_obj_set_style_text_font(obj, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);
                    lv_label_set_text(obj, "OK");
                }
            }
        }
    }
    
    tick_screen_pasword_menu();
}

void delete_screen_pasword_menu() {
    lv_obj_delete(objects.pasword_menu);
    objects.pasword_menu = 0;
    objects.backspace = 0;
    objects.get_password = 0;
    objects.n1 = 0;
    objects.n2 = 0;
    objects.n3 = 0;
    objects.n4 = 0;
    objects.n5 = 0;
    objects.n6 = 0;
    objects.n7 = 0;
    objects.n8 = 0;
    objects.n9 = 0;
    objects.n0 = 0;
    objects._ = 0;
    objects.confirm_pass = 0;
}

void tick_screen_pasword_menu() {
}



typedef void (*create_screen_func_t)();
create_screen_func_t create_screen_funcs[] = {
    create_screen_blank,
    create_screen_off_state,
    create_screen_on_state_mainscreen,
    create_screen_on_state_change_temp,
    create_screen_on_state_confirm_temp,
    create_screen_on_state_change_fan,
    create_screen_on_state_confirm_fan,
    create_screen_tools,
    create_screen_clock_menu,
    create_screen_timer_menu,
    create_screen_timer_parametr_menu,
    create_screen_on_state_mainscreen_with_timer,
    create_screen_setting_menu,
    create_screen_configuration_menu,
    create_screen_grafik_menu,
    create_screen_dispetcher_menu,
    create_screen_themes_menu,
    create_screen_visual_menu,
    create_screen_pasword_menu,
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
    delete_screen_on_state_confirm_temp,
    delete_screen_on_state_change_fan,
    delete_screen_on_state_confirm_fan,
    delete_screen_tools,
    delete_screen_clock_menu,
    delete_screen_timer_menu,
    delete_screen_timer_parametr_menu,
    delete_screen_on_state_mainscreen_with_timer,
    delete_screen_setting_menu,
    delete_screen_configuration_menu,
    delete_screen_grafik_menu,
    delete_screen_dispetcher_menu,
    delete_screen_themes_menu,
    delete_screen_visual_menu,
    delete_screen_pasword_menu,
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
    tick_screen_on_state_confirm_temp,
    tick_screen_on_state_change_fan,
    tick_screen_on_state_confirm_fan,
    tick_screen_tools,
    tick_screen_clock_menu,
    tick_screen_timer_menu,
    tick_screen_timer_parametr_menu,
    tick_screen_on_state_mainscreen_with_timer,
    tick_screen_setting_menu,
    tick_screen_configuration_menu,
    tick_screen_grafik_menu,
    tick_screen_dispetcher_menu,
    tick_screen_themes_menu,
    tick_screen_visual_menu,
    tick_screen_pasword_menu,
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
    create_screen_dispetcher_menu();
    create_screen_themes_menu();
}
