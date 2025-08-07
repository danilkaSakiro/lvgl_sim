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
    void updateScreen(std::string a);
    void updateScreen(int a, float c); 
    void updateScreen(float c); 
    void updateScreen(int a); 

protected:
    virtual void updateScreenAction(int a, int b, int c);
    virtual void updateScreenAction(std::string a, int b);
    virtual void updateScreenAction(std::string a);
    virtual void updateScreenAction(int a, float c);
    virtual void updateScreenAction(float c);
    virtual void updateScreenAction(int a);

private:
    int _screen_id;
};