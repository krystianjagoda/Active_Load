/*******************************************************************************
* File Name: ResistiveTouch_1_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ResistiveTouch_1.h"


/*******************************************************************************
* Function Name: ResistiveTouch_1_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the ADC configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_SaveConfig(void) 
{
    ResistiveTouch_1_ADC_SaveConfig();   
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the ADC configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void ResistiveTouch_1_RestoreConfig(void) 
{
    ResistiveTouch_1_ADC_RestoreConfig();  
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_Sleep(void) 
{
    ResistiveTouch_1_ADC_Sleep();
    ResistiveTouch_1_AMux_Stop();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_Wakeup(void)  
{
    ResistiveTouch_1_ADC_Wakeup();
}


/* [] END OF FILE */
