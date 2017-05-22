#include "LCD_Menu.h"
#include "global_variables.h"
#include "u8g_arm.h"
#include "temp_manage.h"

void LCD_Draw(uint8 PageName, uint8 Current_Menu_Position){

    enum State PageNamee;
    PageNamee = PageName;
    
    switch(PageNamee){
        
    case Error_OV:
        u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  40, 12, "Error!");
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  2, 28, "Over Voltage!");
                
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  4, 60, ">Press any key<");                

            } while ( u8g_NextPage(&u8g) );
      break;
        
        case Error_RP:
        u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  40, 12, "Error!");
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  2, 28, "Rev Polarity!");
                
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  4, 60, ">Press any key<");                

            } while ( u8g_NextPage(&u8g) );
      break;        
        
        case Error_OT:
        u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  40, 12, "Error!");
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  2, 28, "Over Heat!");
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  2, 43, Current_DIE_TempString);
                
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  4, 60, ">Press any key<");                

            } while ( u8g_NextPage(&u8g) );
      break;
        
        case Error_NC:
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  40, 12, "Error!");
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  2, 28, "No Supply!");
                
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  4, 60, ">Press any key<");                

            } while ( u8g_NextPage(&u8g) );
      break;
            
       case Error_OC:
        u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  40, 12, "Error!");
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  2, 28, "Over Current!");
                
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  4, 60, ">Press any key<");                

            } while ( u8g_NextPage(&u8g) );
      break;
        
      case Develop:
        u8g_FirstPage(&u8g);
        do{
            u8g_SetDefaultForegroundColor(&u8g);         
            
            u8g_SetFont(&u8g, u8g_font_unifont);   
            u8g_DrawStr(&u8g,  2, 13, cCounter);
                       
            u8g_SetFont(&u8g, u8g_font_unifont);              
            u8g_DrawStr(&u8g,  2, 29, "Arbitrary Mode");
            
            u8g_SetFont(&u8g, u8g_font_unifont);              
            u8g_DrawStr(&u8g,  2, 45, "Bat Discharge");
            
            u8g_SetFont(&u8g, u8g_font_unifont);              
            u8g_DrawStr(&u8g,  2, 60, "Settings");
            
        } while ( u8g_NextPage(&u8g) );
      break;
   
      case Home: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 3){
                    u8g_DrawBox(&u8g, 0,0,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }             
                
                u8g_SetFont(&u8g, u8g_font_unifont);   
                u8g_DrawStr(&u8g,  2, 13, "Constant Mode");
                
                u8g_SetDefaultForegroundColor(&u8g);                
                if(Current_Menu_Position == 2){
                    u8g_DrawBox(&u8g, 0,16,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "Function Mode");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 1){
                    u8g_DrawBox(&u8g, 0,32,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "Bat Discharge");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){
                    u8g_DrawBox(&u8g, 0,48,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "Settings");
                
            } while ( u8g_NextPage(&u8g) );
      break;
     
      case ConstantMode: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 3){
                    u8g_DrawBox(&u8g, 0,0,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }             
                
                u8g_SetFont(&u8g, u8g_font_unifont);   
                u8g_DrawStr(&u8g,  2, 13, "Const Current");
                
                u8g_SetDefaultForegroundColor(&u8g);                
                if(Current_Menu_Position == 2){
                    u8g_DrawBox(&u8g, 0,16,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "Const Power");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 1){
                    u8g_DrawBox(&u8g, 0,32,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "Const Resist");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){
                    u8g_DrawBox(&u8g, 0,48,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "          <-Back");
                
                
                
            } while ( u8g_NextPage(&u8g) );
        
      break;

      case ArbitraryMode: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 3){
                    u8g_DrawBox(&u8g, 0,0,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }             
                
                u8g_SetFont(&u8g, u8g_font_unifont);   
                u8g_DrawStr(&u8g,  2, 13, "Waveform Mode");
                
                u8g_SetDefaultForegroundColor(&u8g);                
                if(Current_Menu_Position == 2){
                    u8g_DrawBox(&u8g, 0,16,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "PWM Mode");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 1){
                    u8g_DrawBox(&u8g, 0,32,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "External Drive");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){
                    u8g_DrawBox(&u8g, 0,48,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "          <-Back");
                
            } while ( u8g_NextPage(&u8g) );
        
      break;
            
      case WaveForm_Mode: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  30, 12, "WaveForm_Mode");

            } while ( u8g_NextPage(&u8g) ); 
      break;
            
            
      case PWM_Mode: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 2){
                    if(Edit_Value_Mode == 0){
                        u8g_DrawBox(&u8g, 0,0,128,16);
                    }
                    if(Edit_Value_Mode == 1){
                        u8g_DrawBox(&u8g, 43,0,128,16);
                    }
                    u8g_SetDefaultBackgroundColor(&u8g);
                }             
                u8g_SetFont(&u8g, u8g_font_unifont);
                
                if(Set_Ampl <10)                u8g_DrawStr(&u8g,  82, 13, cSet_Ampl);
                else if(Set_Ampl <100)          u8g_DrawStr(&u8g,  74, 13, cSet_Ampl);
                else if(Set_Ampl <1000)         u8g_DrawStr(&u8g,  66, 13, cSet_Ampl);
                else                            u8g_DrawStr(&u8g,  58, 13, cSet_Ampl);
                
                
                if(Current_Menu_Position == 2 && Edit_Value_Mode == 1){
                    u8g_SetDefaultForegroundColor(&u8g);
                }
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  2, 13, "Ampl:");
                
                if(Current_Menu_Position == 2 && Edit_Value_Mode == 1){ 
                        
                        uint8 Underline;
                    
                        u8g_SetDefaultBackgroundColor(&u8g);
                        
                        if(Position_Number == 0) Underline = 59;
                        else if(Position_Number == 1) Underline = 67;
                        else if(Position_Number == 2) Underline = 75;
                        else if(Position_Number == 3) Underline = 83;
                        else Underline = 59;
                        
                        u8g_DrawLine(&u8g,Underline,14,Underline+5,14);
                }
                
                
                
                
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 1){
                    if(Edit_Value_Mode == 0){
                        u8g_DrawBox(&u8g, 0,16,128,16);
                    }
                    if(Edit_Value_Mode == 1){
                        u8g_DrawBox(&u8g, 43,16,128,16);
                    }
                    u8g_SetDefaultBackgroundColor(&u8g);     
                }

                u8g_SetFont(&u8g, u8g_font_unifont);
                if(Set_Freq <10)                u8g_DrawStr(&u8g,  82, 29, cSet_Freq);
                else if(Set_Freq <100)          u8g_DrawStr(&u8g,  74, 29, cSet_Freq);
                else if(Set_Freq <1000)         u8g_DrawStr(&u8g,  66, 29, cSet_Freq);
                else if(Set_Freq <10000)        u8g_DrawStr(&u8g,  58, 29, cSet_Freq);               
                else                            u8g_DrawStr(&u8g,  50, 29, cSet_Freq);
                if(Current_Menu_Position == 1 && Edit_Value_Mode == 1){
                    u8g_SetDefaultForegroundColor(&u8g);
                }
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "Freq:");
                
                
                if(Current_Menu_Position == 1 && Edit_Value_Mode == 1){ 
                        
                    uint8 Underline;
                
                    u8g_SetDefaultBackgroundColor(&u8g);
                    
                    if(Position_Number == 0) Underline = 51;
                    else if(Position_Number == 1) Underline = 59;
                    else if(Position_Number == 2) Underline = 67;
                    else if(Position_Number == 3) Underline = 75;
                    else if(Position_Number == 4) Underline = 83;
                    else Underline = 51;
                    
                    u8g_DrawLine(&u8g,Underline,30,Underline+5,30);
                }
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){                    
                    if(Edit_Value_Mode == 0){
                        u8g_DrawBox(&u8g, 0,32,128,16);
                    }
                    if(Edit_Value_Mode == 1){
                        u8g_DrawBox(&u8g, 43,32,128,16);
                                               
                    }
                    
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                u8g_SetFont(&u8g, u8g_font_unifont);
                if(Set_Duty <10)        u8g_DrawStr(&u8g,  82, 45, cSet_Duty);
                if(Set_Duty <100)       u8g_DrawStr(&u8g,  74, 45, cSet_Duty);
                else                    u8g_DrawStr(&u8g,  66, 45, cSet_Duty);
                
                if(Current_Menu_Position == 0 && Edit_Value_Mode == 1){
                    u8g_SetDefaultForegroundColor(&u8g);
                }
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "Duty:");
                
                if(Current_Menu_Position == 0 && Edit_Value_Mode == 1){ 
                        
                    uint8 Underline;
                
                    u8g_SetDefaultBackgroundColor(&u8g);
                    
                    if(Position_Number == 0) Underline = 75;
                    else if(Position_Number == 1) Underline = 83;
                    else Underline = 59;
                    
                    u8g_DrawLine(&u8g,Underline,46,Underline+5,46);
                }
               
                
                u8g_SetDefaultForegroundColor(&u8g);   
                
                u8g_DrawBox(&u8g, 0,51,128,16);
                u8g_SetDefaultBackgroundColor(&u8g);
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawLine(&u8g,32,52,32,62); 
                u8g_DrawLine(&u8g,64,52,64,62);   
                u8g_DrawLine(&u8g,96,52,96,62);
                
                if(OutputEnable == 0){
                    u8g_DrawTriangle(&u8g, 11+3,51, 17+3,57, 11+3,63);
                }
                if(OutputEnable == 1){
                    u8g_DrawLine(&u8g,14,53,14,61);
                    u8g_DrawLine(&u8g,15,53,15,61); 
                    
                    u8g_DrawLine(&u8g,17,53,17,61); 
                    u8g_DrawLine(&u8g,18,53,18,61);   
                }
                
                if(Edit_Value_Mode == 0){  
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  37, 62, "set");
                }
                else if(Edit_Value_Mode == 1){  
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  41, 62, "ok");
                }
                
                u8g_DrawLine(&u8g,117,54,117,60-1);
                u8g_DrawLine(&u8g,109,60-1,117,60-1);
                u8g_DrawTriangle(&u8g, 112,57-1, 107,60-1, 112,63-1);
                
            } while ( u8g_NextPage(&u8g) );
      break;
            
      case External_Drive: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);         
                u8g_SetFont(&u8g, u8g_font_unifont);                
                u8g_DrawStr(&u8g,  30, 12, "External_Drive");

            } while ( u8g_NextPage(&u8g) ); 
      break;            
            
            

        case VolumeSetting: 
            u8g_FirstPage(&u8g);
            do{
                                
                u8g_SetDefaultForegroundColor(&u8g);       
                
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  2, 13, "Backlight");
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  96, 13, CurrentBacklightValueString);
                
                
                u8g_SetDefaultForegroundColor(&u8g);   

                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "Volume:");
                
                u8g_DrawBox(&u8g, 88,16,44,16);
                u8g_SetDefaultBackgroundColor(&u8g);
                
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  96, 29, CurrentVolumeValueString);
                
                u8g_SetDefaultForegroundColor(&u8g);   
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "Temperature");
                
                u8g_SetDefaultForegroundColor(&u8g);   
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "          <-Back");
                
            } while ( u8g_NextPage(&u8g) );
      break; 
            
            
      case BacklightSetting: 
            u8g_FirstPage(&u8g);
            do{
                                
                u8g_SetDefaultForegroundColor(&u8g);       
                
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  2, 13, "Backlight");
                
                u8g_DrawBox(&u8g, 88,0,44,16);
                u8g_SetDefaultBackgroundColor(&u8g);
                
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  96, 13, CurrentBacklightValueString);
                
                u8g_SetDefaultForegroundColor(&u8g);   

                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "Volume:");
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  96, 29, CurrentVolumeValueString);
                
                u8g_SetDefaultForegroundColor(&u8g);   
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "Temperature");
                
                u8g_SetDefaultForegroundColor(&u8g);   
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "          <-Back");
                
            } while ( u8g_NextPage(&u8g) );
      break;           
            
      case Settings: 
            u8g_FirstPage(&u8g);
            do{
                                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 3){
                    u8g_DrawBox(&u8g, 0,0,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }             
                
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  2, 13, "Backlight");
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  96, 13, CurrentBacklightValueString);
                
                
                u8g_SetDefaultForegroundColor(&u8g);                
                if(Current_Menu_Position == 2){
                    u8g_DrawBox(&u8g, 0,16,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "Volume");
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  96, 29, CurrentVolumeValueString);
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 1){
                    u8g_DrawBox(&u8g, 0,32,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "Temperature");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){
                    u8g_DrawBox(&u8g, 0,48,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "          <-Back");
                
            } while ( u8g_NextPage(&u8g) );
      break;    
            
      case Information: 
            u8g_FirstPage(&u8g);
            do{
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){
                    u8g_DrawBox(&u8g, 0,0,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }             
                
                u8g_SetFont(&u8g, u8g_font_unifont);   
                u8g_DrawStr(&u8g,  2, 13, "DIE Temp");
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  90, 13, Current_DIE_TempString);
                
                u8g_SetDefaultForegroundColor(&u8g);                
                if(Current_Menu_Position == 2){
                    u8g_DrawBox(&u8g, 0,16,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 29, "FET Temp");
                u8g_SetFont(&u8g, u8g_font_unifont);
                u8g_DrawStr(&u8g,  90, 29, Current_FET_TempString);
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 0){
                    u8g_DrawBox(&u8g, 0,32,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 45, "INT Temp   N/C");
                
                u8g_SetDefaultForegroundColor(&u8g);
                if(Current_Menu_Position == 3){
                    u8g_DrawBox(&u8g, 0,48,128,16);
                    u8g_SetDefaultBackgroundColor(&u8g);
                }
                
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  2, 60, "          <-Back");
                
            } while ( u8g_NextPage(&u8g) );
      break;

        case ConstantResistance:
            
            u8g_FirstPage(&u8g);
            do{    
                
                int8 LocalMove = 22;
                
                u8g_SetDefaultForegroundColor(&u8g);    
                                
                if(OutputEnable == 0){
                    if(Set_Resist < 1){                       
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  31+LocalMove, 26, cResist_Set);
                    }
                    else if(Set_Resist < 10){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  24+LocalMove, 26, cResist_Set); 
                    }
                    else if(Set_Resist < 100){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  17+LocalMove, 26, cResist_Set); 
                    }
                    else if(Set_Resist < 1000){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  2+LocalMove, 26, cResist_Set); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  -13+LocalMove, 26, cResist_Set); 
                    }
                            
                    
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  97, 26, "Ohm");
                    
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  4, 43, cVoltage_Actual);
                    
                    if(View_Mode == 0){
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cCurrent_Set); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cPower_Set);
                    }
                    
                    if(Edit_Value_Mode == 1){                        
                        uint8 Underline;
                        if(Current_Menu_Position == 0) Underline = -12+LocalMove;
                        else if(Current_Menu_Position == 1) Underline = 3+LocalMove;
                        else if(Current_Menu_Position == 2) Underline = 18+LocalMove;
                        else if(Current_Menu_Position == 3) Underline = 35+LocalMove;
                        else if(Current_Menu_Position == 4) Underline = 58+LocalMove;
                        else Underline = 50+LocalMove;
                        u8g_DrawLine(&u8g,Underline,27,Underline+12,27);
                        u8g_DrawLine(&u8g,Underline,28,Underline+12,28);
                    }
                }
                
                else if(OutputEnable == 1){
                    if(fResist < 1){                       
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  31+LocalMove, 26, cResist_Actual);
                    }
                    else if(fResist < 10){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  24+LocalMove, 26, cResist_Actual); 
                    }
                    else if(fResist < 100){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  17+LocalMove, 26, cResist_Actual); 
                    }
                    else if(fResist < 1000){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  2+LocalMove, 26, cResist_Actual); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  -13+LocalMove, 26, cResist_Actual); 
                    }
                    
                   
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  96, 26, "Ohm");
                                   
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  4, 43, cVoltage_Actual);
                    
                    if(View_Mode == 0){                        
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cCurrent_Actual);
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cPower_Actual);
                    }
                    
                    if(Edit_Value_Mode == 1){                        
                        uint8 Underline;
                        if(Current_Menu_Position == 0) Underline = -12+LocalMove;
                        else if(Current_Menu_Position == 1) Underline = 3+LocalMove;
                        else if(Current_Menu_Position == 2) Underline = 18+LocalMove;
                        else if(Current_Menu_Position == 3) Underline = 35+LocalMove;
                        else if(Current_Menu_Position == 4) Underline = 58+LocalMove;
                        else Underline = 50+LocalMove;
                        u8g_DrawLine(&u8g,Underline,27,Underline+12,27);
                        u8g_DrawLine(&u8g,Underline,28,Underline+12,28);                    
                    }
                }

                
                
                
                u8g_DrawBox(&u8g, 0,51,128,16);
                u8g_SetDefaultBackgroundColor(&u8g);
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawLine(&u8g,32,52,32,62); 
                u8g_DrawLine(&u8g,64,52,64,62);   
                u8g_DrawLine(&u8g,96,52,96,62);
                
                if(OutputEnable == 0){
                    u8g_DrawTriangle(&u8g, 11+3,51, 17+3,57, 11+3,63);
                }
                if(OutputEnable == 1){
                    u8g_DrawLine(&u8g,14,53,14,61);
                    u8g_DrawLine(&u8g,15,53,15,61); 
                    
                    u8g_DrawLine(&u8g,17,53,17,61); 
                    u8g_DrawLine(&u8g,18,53,18,61);   
                }
                
                if(Four_Wire_Method == 0){  
                u8g_SetFont(&u8g, u8g_font_unifont);      

                u8g_DrawStr(&u8g,  41, 62, "2W");
                }
                else if(Four_Wire_Method == 1){  
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  41, 62, "4W");
                }
                
                u8g_DrawLine(&u8g,117,54,117,60-1);
                u8g_DrawLine(&u8g,109,60-1,117,60-1);
                u8g_DrawTriangle(&u8g, 112,57-1, 107,60-1, 112,63-1);
                
                u8g_SetFont(&u8g, u8g_font_unifont_77);              
                u8g_DrawStr(&u8g,  73, 62, "`");
                
            } while ( u8g_NextPage(&u8g) );
        break;                           
            
            
        case ConstantPower:            
            
            u8g_FirstPage(&u8g);
            do{    
                
                int8 LocalMove = 14;
                
                u8g_SetDefaultForegroundColor(&u8g);    
                                
                if(OutputEnable == 0){
                    if(Set_Power < 10.00){                       
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  28+LocalMove, 26, cPower_Set);
                    }
                    else if(Set_Power < 100.00){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  9+LocalMove, 26, cPower_Set); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  -6+LocalMove, 26, cPower_Set); 
                    }
                                 
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  4, 43, cVoltage_Set);
                    
                    if(View_Mode == 0){
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cCurrent_Set); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cResist_Set);
                    }
                    
                    if(Edit_Value_Mode == 1){                        
                        uint8 Underline;
                        if(Current_Menu_Position == 0) Underline = 10+LocalMove;
                        else if(Current_Menu_Position == 1) Underline = 26+LocalMove;
                        else if(Current_Menu_Position == 2) Underline = 50+LocalMove;
                        else Underline = 50+LocalMove;
                        u8g_DrawLine(&u8g,Underline,27,Underline+12,27);
                        u8g_DrawLine(&u8g,Underline,28,Underline+12,28);
                    }
                }
                
                else if(OutputEnable == 1){
                    if(fPower < 10.00){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  28+LocalMove, 26, cPower_Actual);
                    }
                    else if (fPower < 100.00){
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  9+LocalMove, 26, cPower_Actual); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_fub20);   
                        u8g_DrawStr(&u8g,  -6+LocalMove, 26, cPower_Actual); 
                    }
                    
                                   
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  4, 43, cVoltage_Actual);
                    
                    if(View_Mode == 0){                        
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cCurrent_Actual);
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cResist_Actual);
                    }
                    
                    if(Edit_Value_Mode == 1){                        
                        uint8 Underline;
                        if(Current_Menu_Position == 0) Underline = 10+LocalMove;
                        else if(Current_Menu_Position == 1) Underline = 26+LocalMove;
                        else if(Current_Menu_Position == 2) Underline = 50*LocalMove;
                        else Underline = 50+LocalMove;
                        u8g_DrawLine(&u8g,Underline,27,Underline+12,27);
                        u8g_DrawLine(&u8g,Underline,28,Underline+12,28);
                    }
                }

                
                
                
                u8g_DrawBox(&u8g, 0,51,128,16);
                u8g_SetDefaultBackgroundColor(&u8g);
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawLine(&u8g,32,52,32,62); 
                u8g_DrawLine(&u8g,64,52,64,62);   
                u8g_DrawLine(&u8g,96,52,96,62);
                
                if(OutputEnable == 0){
                    u8g_DrawTriangle(&u8g, 11+3,51, 17+3,57, 11+3,63);
                }
                if(OutputEnable == 1){
                    u8g_DrawLine(&u8g,14,53,14,61);
                    u8g_DrawLine(&u8g,15,53,15,61); 
                    
                    u8g_DrawLine(&u8g,17,53,17,61); 
                    u8g_DrawLine(&u8g,18,53,18,61);   
                }
                
                if(Four_Wire_Method == 0){  
                u8g_SetFont(&u8g, u8g_font_unifont);      

                u8g_DrawStr(&u8g,  41, 62, "2W");
                }
                else if(Four_Wire_Method == 1){  
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  41, 62, "4W");
                }
                
                u8g_DrawLine(&u8g,117,54,117,60-1);
                u8g_DrawLine(&u8g,109,60-1,117,60-1);
                u8g_DrawTriangle(&u8g, 112,57-1, 107,60-1, 112,63-1);
                
                u8g_SetFont(&u8g, u8g_font_unifont_77);              
                u8g_DrawStr(&u8g,  73, 62, "`");
                
            } while ( u8g_NextPage(&u8g) );
        break;      
            
                       
            
        case ConstantCurrent: 
            u8g_FirstPage(&u8g);
            do{    
                
                u8g_SetDefaultForegroundColor(&u8g);    
                               
                if(OutputEnable == 0){
                    u8g_SetFont(&u8g, u8g_font_fub20);   
                    u8g_DrawStr(&u8g,  24, 26, cCurrent_Set);
                                   
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  4, 43, cVoltage_Set);
                    
                    if(View_Mode == 0){                        
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cPower_Set); 
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cResist_Set); 
                    }
                    
                    if(Edit_Value_Mode == 1){                        
                        uint8 Underline;
                        if(Current_Menu_Position == 0) Underline = 26;
                        else if(Current_Menu_Position == 1) Underline = 50;
                        else if(Current_Menu_Position == 2) Underline = 64;
                        else Underline = 50;
                        u8g_DrawLine(&u8g,Underline,27,Underline+12,27);
                        u8g_DrawLine(&u8g,Underline,28,Underline+12,28);
                    }
                }
                
                else if(OutputEnable == 1){
                    u8g_SetFont(&u8g, u8g_font_fub20);   
                    u8g_DrawStr(&u8g,  24, 26, cCurrent_Actual);
                                   
                    u8g_SetFont(&u8g, u8g_font_unifont);              
                    u8g_DrawStr(&u8g,  4, 43, cVoltage_Actual);
                    
                    if(View_Mode == 0){
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cPower_Actual);
                    }
                    else{
                        u8g_SetFont(&u8g, u8g_font_unifont);              
                        u8g_DrawStr(&u8g,  64, 43, cResist_Actual);                       
                    }
                    
                    if(Edit_Value_Mode == 1){                        
                        uint8 Underline;
                        if(Current_Menu_Position == 0) Underline = 26;
                        else if(Current_Menu_Position == 1) Underline = 50;
                        else if(Current_Menu_Position == 2) Underline = 64;
                        else Underline = 50;
                        u8g_DrawLine(&u8g,Underline,27,Underline+12,27);
                        u8g_DrawLine(&u8g,Underline,28,Underline+12,28);
                    }
                }

                
                
                
                u8g_DrawBox(&u8g, 0,51,128,16);
                u8g_SetDefaultBackgroundColor(&u8g);
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawLine(&u8g,32,52,32,62); 
                u8g_DrawLine(&u8g,64,52,64,62);   
                u8g_DrawLine(&u8g,96,52,96,62);
                
                if(OutputEnable == 0){
                    u8g_DrawTriangle(&u8g, 11+3,51, 17+3,57, 11+3,63);
                }
                if(OutputEnable == 1){
                    u8g_DrawLine(&u8g,14,53,14,61);
                    u8g_DrawLine(&u8g,15,53,15,61); 
                    
                    u8g_DrawLine(&u8g,17,53,17,61); 
                    u8g_DrawLine(&u8g,18,53,18,61);   
                }
                
                if(Four_Wire_Method == 0){  
                u8g_SetFont(&u8g, u8g_font_unifont);      

                u8g_DrawStr(&u8g,  41, 62, "2W");
                }
                else if(Four_Wire_Method == 1){  
                u8g_SetFont(&u8g, u8g_font_unifont);              
                u8g_DrawStr(&u8g,  41, 62, "4W");
                }
                
                u8g_DrawLine(&u8g,117,54,117,60-1);
                u8g_DrawLine(&u8g,109,60-1,117,60-1);
                u8g_DrawTriangle(&u8g, 112,57-1, 107,60-1, 112,63-1);
                
                u8g_SetFont(&u8g, u8g_font_unifont_77);              
                u8g_DrawStr(&u8g,  73, 62, "`");
                
            } while ( u8g_NextPage(&u8g) );
        
      break;            

            
      // ...
     
      default:
        break;
    }   
}