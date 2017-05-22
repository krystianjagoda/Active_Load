/*******************************************************************************
* File Name: PWM_Driver_PM.c
* Version 3.30
*
* Description:
*  This file provides the power management source code to API for the
*  PWM.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "PWM_Driver.h"

static PWM_Driver_backupStruct PWM_Driver_backup;


/*******************************************************************************
* Function Name: PWM_Driver_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Driver_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Driver_SaveConfig(void) 
{

    #if(!PWM_Driver_UsingFixedFunction)
        #if(!PWM_Driver_PWMModeIsCenterAligned)
            PWM_Driver_backup.PWMPeriod = PWM_Driver_ReadPeriod();
        #endif /* (!PWM_Driver_PWMModeIsCenterAligned) */
        PWM_Driver_backup.PWMUdb = PWM_Driver_ReadCounter();
        #if (PWM_Driver_UseStatus)
            PWM_Driver_backup.InterruptMaskValue = PWM_Driver_STATUS_MASK;
        #endif /* (PWM_Driver_UseStatus) */

        #if(PWM_Driver_DeadBandMode == PWM_Driver__B_PWM__DBM_256_CLOCKS || \
            PWM_Driver_DeadBandMode == PWM_Driver__B_PWM__DBM_2_4_CLOCKS)
            PWM_Driver_backup.PWMdeadBandValue = PWM_Driver_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Driver_KillModeMinTime)
             PWM_Driver_backup.PWMKillCounterPeriod = PWM_Driver_ReadKillTime();
        #endif /* (PWM_Driver_KillModeMinTime) */

        #if(PWM_Driver_UseControl)
            PWM_Driver_backup.PWMControlRegister = PWM_Driver_ReadControlRegister();
        #endif /* (PWM_Driver_UseControl) */
    #endif  /* (!PWM_Driver_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Driver_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Driver_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Driver_RestoreConfig(void) 
{
        #if(!PWM_Driver_UsingFixedFunction)
            #if(!PWM_Driver_PWMModeIsCenterAligned)
                PWM_Driver_WritePeriod(PWM_Driver_backup.PWMPeriod);
            #endif /* (!PWM_Driver_PWMModeIsCenterAligned) */

            PWM_Driver_WriteCounter(PWM_Driver_backup.PWMUdb);

            #if (PWM_Driver_UseStatus)
                PWM_Driver_STATUS_MASK = PWM_Driver_backup.InterruptMaskValue;
            #endif /* (PWM_Driver_UseStatus) */

            #if(PWM_Driver_DeadBandMode == PWM_Driver__B_PWM__DBM_256_CLOCKS || \
                PWM_Driver_DeadBandMode == PWM_Driver__B_PWM__DBM_2_4_CLOCKS)
                PWM_Driver_WriteDeadTime(PWM_Driver_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Driver_KillModeMinTime)
                PWM_Driver_WriteKillTime(PWM_Driver_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Driver_KillModeMinTime) */

            #if(PWM_Driver_UseControl)
                PWM_Driver_WriteControlRegister(PWM_Driver_backup.PWMControlRegister);
            #endif /* (PWM_Driver_UseControl) */
        #endif  /* (!PWM_Driver_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Driver_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves the user configuration. Should be called
*  just prior to entering sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Driver_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Driver_Sleep(void) 
{
    #if(PWM_Driver_UseControl)
        if(PWM_Driver_CTRL_ENABLE == (PWM_Driver_CONTROL & PWM_Driver_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Driver_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Driver_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Driver_UseControl) */

    /* Stop component */
    PWM_Driver_Stop();

    /* Save registers configuration */
    PWM_Driver_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Driver_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration. Should be called just after
*  awaking from sleep.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  PWM_Driver_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Driver_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Driver_RestoreConfig();

    if(PWM_Driver_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Driver_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
