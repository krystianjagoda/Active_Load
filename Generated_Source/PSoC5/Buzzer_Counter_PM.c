/*******************************************************************************
* File Name: Buzzer_Counter_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Buzzer_Counter.h"

static Buzzer_Counter_backupStruct Buzzer_Counter_backup;


/*******************************************************************************
* Function Name: Buzzer_Counter_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Buzzer_Counter_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Buzzer_Counter_SaveConfig(void) 
{
    #if (!Buzzer_Counter_UsingFixedFunction)

        Buzzer_Counter_backup.CounterUdb = Buzzer_Counter_ReadCounter();

        #if(!Buzzer_Counter_ControlRegRemoved)
            Buzzer_Counter_backup.CounterControlRegister = Buzzer_Counter_ReadControlRegister();
        #endif /* (!Buzzer_Counter_ControlRegRemoved) */

    #endif /* (!Buzzer_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Buzzer_Counter_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Buzzer_Counter_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Buzzer_Counter_RestoreConfig(void) 
{      
    #if (!Buzzer_Counter_UsingFixedFunction)

       Buzzer_Counter_WriteCounter(Buzzer_Counter_backup.CounterUdb);

        #if(!Buzzer_Counter_ControlRegRemoved)
            Buzzer_Counter_WriteControlRegister(Buzzer_Counter_backup.CounterControlRegister);
        #endif /* (!Buzzer_Counter_ControlRegRemoved) */

    #endif /* (!Buzzer_Counter_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Buzzer_Counter_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Buzzer_Counter_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Buzzer_Counter_Sleep(void) 
{
    #if(!Buzzer_Counter_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Buzzer_Counter_CTRL_ENABLE == (Buzzer_Counter_CONTROL & Buzzer_Counter_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Buzzer_Counter_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Buzzer_Counter_backup.CounterEnableState = 0u;
        }
    #else
        Buzzer_Counter_backup.CounterEnableState = 1u;
        if(Buzzer_Counter_backup.CounterEnableState != 0u)
        {
            Buzzer_Counter_backup.CounterEnableState = 0u;
        }
    #endif /* (!Buzzer_Counter_ControlRegRemoved) */
    
    Buzzer_Counter_Stop();
    Buzzer_Counter_SaveConfig();
}


/*******************************************************************************
* Function Name: Buzzer_Counter_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Buzzer_Counter_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Buzzer_Counter_Wakeup(void) 
{
    Buzzer_Counter_RestoreConfig();
    #if(!Buzzer_Counter_ControlRegRemoved)
        if(Buzzer_Counter_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Buzzer_Counter_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Buzzer_Counter_ControlRegRemoved) */
    
}


/* [] END OF FILE */
