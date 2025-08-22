#pragma once
#include "screen_menu.hpp"
#include "ui.h"
#include "actions.h"

class screen_visual : public screen_menu
{
public:
    screen_visual(int screen_id);
    virtual ~screen_visual();

protected:
    void updateScreenAction(int c) override;

private:

};