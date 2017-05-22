#include "global_variables.h"



void SetBacklight(uint8 BacklightValue);
void Check_Buttons(void);


void Buzzer_Shot(uint32 pulse_length){
    if(Sound_Enable == 1){
        Counter_Buzz_WriteCompare(pulse_length);
        Counter_Buzz_WriteCounter(0);
        Counter_Buzz_Start();
    }
}


void Buzzer(uint8 Enable){
    if(Sound_Enable == 1){
        if(Enable == 1){ 
            PWM_Buzz_Start();
        }
        if(Enable == 0){
            PWM_Buzz_Stop();
        }
    }
}


uint8 Check_Input(){
    if(REV_POLARITY_Read() == 1){
        Previous_State = Current_State;
        Current_State = Error_RP;
        Buzzer_Shot(500000);
        return 0;
    }
    else if(INPUT_OK_Read() == 0){
        Previous_State = Current_State;
        Current_State = Error_NC;
        Buzzer_Shot(500000);
        return 0;
    }   
    else{
        return 1;
    }
}

uint16 Get_Encoder(uint16 maxValue){
    qdCount = QD_GetCounter();  // Encoder Value   
    if(!(Last_qdCount == qdCount)){
        Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
        if(qdCount >= 65530){
            QD_SetCounter(0);
            qdCount = 0;
        }       
        if(qdCount >= maxValue-1){
            QD_SetCounter(maxValue-1);
            qdCount = maxValue-1;
        }
        Last_qdCount = qdCount;
    }
    return Last_qdCount;
}

uint16 Get_Encoder_Menu(uint16 minValue, uint16 maxValue){
    qdCount = QD_GetCounter();  // Encoder Value    
    if(!(Last_qdCount == qdCount)){
        Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
        if(qdCount >= 65530){
            QD_SetCounter(0);
            qdCount = 0;
        }  
        if(qdCount < minValue){
            QD_SetCounter(minValue);
            qdCount = minValue;
        }       
        if(qdCount >= maxValue){
            QD_SetCounter(maxValue);
            qdCount = maxValue;
        }
        Last_qdCount = qdCount;
    }
    return Last_qdCount;  
}

void Check_Buttons(void){
    button1 = Button1_Reg_Read();
    button2 = Button2_Reg_Read();
    button3 = Button3_Reg_Read();
    button4 = Button4_Reg_Read();
    button5 = Button5_Reg_Read();
    button6 = Button6_Reg_Read(); 
}

void SetBacklight(uint8 BacklightValue){
    int Backlight = BacklightValue;
    if(Backlight>=10) Backlight = 10;
    if(Backlight<=0) Backlight = 0;
    PWM_Back_WriteCompare(Backlight);
    CurrentBacklightValue = Backlight;
    sprintf((char *)CurrentBacklightValueString,"%d",Backlight);
    
    PWM_Back_WriteCompare(Backlight*25);
}

void SetVolume(uint8 VolumeValue){
    int Volume = VolumeValue;
    if(Volume>=10) Volume = 10;
    if(Volume<=0) Volume = 0;
    CurrentVolumeValue = Volume;
    sprintf((char *)CurrentVolumeValueString,"%d",Volume); 
    
    PWM_Buzz_WriteCompare(Volume*10);
}