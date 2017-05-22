/*******************************************************************************
* File Name: PWM_Buzz_PM.c
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

#include "PWM_Buzz.h"

static PWM_Buzz_backupStruct PWM_Buzz_backup;


/*******************************************************************************
* Function Name: PWM_Buzz_SaveConfig
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
*  PWM_Buzz_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Buzz_SaveConfig(void) 
{

    #if(!PWM_Buzz_UsingFixedFunction)
        #if(!PWM_Buzz_PWMModeIsCenterAligned)
            PWM_Buzz_backup.PWMPeriod = PWM_Buzz_ReadPeriod();
        #endif /* (!PWM_Buzz_PWMModeIsCenterAligned) */
        PWM_Buzz_backup.PWMUdb = PWM_Buzz_ReadCounter();
        #if (PWM_Buzz_UseStatus)
            PWM_Buzz_backup.InterruptMaskValue = PWM_Buzz_STATUS_MASK;
        #endif /* (PWM_Buzz_UseStatus) */

        #if(PWM_Buzz_DeadBandMode == PWM_Buzz__B_PWM__DBM_256_CLOCKS || \
            PWM_Buzz_DeadBandMode == PWM_Buzz__B_PWM__DBM_2_4_CLOCKS)
            PWM_Buzz_backup.PWMdeadBandValue = PWM_Buzz_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Buzz_KillModeMinTime)
             PWM_Buzz_backup.PWMKillCounterPeriod = PWM_Buzz_ReadKillTime();
        #endif /* (PWM_Buzz_KillModeMinTime) */

        #if(PWM_Buzz_UseControl)
            PWM_Buzz_backup.PWMControlRegister = PWM_Buzz_ReadControlRegister();
        #endif /* (PWM_Buzz_UseControl) */
    #endif  /* (!PWM_Buzz_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Buzz_RestoreConfig
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
*  PWM_Buzz_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Buzz_RestoreConfig(void) 
{
        #if(!PWM_Buzz_UsingFixedFunction)
            #if(!PWM_Buzz_PWMModeIsCenterAligned)
                PWM_Buzz_WritePeriod(PWM_Buzz_backup.PWMPeriod);
            #endif /* (!PWM_Buzz_PWMModeIsCenterAligned) */

            PWM_Buzz_WriteCounter(PWM_Buzz_backup.PWMUdb);

            #if (PWM_Buzz_UseStatus)
                PWM_Buzz_STATUS_MASK = PWM_Buzz_backup.InterruptMaskValue;
            #endif /* (PWM_Buzz_UseStatus) */

            #if(PWM_Buzz_DeadBandMode == PWM_Buzz__B_PWM__DBM_256_CLOCKS || \
                PWM_Buzz_DeadBandMode == PWM_Buzz__B_PWM__DBM_2_4_CLOCKS)
                PWM_Buzz_WriteDeadTime(PWM_Buzz_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Buzz_KillModeMinTime)
                PWM_Buzz_WriteKillTime(PWM_Buzz_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Buzz_KillModeMinTime) */

            #if(PWM_Buzz_UseControl)
                PWM_Buzz_WriteControlRegister(PWM_Buzz_backup.PWMControlRegister);
            #endif /* (PWM_Buzz_UseControl) */
        #endif  /* (!PWM_Buzz_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Buzz_Sleep
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
*  PWM_Buzz_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Buzz_Sleep(void) 
{
    #if(PWM_Buzz_UseControl)
        if(PWM_Buzz_CTRL_ENABLE == (PWM_Buzz_CONTROL & PWM_Buzz_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Buzz_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Buzz_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Buzz_UseControl) */

    /* Stop component */
    PWM_Buzz_Stop();

    /* Save registers configuration */
    PWM_Buzz_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Buzz_Wakeup
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
*  PWM_Buzz_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Buzz_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Buzz_RestoreConfig();

    if(PWM_Buzz_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Buzz_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
