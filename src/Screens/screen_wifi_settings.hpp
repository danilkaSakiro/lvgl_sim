#pragma once
#include "screen_base.hpp"
#include "ui.h"
#include "actions.h"

class screen_wifi_settings : public screen_base
{
public:
    screen_wifi_settings(int screen_id);
    virtual ~screen_wifi_settings();

protected:
    void updateScreenAction(float с) override;

private:
    
};