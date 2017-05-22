#include <device.h>
#include <stdio.h>

#define I2C_SLAVE_ADDRESS    0x48

void TempRead_FET(void);
void TempRead_DIE(void);
void FAN_Speed(uint8 Speed);
void Temp_Regulator(uint8 Set_Temp_Value, uint8 Actual_Temp_Value);
void Temp_Management(uint8 MaxTemp);


uint8 deltaT;
uint32 Avarage_FET_Temp;
int16 Current_DIE_Temp;
char8 Current_DIE_TempString[8u];
int8  Current_FET_Temp;
char8 Current_FET_TempString[8u];