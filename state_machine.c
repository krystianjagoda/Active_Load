#include "state_machine.h"
#include "global_variables.h"
#include "LCD_Menu.h"
#include "temp_manage.h"


uint8 Temporary = 0;



uint16 DACValue = 0;
int16 Timer = 0;

uint32 Loop_Counter = 0;


int    Last_Counter = 0;
int    Current_Counter = 0;



int Testowy_Counter = 0;
char8 cTestowy_Counter[16u];

float SredniaC;
uint8 dtC = 40;

float SredniaV;
uint8 dtV = 100;

float SredniaP;
uint8 dtP = 10;


void State_Machine(){   
    switch(Current_State){
        case Home:
             State_Machine_Home();
        break;
    
        case ConstantMode:
             State_Machine_ConstantMode();  
        break;
            
        case ArbitraryMode:
             State_Machine_ArbitraryMode();  
        break;
            
        case ConstantCurrent:
             State_Machine_ConstantCurrent();  
        break;
            
        case ConstantPower:
            State_Machine_ConstantPower();
        break;
            
        case ConstantResistance:
            State_Machine_ConstantResistance();
        break;
            
        case WaveForm_Mode:
            State_Machine_WaveForm_Mode();
        break;
         
        case PWM_Mode:
            State_Machine_PWM_Mode();
        break;
            
        case External_Drive:
            State_Machine_External_Drive();
        break;
            
        case Settings:
             State_Machine_Settings();
        break;
            
        case BacklightSetting:
            State_Machine_BacklightSetting();
        break;
            
        case VolumeSetting:
            State_Machine_VolumeSetting();
        break;
            
        case Information:
            State_Machine_Information();  
        break;

        case Error_NC:
            State_Machine_Error_NC(); 
        break;
            
        case Error_OC:
            State_Machine_Error_OC(); 
        break;    
            
        case Error_OT:
            State_Machine_Error_OT(); 
        break;            
        
        case Error_OV:
            State_Machine_Error_OV(); 
        break;            
          
        case Error_RP:
            State_Machine_Error_RP(); 
        break;            
            
        case Develop:     
            
            MeasuredCurrent = ADC_SAR_2_GetResult16()-33;      
            fCurrent = ADC_SAR_2_CountsTo_Volts(MeasuredCurrent);
            sprintf((char *)cCurrent_Actual,"%f2.4",fCurrent);
                        
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  40, 12, cCurrent_Actual);               

            } while ( u8g_NextPage(&u8g) );
            
            if(!(button1 == 0)){    //Output Enable Button
                Buzzer_Shot(Push_Buzzer__Default_Lenght);
                RELAY_Write(1);
            }
            
        break;
            
        default:
        break;
    }
}


void State_Machine_Error_RP(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, 0);
        Loop_Counter = 0;
    }
    
    if((!(button1 == 0))||(!(button2 == 0))||(!(button3 == 0))||(!(button4 == 0))||
       (!(button5 == 0))||(!(button6 == 0))||(!(Push_Reg_Read() == 0))){
        Current_State = Previous_State;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}
void State_Machine_Error_NC(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, 0);
        Loop_Counter = 0;
    }
    
    if((!(button1 == 0))||(!(button2 == 0))||(!(button3 == 0))||(!(button4 == 0))||
       (!(button5 == 0))||(!(button6 == 0))||(!(Push_Reg_Read() == 0))){
        Current_State = Previous_State;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}
void State_Machine_Error_OC(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, 0);
        Loop_Counter = 0;
    }
    
    if((!(button1 == 0))||(!(button2 == 0))||(!(button3 == 0))||(!(button4 == 0))||
       (!(button5 == 0))||(!(button6 == 0))||(!(Push_Reg_Read() == 0))){
        Current_State = Previous_State;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}
void State_Machine_Error_OT(){
    
    OutputEnable = 0;
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, 0);
        Loop_Counter = 0;
    }
    
    if((!(button1 == 0))||(!(button2 == 0))||(!(button3 == 0))||(!(button4 == 0))||
       (!(button5 == 0))||(!(button6 == 0))||(!(Push_Reg_Read() == 0))){
        Current_State = Previous_State;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}
void State_Machine_Error_OV(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, 0);
        Loop_Counter = 0;
    }
    
    if((!(button1 == 0))||(!(button2 == 0))||(!(button3 == 0))||(!(button4 == 0))||
       (!(button5 == 0))||(!(button6 == 0))||(!(Push_Reg_Read() == 0))){
        Current_State = Previous_State;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}

void State_Machine_Home(){  
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, Get_Encoder_Menu(0,3));
        Loop_Counter = 0;
    }
    
    if(!(Push_Reg_Read() == 0)){
        if(Get_Encoder_Menu(0,3) == 3){
            QD_SetCounter(3);
            Current_State = ConstantMode;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 2){
            QD_SetCounter(3);
            Current_State = ArbitraryMode;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 0){   
            QD_SetCounter(3);
            Current_State = Settings;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }  
    }
}

