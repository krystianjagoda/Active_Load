// Krystian Jagoda krystianjagoda@gmail.com
// Active Load - Master Thesis 2015-2016

#include <device.h>
#include <stdio.h>
#include "u8g_arm.h"

#include "global_variables.h"
#include "state_machine.h"
#include "LCD_Menu.h"
#include "temp_manage.h"

#if defined (__GNUC__)
    asm (".global _printf_float");  /* Add an explicit reference to the floating point printf library */
#endif

//-------------------------------------------------------------------------------------------------------------------------


void Initialize(void);


uint32 Main_Counter = 0;


//-------------------------------------------------------------------------------------------------------------------------
int main()
{
    // Set Limit Values Here
    MaxPower = 130.00;
    MaxVoltage = 28.00;
    MaxCurrent = 2.00;
    MinResistance = 8;
    MaxResistance = 2000;
    Max_FET_Temp = 40;
    
    // Set Current PID Regulator Here
    C_Kp = 1.00;
    C_Ki = 0.00;
    C_Kd = 0.00;
    
    //Set Calibration Values Here:
    Current_Calibration_Range1 = 1.05;
    Current_Calibration_Range2 = 2.60;
    Current_Calibration_Range3 = 5.24;
    
    LEM_Offset_Value = 33;
    
    Two_Wire_Range = 15.00;
    Four_Wire_Range = 14.63;
    
    // Interface Values
    CurrentVolumeValue = 1;         //10 is Max
    CurrentBacklightValue = 7;      //10 is Max
    Push_Buzzer__Default_Lenght = 5000;
    Rotate_Buzzer__Default_Lenght = 1000;
    
    CyDelay(100); // 100ms Delay
    
    Initialize();
    
    
    Previous_State = Home;
    Current_State = Home;
    
   // Current_State = Develop;


    QD_SetCounter(3);
    OutputEnable = 0;
    

    
    
    
    

    
//-------------------------------------------------------------------------------------------------------------------------
    while(1)
    {


        Check_Buttons();
        State_Machine();
        
        
        Main_Counter++;
        if(Main_Counter >= 5000){
            Temp_Management(Max_FET_Temp);
            Main_Counter = 0;
        }
        
    }
}
//-------------------------------------------------------------------------------------------------------------------------


void Initialize(void){
    //Enable global interrupts
    CyGlobalIntEnable;
      
    // Driver
    DAC_MUX_Select(0);
    WaveDAC8_1_Start();    
    DVDAC8_1_Start();  
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();    
    ADC_SAR_2_Start();
    ADC_SAR_2_StartConvert();
    
    //I2C
    I2C_Start();
    
    // Clocks
    Clock_QD_1_Start();
    Clock_QD_2_Start();
    Clock_QD_4_Start();
    Clock_FAN_Start();
    
    //LCD
    u8g_InitComFn(&u8g, &u8g_dev_st7565_dogm128_hw_spi, u8g_com_hw_spi_fn);
    u8g_SetContrast(&u8g,55); // Ustawienie kontrastu
    PWM_Back_Start();   
    SetBacklight(CurrentBacklightValue);
    
    //Buzzer
    Sound_Enable = 1;
    PWM_Buzz_Start(); 
    SetVolume(CurrentVolumeValue);
    
    //Encoder
    QD_Start();    
    
    //Temperature
    Current_FET_Temp = 1;  //Dummy change for initial check pass...
    
    Actual_Range = 1;
    Four_Wire_Method = 1;            
    
}   
