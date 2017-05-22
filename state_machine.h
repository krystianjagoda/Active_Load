#include <device.h>
#include <stdio.h>


// Menus
void State_Machine();
void State_Machine_Home();
void State_Machine_Settings();
void State_Machine_BacklightSetting();
void State_Machine_VolumeSetting();
void State_Machine_Information();  
void State_Machine_ConstantMode();
void State_Machine_ArbitraryMode();

// Driving Modes
void State_Machine_ConstantCurrent();  
void State_Machine_ConstantPower();
void State_Machine_ConstantResistance();

void State_Machine_WaveForm_Mode();
void State_Machine_PWM_Mode();
void State_Machine_External_Drive();

//Error Modes:
void State_Machine_Error_RP();
void State_Machine_Error_OV();
void State_Machine_Error_NC();
void State_Machine_Error_OT();
void State_Machine_Error_OC();

