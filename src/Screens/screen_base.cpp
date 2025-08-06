#include "screen_base.hpp"
#include "esp_lvgl_port.h"

screen_base::screen_base(int screen_id) 
    : _screen_id(screen_id)
{
};

screen_base::~screen_base() 
{
};

void screen_base::updateScreen(int a, int b, int c) {
    lvgl_port_lock(0);
    updateScreenAction(a, b, c);
    lvgl_port_unlock();
};

void screen_base::updateScreen(std::string a, int b) {
    lvgl_port_lock(0);
    updateScreenAction(a, b);
    lvgl_port_unlock();
};

void screen_base::updateScreen(std::string a) {
    lvgl_port_lock(0);
    updateScreenAction(a);
    lvgl_port_unlock();
}

void screen_base::updateScreen(float c) {
    lvgl_port_lock(0);
    updateScreenAction(c);
    lvgl_port_unlock();
}

void screen_base::updateScreenAction(int a, int b, int c) 
{

};

void screen_base::updateScreenAction(std::string a, int b) 
{

};

void screen_base::updateScreenAction(std::string a) 
{

};

void screen_base::updateScreenAction(float c)
{

};