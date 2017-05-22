#include "temp_manage.h"
#include "global_variables.h"
#include "state_machine.h"


cystatus Status;


void Temp_Management(uint8 MaxTemp){
    TempRead_FET();
    if(Current_FET_Temp == 0){
        OverTemperature = 1;  
    }
    else if(Current_FET_Temp >= MaxTemp){
        OverTemperature = 1;
    }
    else OverTemperature = 0;

    Temp_Regulator(MaxTemp-20, Current_FET_Temp);
    
}


void TempRead_FET(void){
        deltaT = 10;
        Status = I2C_MasterSendStart(I2C_SLAVE_ADDRESS, I2C_READ_XFER_MODE);
        if(I2C_MSTR_NO_ERROR == Status) /* Check if transfer completed without errors */
        Current_FET_Temp = I2C_MasterReadByte(I2C_NAK_DATA);
        I2C_MasterSendStop(); /* Send Stop */
        
        Avarage_FET_Temp = Avarage_FET_Temp*deltaT;
        Avarage_FET_Temp = Avarage_FET_Temp + Current_FET_Temp;
        Avarage_FET_Temp = Avarage_FET_Temp / (deltaT+1);
        Current_FET_Temp = Avarage_FET_Temp;
        
        sprintf((char *)Current_FET_TempString,"%d C",Current_FET_Temp); 
}

void TempRead_DIE(void){  
    Status = DieTemp_GetTemp(&Current_DIE_Temp);
    sprintf((char *)Current_DIE_TempString,"%d C",Current_DIE_Temp); 
}

void FAN_Speed(uint8 Speed){    
    if(Speed == 0){
        PWM_Fan_Stop();
    }
    else{
        PWM_Fan_Start();
        PWM_Fan_WriteCompare(Speed);
    }
}

void Temp_Regulator(uint8 Set_Temp_Value, uint8 Actual_Temp_Value){
    
    uint16 Hist = 2;
    uint8 K = 30;
    
    int16  Error = Actual_Temp_Value - Set_Temp_Value;
    
    if(Error < Hist) Error = 0;
    if(Error > 255) Error = 255;
    
    uint16 Drive = Error*K;
    
    if(Drive >255) Drive = 255;
    if(Drive <35) Drive = 0;
    
    FAN_Speed(Drive);        
}