#pragma once

class TempChanges
{
public:
    static int gettemperature_ch() { return temperature_ch;} // Temp Changes
    static void settemperature_ch(int i) { temperature_ch = i;}
    static int gettemperature() { return temperature;}
    static void settemperature(int i) { temperature = i;}
    static bool gettemp_change() { return temperature_change;}
    static void settemp_change(bool flag) { temperature_change = flag;}

private:
    static int temperature_ch;
    static int temperature;
    static bool temperature_change;

};

class FanChanges
{
public:
    static int getfan_mode_ch() { return fan_mode_ch;} // Fan Changes
    static void setfan_mode_ch(int j) { fan_mode_ch = j;}
    static int getfan_mode() { return fan_mode;}
    static void setfan_mode(int i) { fan_mode = i;}
    static bool getfan_mode_change() { return fan_mode_change;}
    static void setfan_mode_change(bool flag) { fan_mode_change = flag;}

private:
    static int fan_mode_ch;
    static int fan_mode;
    static bool fan_mode_change;
};