void State_Machine_ConstantMode(){
    // Disable Output and Relay
    OutputEnable = 0;
    RELAY_Write(0);
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, Get_Encoder_Menu(0,3));
        Loop_Counter = 0;
    }
    
    if(!(Push_Reg_Read() == 0)){
        if(Get_Encoder_Menu(2,3) == 3){
            QD_SetCounter(3);
            Current_State = ConstantCurrent;
            Set_Current = 0.50;   // Initial Value
            Set_Current_Temporary_Value = 0.50;
            Position_Number = 1;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 2){
            QD_SetCounter(3);
            Current_State = ConstantPower;
            Set_Power = 10.50;   // Initial Value
            Set_Power_Temporary_Value = 10.50;
            Position_Number = 1;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 1){
            QD_SetCounter(3);
            Current_State = ConstantResistance;
            Set_Resist = 25.0;   // Initial Value
            Set_Resist_Temporary_Value = 25.0; 
            Position_Number = 1;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 0){ // Back
            QD_SetCounter(3);
            Current_State = Home;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
    }

    if(!(button4 == 0)){    //Back
        QD_SetCounter(3);
        Current_State = Home;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    
    
}

void State_Machine_ArbitraryMode(){
    // Disable Output and Relay
    OutputEnable = 0;
    RELAY_Write(0);
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, Get_Encoder_Menu(0,3));
        Loop_Counter = 0;
    }
        
    if(!(Push_Reg_Read() == 0)){
//        if(Get_Encoder_Menu(2,3) == 3){
//            QD_SetCounter(3);
//            Current_State = WaveForm_Mode;
//            Buzzer_Shot(Push_Buzzer__Default_Lenght);
//        }
        if(Get_Encoder_Menu(2,3) == 2){
            QD_SetCounter(3);
            Current_State = PWM_Mode;
            Set_Ampl = 1000;
            Set_Ampl_Temporary_Value = 1000;
            Set_Freq = 25000;
            Set_Freq_Temporary_Value = 25000;
            Set_Duty = 50;
            Set_Duty_Temporary_Value = 50;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        
        else if(Get_Encoder_Menu(0,3) == 0){ // Back
            QD_SetCounter(3);
            Current_State = Home;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
    }
    if(!(button4 == 0)){    //Back
        QD_SetCounter(3);
        Current_State = Home;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}

void State_Machine_WaveForm_Mode(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, Get_Encoder_Menu(0,3));
        Loop_Counter = 0;
    }
        
    if(!(button4 == 0)){    //Back
        QD_SetCounter(3);
        DAC_MUX_Select(0);   // GND
        OutputEnable = 0;
        RELAY_Write(0);
        Current_State = ArbitraryMode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
}



void State_Machine_PWM_Mode(){
    
    float MaxSetValue;
    
    LEM_A_Write(0);     //160 Ohm - Range 2
    LEM_B_Write(0);   //60 Ohm - Range 3
    CAP_EN_Write(1);    // Enable 10nF Cap

    
    // Secondary Loop Counter
    Loop_Counter++;
    
    // Output Enable Case
    if(OutputEnable == 1){
        
        if(!(Input_Reg_Read())){
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OC;
            Buzzer_Shot(500000);
        }
        else if(OverTemperature == 1){

            DACValue = 0;
            DVDAC8_1_SetValue(0); 
            DAC_MUX_Select(0);     
            
            // Disable Relay
            RELAY_Write(0);
            
            Buzzer_Shot(500000);
            
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OT;   
        } 
        else{       
            // Enable Relay if Input is OK
            RELAY_Write(1);
            
            
            DVDAC8_1_SetValue(Set_Ampl);
            
            DAC_MUX_Select(2);      // ConstantDAC
            PWM_Driver_Start();     //Start PWM
            
            PWM_Driver_WritePeriod(Set_Freq);
                        
            uint16 Actual_Period;
            Actual_Period = PWM_Driver_ReadPeriod();
            
            uint16 Duty_to_Set;
            Duty_to_Set = Actual_Period-(Set_Duty*Actual_Period/100);
            PWM_Driver_WriteCompare(Duty_to_Set);
            

        }
    }
    
    // Output Disable Case
    if(OutputEnable == 0){
        
        DACValue = 0;
        DVDAC8_1_SetValue(0); 
        DAC_MUX_Select(0);
        PWM_Driver_Stop();
        
        // Disable Relay
        RELAY_Write(0);
    }
    
        
    if(Edit_Value_Mode == 0){
        
    if(Loop_Counter >= 1000){
        sprintf((char *)cSet_Ampl,"%d mA",Set_Ampl);
        sprintf((char *)cSet_Freq,"%d Hz",Set_Freq);
        sprintf((char *)cSet_Duty,"%d %%",Set_Duty);
        
        LCD_Draw(Current_State, Get_Encoder_Menu(0,2));
        
        Loop_Counter = 0;
    }

        if(!(Push_Reg_Read() == 0)){
            Edit_Value_Mode = 1;
            if(Get_Encoder_Menu(0,3) == 2){
                Current_Edit_Value = 2; //Amp
                QD_SetCounter(Set_Ampl);
                Last_Counter = Set_Ampl;
                Position_Number = 1;
                
            }
            else if(Get_Encoder_Menu(0,3) == 1){
                Current_Edit_Value = 1; //Freq
                QD_SetCounter(Set_Freq);
                Last_Counter = Set_Freq;
                Position_Number = 1;
            }
            else if(Get_Encoder_Menu(0,3) == 0){   
                Current_Edit_Value = 0; //Duty
                QD_SetCounter(Set_Duty);
                Last_Counter = Set_Duty;
                Position_Number = 1;
            } 
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }   
 }
    
    if(Edit_Value_Mode == 1){
        
        if(Loop_Counter >= 1000){
            sprintf((char *)cSet_Ampl,"%d mA",Set_Ampl);
            sprintf((char *)cSet_Freq,"%d Hz",Set_Freq);
            sprintf((char *)cSet_Duty,"%d %%",Set_Duty);
            LCD_Draw(Current_State, Current_Edit_Value);
            Loop_Counter = 0;
        }

                               
        if(!(button6 == 0)){    // Shift Right Button
            Position_Number++;
            if(Current_Edit_Value == 2){        //Ampl
                if(Position_Number >2) Position_Number = 3;
            }
            else if(Current_Edit_Value == 1){    //Freq
                if(Position_Number >3) Position_Number = 4;
            }
            else if(Current_Edit_Value == 0){    //Duty
                if(Position_Number >1) Position_Number = 1;
            }
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        
        if(!(button5 == 0)){    // Shift Left Button
            Position_Number--;
            if(Position_Number <0) Position_Number = 0;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        
        
        if(Current_Edit_Value == 0){ //Duty           
            MaxSetValue = 100;
                        
            Current_Counter = QD_GetCounter();
            
            if(Position_Number == 0){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Duty_Temporary_Value = Set_Duty_Temporary_Value - 10;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Duty_Temporary_Value = Set_Duty_Temporary_Value + 10;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }        
            
            if(Position_Number == 1){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Duty_Temporary_Value = Set_Duty_Temporary_Value - 1;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Duty_Temporary_Value = Set_Duty_Temporary_Value + 1;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }

            if(Set_Duty_Temporary_Value > MaxSetValue){
                Set_Duty_Temporary_Value = MaxSetValue;
                Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
            }
            if(Set_Duty_Temporary_Value < 0){
                Set_Duty_Temporary_Value = 0;
                Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
            }
            Set_Duty = Set_Duty_Temporary_Value;  
        }   
        
        
        
        else if(Current_Edit_Value == 1){ //Freq          
            MaxSetValue = 50000;
                        
            Current_Counter = QD_GetCounter();
            
            if(Position_Number == 0){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value - 10000;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value + 10000;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }        
            
            if(Position_Number == 1){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value - 1000;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value + 1000;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }            
            if(Position_Number == 2){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value - 100;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value + 100;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }
            if(Position_Number == 3){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value - 10;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value + 10;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }
            if(Position_Number == 4){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value - 1;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Freq_Temporary_Value = Set_Freq_Temporary_Value + 1;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }
            

            if(Set_Freq_Temporary_Value > MaxSetValue){
                Set_Freq_Temporary_Value = MaxSetValue;
                Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
            }
            if(Set_Freq_Temporary_Value < 0){
                Set_Freq_Temporary_Value = 0;
                Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
            }
            Set_Freq = Set_Freq_Temporary_Value;  
        }  
        
        else if(Current_Edit_Value == 2){ //Ampl       
            MaxSetValue = 2000;
                        
            Current_Counter = QD_GetCounter();
            
            if(Position_Number == 0){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value - 1000;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value + 1000;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }        
            
            if(Position_Number == 1){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value - 100;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value + 100;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            }
            if(Position_Number == 2){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value - 10;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value + 10;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            } 
            if(Position_Number == 3){
                if(!(Last_Counter == Current_Counter)){
                    if(Last_Counter > Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value - 1;
                    }
                    if(Last_Counter < Current_Counter){
                        Set_Ampl_Temporary_Value = Set_Ampl_Temporary_Value + 1;
                    }
                    Last_Counter = Current_Counter;   
                    Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
                }      
            } 

            if(Set_Ampl_Temporary_Value > MaxSetValue){
                Set_Ampl_Temporary_Value = MaxSetValue;
                Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
            }
            if(Set_Ampl_Temporary_Value < 0){
                Set_Ampl_Temporary_Value = 0;
                Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
            }
            Set_Ampl = Set_Ampl_Temporary_Value;  
        } 
        
        
        // Encoder Push
        if(!(Push_Reg_Read() == 0)){
            Edit_Value_Mode = 0;
            QD_SetCounter(Current_Edit_Value);
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }  
        
    }
        
            
    if(!(button1 == 0)){    //Output Enable Button
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
        if(OutputEnable == 0){
            if(Check_Input() == 1){
                OutputEnable = 1;
            }
        }
        else OutputEnable = 0;
        Edit_Value_Mode = 0;      
    }
    
    
    if(!(button4 == 0)){    //Back
        QD_SetCounter(3);
        DAC_MUX_Select(0);   // GND
        OutputEnable = 0;
        RELAY_Write(0);
        PWM_Driver_Stop();     //Stop PWM
        Current_State = ArbitraryMode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
}


void State_Machine_External_Drive(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, Get_Encoder_Menu(0,3));
        Loop_Counter = 0;
    }
    
}


void State_Machine_ConstantCurrent(){
    
    CAP_EN_Write(1);    // Enable 10nF Cap
    PWM_Driver_Stop();     //Stop PWM
    
    float MaxSetValue = MaxCurrent;
           
    // Secondary Loop Counter
    Loop_Counter++;
    
     
    // Voltage, Current, Power Measurement and Calculations
    MeasuredVoltage = ADC_SAR_1_GetResult16();
    MeasuredCurrent = ADC_SAR_2_GetResult16() - LEM_Offset_Value;      
    
    if(Four_Wire_Method ==1){
        VOLTAGE_SELECT_Write(1);
        fVoltage = Four_Wire_Range*ADC_SAR_1_CountsTo_Volts(MeasuredVoltage); 
    }
    else{
        VOLTAGE_SELECT_Write(0);
        fVoltage = Two_Wire_Range*ADC_SAR_1_CountsTo_Volts(MeasuredVoltage);        
    }
    
    SredniaV = SredniaV*dtV;
    SredniaV = SredniaV + fVoltage;
    SredniaV = SredniaV / (dtV+1);
    fVoltage = SredniaV;
    
    
    
    if(Actual_Range == 1) fCurrent = Current_Calibration_Range1 * ADC_SAR_2_CountsTo_Volts(MeasuredCurrent);
//    else if (Actual_Range == 2) fCurrent = Current_Calibration_Range2*ADC_SAR_2_CountsTo_Volts(MeasuredCurrent);
//    else if (Actual_Range == 3) fCurrent = Current_Calibration_Range3*ADC_SAR_2_CountsTo_Volts(MeasuredCurrent);
    
    fPower = fVoltage*fCurrent;
    
    Set_Power = fVoltage*Set_Current;
    Set_Resist = fVoltage/Set_Current; 
    fResist = fVoltage/fCurrent;
    
    
    
    
    // Check for OverVoltage
    if(fVoltage > MaxVoltage){
        OutputEnable = 0;
        Previous_State = Current_State;
        Current_State = Error_OV;
        Buzzer_Shot(500000);
    }
    

    // Output Enable Case
    if(OutputEnable == 1){
        
        if(!(Input_Reg_Read())){
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OC;
            Buzzer_Shot(500000);
        }
        else if(OverTemperature == 1){

            DACValue = 0;
            DVDAC8_1_SetValue(0); 
            DAC_MUX_Select(0);     
            
            // Disable Relay
            RELAY_Write(0);
            
            Buzzer_Shot(500000);
            
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OT;   
        } 
        else{       
            // Enable Relay if Input is OK
            RELAY_Write(1);
                
            if(Loop_Counter >= 1000){
                sprintf((char *)cVoltage_Actual,"%2.2fV",fVoltage);
                sprintf((char *)cCurrent_Actual,"%2.2fA",fCurrent);
                sprintf((char *)cPower_Actual,"%3.2fW",fPower);
                sprintf((char *)cResist_Actual,"%4.1fohm",fResist);
                LCD_Draw(Current_State, Position_Number); 
                Loop_Counter = 0;
            }

            DAC_MUX_Select(2);   // ConstantDAC
            
            //Regulator
            if(Set_Current - fCurrent > 0.005){
                DACValue++;
                if(DACValue > 4080) DACValue = 4080;
                DVDAC8_1_SetValue(DACValue);                
            }
            else if(fCurrent - Set_Current > 0.005){
                DACValue--;
                if(DACValue <= 0){
                    DACValue = 0;
                    OutputEnable = 0;
                }
                DVDAC8_1_SetValue(DACValue);        
            }
        }
    }
    
    // Output Disable Case
    if(OutputEnable == 0){
        
        if(Loop_Counter >= 1000){
            sprintf((char *)cVoltage_Set,"%2.2fV",fVoltage);
            sprintf((char *)cCurrent_Set,"%2.2fA",Set_Current);            
            sprintf((char *)cPower_Set,"%2.2fW",Set_Power);
            sprintf((char *)cResist_Set,"%4.1fohm",Set_Resist);
            LCD_Draw(Current_State, Position_Number); 
            Loop_Counter = 0;
        }
        DACValue = 0;
        DVDAC8_1_SetValue(0); 
        DAC_MUX_Select(0);     
        
        // Disable Relay
        RELAY_Write(0);
    }
    
    
    // Encoder Control
    if(!(Push_Reg_Read() == 0)){
        Edit_Value_Mode = !Edit_Value_Mode;
        QD_SetCounter(Current_Counter);
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    

    if(Edit_Value_Mode == 1){ 
        Current_Counter = QD_GetCounter();
        
        if(Position_Number == 0){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Current_Temporary_Value = Set_Current_Temporary_Value - 1;
                }
                if(Last_Counter < Current_Counter){
                    Set_Current_Temporary_Value = Set_Current_Temporary_Value + 1;
                }
                Last_Counter = Current_Counter;   
                Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
            }      
        }        
        
        if(Position_Number == 1){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Current_Temporary_Value = Set_Current_Temporary_Value - 0.1;
                }
                if(Last_Counter < Current_Counter){
                    Set_Current_Temporary_Value = Set_Current_Temporary_Value + 0.1;
                }
                Last_Counter = Current_Counter;   
                Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
            }      
        }
        if(Position_Number == 2){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Current_Temporary_Value = Set_Current_Temporary_Value - 0.01;
                }
                if(Last_Counter < Current_Counter){
                    Set_Current_Temporary_Value = Set_Current_Temporary_Value + 0.01;
                }
                Last_Counter = Current_Counter;   
                Buzzer_Shot(Rotate_Buzzer__Default_Lenght);
            }      
        }
          
        if(Set_Current_Temporary_Value > MaxSetValue){
            Set_Current_Temporary_Value = MaxSetValue;
            Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
        }
        if(Set_Current_Temporary_Value < 0){
            OutputEnable = 0;
            Set_Current_Temporary_Value = 0;
            Buzzer_Shot(10*Rotate_Buzzer__Default_Lenght);
        }
        Set_Current = Set_Current_Temporary_Value;  
       
        
    }
 
    //Buttons Control
    if(!(button1 == 0)){    //Output Enable Button
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
        if(OutputEnable == 0){
            if(Check_Input() == 1){
                OutputEnable = 1;
            }
        }
        else OutputEnable = 0;
        Edit_Value_Mode = 0;      
    }
    
    if(!(button2 == 0)){    //Four/Two Wire Select
        Four_Wire_Method = !Four_Wire_Method;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    
    
    if(!(button3 == 0)){    //Four/Two Wire Select
        View_Mode = !View_Mode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
//        
//        Temporary = !Temporary;  
//        
//        if(Temporary == 1){
//            
//            DACValue = DACValue*2.5;
//            DVDAC8_1_SetValue(DACValue);
//            
//            LEM_A_Write(0);     //160 Ohm - Range 2
//            LEM_B_Write(0);   //60 Ohm - Range 3
//            
//
//           
//            Actual_Range = 1;       
//        }
//        else{
//            DACValue = DACValue/2.5;
//            DVDAC8_1_SetValue(DACValue);
//            
//            LEM_A_Write(1);     //160 Ohm - Range 2
//            //LEM_B_Write(1);   //60 Ohm - Range 3
//                        
//            Actual_Range = 2; 
//        }
//        
//        Buzzer_Shot(Push_Buzzer__Default_Lenght);
//    }  
    
    if(!(button4 == 0)){    //Back Button
        QD_SetCounter(3);
        OutputEnable = 0;
        Edit_Value_Mode = 0;
        Current_State = ConstantMode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    

    if(!(button6 == 0)){    // Shift Right Button
        Position_Number++;
        if(Position_Number >2) Position_Number = 2;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button5 == 0)){    // Shift Left Button
        Position_Number--;
        if(Position_Number <0) Position_Number = 0;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
 }

void State_Machine_ConstantPower(){
        
    
    
    CAP_EN_Write(1);    // Enable 10nF Cap
    PWM_Driver_Stop();     //Start PWM
    
    float MaxSetValue = MaxPower;
    
    // Secondary Loop Counter
    Loop_Counter++;
     
    
    // Voltage, Current, Power Measurement and Calculations
    
    MeasuredVoltage = ADC_SAR_1_GetResult16();   
    MeasuredCurrent = ADC_SAR_2_GetResult16();  
    
    if(Four_Wire_Method ==1){
        VOLTAGE_SELECT_Write(1);
        fVoltage = Four_Wire_Range*ADC_SAR_1_CountsTo_Volts(MeasuredVoltage); 
    }
    else{
        VOLTAGE_SELECT_Write(0);
        fVoltage = Two_Wire_Range*ADC_SAR_1_CountsTo_Volts(MeasuredVoltage);        
    }  
    
    SredniaV = SredniaV*dtV;
    SredniaV = SredniaV + fVoltage;
    SredniaV = SredniaV / (dtV+1);
    fVoltage = SredniaV;  
       
    if(Actual_Range == 1) fCurrent = Current_Calibration_Range1 * ADC_SAR_2_CountsTo_Volts(MeasuredCurrent);
    

    fPower = fVoltage*fCurrent;
    Set_Current = Set_Power/fVoltage;
            
    
    // Check for OverVoltage
    if(fVoltage > MaxVoltage){
        OutputEnable = 0;
        Previous_State = Current_State;
        Current_State = Error_OV;
        Buzzer_Shot(500000);
    }
    

    // Output Enable Case
    if(OutputEnable == 1){
        
        if(!(Input_Reg_Read())){
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OC;
            Buzzer_Shot(500000);
        }
        
        else if(OverTemperature == 1){

            DACValue = 0;
            DVDAC8_1_SetValue(0); 
            DAC_MUX_Select(0);     
            
            // Disable Relay
            RELAY_Write(0);
            
            Buzzer_Shot(500000);
            
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OT;   
        } 
        else{
        
            // Enable Relay if Input is OK
            RELAY_Write(1);
                
            if(Loop_Counter >= 1000){                             
                sprintf((char *)cVoltage_Actual,"%2.2fV",fVoltage);
                sprintf((char *)cCurrent_Actual,"%2.2fA",fCurrent);
                sprintf((char *)cPower_Actual,"%3.2fW",fPower);
                sprintf((char *)cResist_Actual,"%4.1fohm",fResist);
                
                LCD_Draw(Current_State, Position_Number); 
                Loop_Counter = 0;
            }

            DAC_MUX_Select(2);
            
            //Regulator
            if(Set_Power - fPower > 0.05){  // >=
                DACValue++;
                if(DACValue > 4080) DACValue = 4080;
                DVDAC8_1_SetValue(DACValue);                
            }
            else if(fPower - Set_Power > 0.05){
                DACValue--;
                if(DACValue <= 0){
                    DACValue = 0;
                    OutputEnable = 0;
                }
                DVDAC8_1_SetValue(DACValue);        
            }     
        }
    }
    
    // Output Disable Case
    if(OutputEnable == 0){
        
        if(Loop_Counter >= 1000){
            sprintf((char *)cVoltage_Set,"%2.2fV",fVoltage);
            sprintf((char *)cCurrent_Set,"%2.2fA",Set_Current);            
            sprintf((char *)cPower_Set,"%2.2fW",Set_Power);
            sprintf((char *)cResist_Set,"%4.1fohm",Set_Resist);
            LCD_Draw(Current_State, Position_Number); 
            Loop_Counter = 0;
        }
        DACValue = 0;
        DVDAC8_1_SetValue(0); 
        DAC_MUX_Select(0);     
        
        // Disable Relay
        RELAY_Write(0);
    }
    
    
    // Encoder Control
    if(!(Push_Reg_Read() == 0)){
        Edit_Value_Mode = !Edit_Value_Mode;
        QD_SetCounter(Current_Counter);
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    

    if(Edit_Value_Mode == 1){ 
        Current_Counter = QD_GetCounter();
        
        if(Position_Number == 0){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Power_Temporary_Value = Set_Power_Temporary_Value - 10;
                }
                if(Last_Counter < Current_Counter){
                    Set_Power_Temporary_Value = Set_Power_Temporary_Value + 10;
                }
                Last_Counter = Current_Counter;   
            }      
        }        
        
        if(Position_Number == 1){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Power_Temporary_Value = Set_Power_Temporary_Value - 1;
                }
                if(Last_Counter < Current_Counter){
                    Set_Power_Temporary_Value = Set_Power_Temporary_Value + 1;
                }
                Last_Counter = Current_Counter;   
            }      
        }
        if(Position_Number == 2){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Power_Temporary_Value = Set_Power_Temporary_Value - 0.1;
                }
                if(Last_Counter < Current_Counter){
                    Set_Power_Temporary_Value = Set_Power_Temporary_Value + 0.1;
                }
                Last_Counter = Current_Counter;   
            }      
        }
          
        if(Set_Power_Temporary_Value > MaxSetValue){
            Set_Power_Temporary_Value = MaxSetValue;
        }
        if(Set_Power_Temporary_Value < 0){
            OutputEnable = 0;
            Set_Power_Temporary_Value = 0;
        }
        Set_Power = Set_Power_Temporary_Value;  
    }
 
    //Buttons Control
    if(!(button1 == 0)){    //Output Enable Button
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
        if(OutputEnable == 0){
            if(Check_Input() == 1){
                OutputEnable = 1;
            }
        }
        else OutputEnable = 0;
        Edit_Value_Mode = 0;      
    }
    
    if(!(button2 == 0)){    //Four/Two Wire Select
        Four_Wire_Method = !Four_Wire_Method;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button3 == 0)){    //Four/Two Wire Select
        View_Mode = !View_Mode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button4 == 0)){    //Back Button
        QD_SetCounter(3);
        OutputEnable = 0;
        Edit_Value_Mode = 0;
        Current_State = ConstantMode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    

    if(!(button6 == 0)){    // Shift Right Button
        Position_Number++;
        if(Position_Number >2) Position_Number = 2;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button5 == 0)){    // Shift Left Button
        Position_Number--;
        if(Position_Number <0) Position_Number = 0;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
 }

