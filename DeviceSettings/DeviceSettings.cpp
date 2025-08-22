#include "DeviceSettings.hpp"
#include <stdio.h>
#include <cstdlib>

int TempChanges::temperature = 25;
int TempChanges::temperature_ch = temperature;
 
bool TempChanges::temperature_change = false; 

int FanChanges::fan_mode = 3;
int FanChanges::fan_mode_ch = fan_mode;
 
bool FanChanges::fan_mode_change = false; 