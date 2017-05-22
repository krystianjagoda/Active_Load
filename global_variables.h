#include <device.h>
#include <stdio.h>
#include "u8g_arm.h"

enum State {Develop, Home, ConstantMode, ArbitraryMode, ConstantCurrent, Settings, BacklightSetting, VolumeSetting,
            Information, ConstantPower, ConstantResistance, Error_RP, Error_OV, Error_NC, Error_OT, Error_OC,
            WaveForm_Mode, PWM_Mode, External_Drive};

enum State Current_State;
enum State Previous_State;

uint8 Sound_Enable;

uint8 Current_Menu_Position; // Selected Position in Current Menu


uint8 CurrentBacklightValue;
char8 CurrentBacklightValueString[8u];

uint8 CurrentVolumeValue;
char8 CurrentVolumeValueString[8u];

float Current_Calibration_Range1;
float Current_Calibration_Range2;
float Current_Calibration_Range3;

uint8 LEM_Offset_Value;

float Two_Wire_Range;
float Four_Wire_Range;
uint8 Four_Wire_Method;

uint8 Actual_Range;
uint8 View_Mode;


uint16 qdCount;    // Current Encoder Value
uint16 Last_qdCount;    // Last Encoder Value

uint8 button1, button2, button3, button4, button5, button6, push;

uint8 OutputEnable;

u8g_t u8g;

uint32 Push_Buzzer__Default_Lenght;
uint32 Rotate_Buzzer__Default_Lenght;

void Buzzer(uint8 Enable);
void Buzzer_Shot(uint32 pulse_length);

uint8 Check_Input(void);

void SetVolume(uint8 VolumeValue);
void Check_Buttons(void);
void SetBacklight(uint8 BacklightValue);
uint16 Get_Encoder(uint16 maxValue);
uint16 Get_Encoder_Menu(uint16 minValue, uint16 maxValue);

uint8  Edit_Value_Mode;

char8 cVoltage_Actual[16u];
char8 cCurrent_Actual[16u];
char8 cPower_Actual[16u];
char cResist_Actual[16u];

char8 cVoltage_Set[16u];
char8 cCurrent_Set[16u];
char8 cPower_Set[16u];
char8 cResist_Set[16u];

char8 TestChar[16];


// Touch Screen
int16 XPosition;
char8 cXPosition[16];
int16 YPosition;
char8 cYPosition[16];
uint8 Touched;

uint16 MeasuredVoltage;
float fVoltage;
int16 MeasuredCurrent;
float fCurrent;
int16 Power;
float fPower;
int16 Resist;
float fResist;


float Set_Voltage;
float  Set_Current;  
float  Set_Current_Temporary_Value;
float Set_Power;
float Set_Power_Temporary_Value;
float Set_Resist;
float Set_Resist_Temporary_Value;

int8 Position_Number;


// Settings
float MaxPower;
float MaxVoltage;
float MaxCurrent;
float MinResistance;
float MaxResistance;
float C_Kp;   // Propotional
float C_Ki;   // Integral
float C_Kd;   // Derivative 
int8  Max_FET_Temp;
uint8 OverTemperature;

//PWM Mode
int16 Set_Ampl;
int16 Set_Ampl_Temporary_Value;
uint16 Set_Freq;
int32 Set_Freq_Temporary_Value;
int8 Set_Duty;
int8 Set_Duty_Temporary_Value;
char8 cSet_Ampl[16u];
char8 cSet_Freq[16u];
char8 cSet_Duty[16u];

uint8 Current_Edit_Value;
uint8 Actual_Multiplier_Value;



char8 cCounter[32u];