void State_Machine_ConstantResistance(){
    
    
    
    CAP_EN_Write(1);    // Enable 10nF Cap
    PWM_Driver_Stop();     //Stop PWM
    
    float MaxSetValue = MaxResistance;
    float MinSetValue = MinResistance;
        
    
    // Secondary Loop Counter
    Loop_Counter++;
    
    
    // Voltage, Current, Power Measurement and Calculations
    
    MeasuredVoltage = ADC_SAR_1_GetResult16();   
    MeasuredCurrent = ADC_SAR_2_GetResult16();  
    
    if(Four_Wire_Method ==1){
        VOLTAGE_SELECT_Write(1);
        fVoltage = Four_Wire_Range*ADC_SAR_1_CountsTo_Volts(MeasuredVoltage); 
    }
    else{
        VOLTAGE_SELECT_Write(0);
        fVoltage = Two_Wire_Range*ADC_SAR_1_CountsTo_Volts(MeasuredVoltage);        
    } 
    
    SredniaV = SredniaV*dtV;
    SredniaV = SredniaV + fVoltage;
    SredniaV = SredniaV / (dtV+1);
    fVoltage = SredniaV;  
       
    if(Actual_Range == 1) fCurrent = Current_Calibration_Range1 * ADC_SAR_2_CountsTo_Volts(MeasuredCurrent);
    
//    fPower = fVoltage*fCurrent;
    
    fResist = fVoltage/fCurrent;     
    Set_Current = fVoltage/Set_Resist;
    Set_Power = fVoltage*fVoltage/Set_Resist;
    fPower = fVoltage*fCurrent;
    
    
        // Check for OverVoltage
    if(fVoltage > MaxVoltage){
        OutputEnable = 0;
        Previous_State = Current_State;
        Current_State = Error_OV;
        Buzzer_Shot(500000);
    }
    

    // Output Enable Case
    if(OutputEnable == 1){
        
        if(!(Input_Reg_Read())){
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OC;
            Buzzer_Shot(500000);
        }
        
        if(OverTemperature){
            OutputEnable = 0;
            Previous_State = Current_State;
            Current_State = Error_OT;
            
            DACValue = 0;
            DVDAC8_1_SetValue(0); 
            DAC_MUX_Select(0);     
            
            // Disable Relay
            RELAY_Write(0);
            
            Buzzer_Shot(500000);
        }
        
        // Enable Relay if Input is OK
        RELAY_Write(1);
            
        if(Loop_Counter >= 1000){
            sprintf((char *)cVoltage_Actual,"%2.2fV",fVoltage);
            sprintf((char *)cCurrent_Actual,"%2.2fA",fCurrent);
            sprintf((char *)cPower_Actual,"%3.2fW",fPower);
            sprintf((char *)cResist_Actual,"%4.1f",fResist);
            LCD_Draw(Current_State, Position_Number); 
            Loop_Counter = 0;
        }

        DAC_MUX_Select(2);
        
        //Regulator
        if(Set_Resist - fResist > 0.05){  // >=
            DACValue--;
            if(DACValue > 4080) DACValue = 4080;
            DVDAC8_1_SetValue(DACValue);                
        }
        else if(fResist - Set_Resist > 0.05){
            DACValue++;
            if(DACValue <= 0){
                DACValue = 0;
                OutputEnable = 0;
            }
            DVDAC8_1_SetValue(DACValue);        
        }     
    }
    
    // Output Disable Case
    if(OutputEnable == 0){
        
        if(Loop_Counter >= 1000){
            sprintf((char *)cVoltage_Actual,"%2.2fV",fVoltage);
            sprintf((char *)cCurrent_Set,"%2.2fA",Set_Current);            
            sprintf((char *)cPower_Set,"%2.2fW",Set_Power);
            sprintf((char *)cResist_Set,"%4.1f",Set_Resist);
            LCD_Draw(Current_State, Position_Number); 
            Loop_Counter = 0;
        }
        DACValue = 0;
        DVDAC8_1_SetValue(0); 
        DAC_MUX_Select(0);     
        
        // Disable Relay
        RELAY_Write(0);
    }
    
    
    // Encoder Control
    if(!(Push_Reg_Read() == 0)){
        Edit_Value_Mode = !Edit_Value_Mode;
        QD_SetCounter(Current_Counter);
    }
    

    if(Edit_Value_Mode == 1){ 
        Current_Counter = QD_GetCounter();
        
        if(Position_Number == 0){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value - 1000;
                }
                if(Last_Counter < Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value + 1000;
                }
                Last_Counter = Current_Counter;   
            }      
        }        
        
        if(Position_Number == 1){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value - 100;
                }
                if(Last_Counter < Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value + 100;
                }
                Last_Counter = Current_Counter;   
            }      
        }
        if(Position_Number == 2){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value - 10;
                }
                if(Last_Counter < Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value + 10;
                }
                Last_Counter = Current_Counter;   
            }      
        }
        if(Position_Number == 3){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value - 1;
                }
                if(Last_Counter < Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value + 1;
                }
                Last_Counter = Current_Counter;   
            }      
        }
        if(Position_Number == 4){
            if(!(Last_Counter == Current_Counter)){
                if(Last_Counter > Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value - 0.1;
                }
                if(Last_Counter < Current_Counter){
                    Set_Resist_Temporary_Value = Set_Resist_Temporary_Value + 0.1;
                }
                Last_Counter = Current_Counter;   
            }      
        }
        
          
        if(Set_Resist_Temporary_Value > MaxSetValue){
            Set_Resist_Temporary_Value = MaxSetValue;
        }
        if(Set_Resist_Temporary_Value < MinSetValue){
            OutputEnable = 0;
            Set_Resist_Temporary_Value = MinSetValue;
        }
        Set_Resist = Set_Resist_Temporary_Value;  
    }
 
    //Buttons Control
    if(!(button1 == 0)){    //Output Enable Button
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
        if(OutputEnable == 0){
            if(Check_Input() == 1){
                OutputEnable = 1;
            }
        }
        else OutputEnable = 0;
        Edit_Value_Mode = 0;      
    }
    
    if(!(button2 == 0)){    //Four/Two Wire Select
        Four_Wire_Method = !Four_Wire_Method;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button3 == 0)){    //Four/Two Wire Select
        View_Mode = !View_Mode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button4 == 0)){    //Back Button
        QD_SetCounter(3);
        OutputEnable = 0;
        Edit_Value_Mode = 0;
        Current_State = ConstantMode;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    

    if(!(button6 == 0)){    // Shift Right Button
        Position_Number++;
        if(Position_Number >4) Position_Number = 4;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button5 == 0)){    // Shift Left Button
        Position_Number--;
        if(Position_Number <0) Position_Number = 0;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
 }


