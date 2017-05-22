/*******************************************************************************
* File Name: DVDAC8_1_VDAC8_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "DVDAC8_1_VDAC8.h"

static DVDAC8_1_VDAC8_backupStruct DVDAC8_1_VDAC8_backup;


/*******************************************************************************
* Function Name: DVDAC8_1_VDAC8_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void DVDAC8_1_VDAC8_SaveConfig(void) 
{
    if (!((DVDAC8_1_VDAC8_CR1 & DVDAC8_1_VDAC8_SRC_MASK) == DVDAC8_1_VDAC8_SRC_UDB))
    {
        DVDAC8_1_VDAC8_backup.data_value = DVDAC8_1_VDAC8_Data;
    }
}


/*******************************************************************************
* Function Name: DVDAC8_1_VDAC8_RestoreConfig
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
*******************************************************************************/
void DVDAC8_1_VDAC8_RestoreConfig(void) 
{
    if (!((DVDAC8_1_VDAC8_CR1 & DVDAC8_1_VDAC8_SRC_MASK) == DVDAC8_1_VDAC8_SRC_UDB))
    {
        if((DVDAC8_1_VDAC8_Strobe & DVDAC8_1_VDAC8_STRB_MASK) == DVDAC8_1_VDAC8_STRB_EN)
        {
            DVDAC8_1_VDAC8_Strobe &= (uint8)(~DVDAC8_1_VDAC8_STRB_MASK);
            DVDAC8_1_VDAC8_Data = DVDAC8_1_VDAC8_backup.data_value;
            DVDAC8_1_VDAC8_Strobe |= DVDAC8_1_VDAC8_STRB_EN;
        }
        else
        {
            DVDAC8_1_VDAC8_Data = DVDAC8_1_VDAC8_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: DVDAC8_1_VDAC8_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  DVDAC8_1_VDAC8_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void DVDAC8_1_VDAC8_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(DVDAC8_1_VDAC8_ACT_PWR_EN == (DVDAC8_1_VDAC8_PWRMGR & DVDAC8_1_VDAC8_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        DVDAC8_1_VDAC8_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        DVDAC8_1_VDAC8_backup.enableState = 0u;
    }
    
    DVDAC8_1_VDAC8_Stop();
    DVDAC8_1_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: DVDAC8_1_VDAC8_Wakeup
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
*  DVDAC8_1_VDAC8_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void DVDAC8_1_VDAC8_Wakeup(void) 
{
    DVDAC8_1_VDAC8_RestoreConfig();
    
    if(DVDAC8_1_VDAC8_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        DVDAC8_1_VDAC8_Enable();

        /* Restore the data register */
        DVDAC8_1_VDAC8_SetValue(DVDAC8_1_VDAC8_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
