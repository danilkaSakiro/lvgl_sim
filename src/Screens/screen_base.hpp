#pragma once
#include <string>

class screen_base
{
public:
    screen_base(int screen_id);
    virtual ~screen_base();
    int id() {return _screen_id;}

    void updateScreen(int a, int b, int c);
    void updateScreen(std::string a, int b);

protected:
    virtual void updateScreenAction(int a, int b, int c);
    virtual void updateScreenAction(std::string a, int b);
    
private:
    int _screen_id;
};