void State_Machine_Settings(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        LCD_Draw(Current_State, Get_Encoder_Menu(0,3));
        Loop_Counter = 0;
    } 
    
    
    if(!(Push_Reg_Read() == 0)){
        if(Get_Encoder_Menu(0,3) == 3){
            QD_SetCounter(CurrentBacklightValue);
            Current_State = BacklightSetting;  
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 2){
            QD_SetCounter(CurrentVolumeValue);
            Current_State = VolumeSetting;  
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        }
        else if(Get_Encoder_Menu(0,3) == 1){
            QD_SetCounter(3);
            Current_State = Information;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        } 
        else if(Get_Encoder_Menu(0,3) == 0){
            QD_SetCounter(3);
            Current_State = Home;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
        } 
    }   
    if(!(button4 == 0)){    //Back
        QD_SetCounter(3);
        Current_State = Home;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}


void State_Machine_BacklightSetting(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        SetBacklight(Get_Encoder(11));
        LCD_Draw(Current_State, 3);
        Loop_Counter = 0;
    } 
    
    if(!(Push_Reg_Read() == 0)){
        QD_SetCounter(3);
        Current_State = Settings;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button1 == 0)){    //Back
        QD_SetCounter(3);
        Current_State = Settings;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
}

void State_Machine_VolumeSetting(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        SetVolume(Get_Encoder(11));
        LCD_Draw(Current_State, 2);
        Loop_Counter = 0;
    } 
    
    if(!(Push_Reg_Read() == 0)){
        QD_SetCounter(2);
        Current_State = Settings;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    
    if(!(button1 == 0)){    //Back
        QD_SetCounter(2);
        Current_State = Settings;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }    
}

void State_Machine_Information(){
    
    // Secondary Loop Counter
    Loop_Counter++;
    if(Loop_Counter >= 1000){
        TempRead_DIE();
        LCD_Draw(Current_State, 3);
        Loop_Counter = 0;
    } 
    
    if(!(Push_Reg_Read() == 0)){    //Back
            QD_SetCounter(1);
            Current_State = Settings;
            Buzzer_Shot(Push_Buzzer__Default_Lenght);
    }
    if(!(button4 == 0)){    //Back
        QD_SetCounter(1);
        Current_State = Settings;
        Buzzer_Shot(Push_Buzzer__Default_Lenght);
    } 
}