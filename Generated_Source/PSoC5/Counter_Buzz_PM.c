/*******************************************************************************
* File Name: Counter_Buzz_PM.c  
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

#include "Counter_Buzz.h"

static Counter_Buzz_backupStruct Counter_Buzz_backup;


/*******************************************************************************
* Function Name: Counter_Buzz_SaveConfig
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
*  Counter_Buzz_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Counter_Buzz_SaveConfig(void) 
{
    #if (!Counter_Buzz_UsingFixedFunction)

        Counter_Buzz_backup.CounterUdb = Counter_Buzz_ReadCounter();

        #if(!Counter_Buzz_ControlRegRemoved)
            Counter_Buzz_backup.CounterControlRegister = Counter_Buzz_ReadControlRegister();
        #endif /* (!Counter_Buzz_ControlRegRemoved) */

    #endif /* (!Counter_Buzz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_Buzz_RestoreConfig
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
*  Counter_Buzz_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_Buzz_RestoreConfig(void) 
{      
    #if (!Counter_Buzz_UsingFixedFunction)

       Counter_Buzz_WriteCounter(Counter_Buzz_backup.CounterUdb);

        #if(!Counter_Buzz_ControlRegRemoved)
            Counter_Buzz_WriteControlRegister(Counter_Buzz_backup.CounterControlRegister);
        #endif /* (!Counter_Buzz_ControlRegRemoved) */

    #endif /* (!Counter_Buzz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Counter_Buzz_Sleep
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
*  Counter_Buzz_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Counter_Buzz_Sleep(void) 
{
    #if(!Counter_Buzz_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Counter_Buzz_CTRL_ENABLE == (Counter_Buzz_CONTROL & Counter_Buzz_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Counter_Buzz_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Counter_Buzz_backup.CounterEnableState = 0u;
        }
    #else
        Counter_Buzz_backup.CounterEnableState = 1u;
        if(Counter_Buzz_backup.CounterEnableState != 0u)
        {
            Counter_Buzz_backup.CounterEnableState = 0u;
        }
    #endif /* (!Counter_Buzz_ControlRegRemoved) */
    
    Counter_Buzz_Stop();
    Counter_Buzz_SaveConfig();
}


/*******************************************************************************
* Function Name: Counter_Buzz_Wakeup
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
*  Counter_Buzz_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Counter_Buzz_Wakeup(void) 
{
    Counter_Buzz_RestoreConfig();
    #if(!Counter_Buzz_ControlRegRemoved)
        if(Counter_Buzz_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Counter_Buzz_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Counter_Buzz_ControlRegRemoved) */
    
}


/* [] END OF FILE */
