/*******************************************************************************
* File Name: DVDAC8_1_PM.c
* Version 2.10
*
* Description:
*  This file provides the power management source code to the API for the
*  DVDAC component.
*
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DVDAC8_1.h"
#include "DVDAC8_1_VDAC8.h"

static DVDAC8_1_BACKUP_STRUCT  DVDAC8_1_backup;


/*******************************************************************************
* Function Name: DVDAC8_1_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for sleep. The
*  DVDAC8_1_Sleep() API saves the current component state. Then it
*  calls the DVDAC8_1_Stop() function and calls
*  DVDAC8_1_SaveConfig() to save the hardware configuration. Call the
*  DVDAC8_1_Sleep() function before calling the CyPmSleep() or the
*  CyPmHibernate() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DVDAC8_1_Sleep(void) 
{
    /* Save VDAC8's enable state */
    if(0u != (DVDAC8_1_VDAC8_PWRMGR & DVDAC8_1_VDAC8_ACT_PWR_EN))
    {
        DVDAC8_1_backup.enableState = 1u;
    }
    else
    {
        DVDAC8_1_backup.enableState = 0u;
    }

    DVDAC8_1_Stop();
    DVDAC8_1_SaveConfig();
}


/*******************************************************************************
* Function Name: DVDAC8_1_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  DVDAC8_1_Sleep() was called. The DVDAC8_1_Wakeup() function
*  calls the DVDAC8_1_RestoreConfig() function to restore the
*  configuration. If the component was enabled before the
*  DVDAC8_1_Sleep() function was called, the DVDAC_Wakeup() function
*  will also re-enable the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DVDAC8_1_Wakeup(void) 
{
    DVDAC8_1_RestoreConfig();

    if(DVDAC8_1_backup.enableState == 1u)
    {
        DVDAC8_1_Enable();
    }
}


/*******************************************************************************
* Function Name: DVDAC8_1_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the DVDAC8_1_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DVDAC8_1_SaveConfig(void) 
{
    DVDAC8_1_VDAC8_SaveConfig();
}


/*******************************************************************************
* Function Name: DVDAC8_1_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the DVDAC8_1_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  None
*
*******************************************************************************/
void DVDAC8_1_RestoreConfig(void) 
{
    DVDAC8_1_VDAC8_RestoreConfig();
}


/* [] END OF FILE */
