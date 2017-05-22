/*******************************************************************************
* File Name: PWM_Back_PM.c
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

#include "PWM_Back.h"

static PWM_Back_backupStruct PWM_Back_backup;


/*******************************************************************************
* Function Name: PWM_Back_SaveConfig
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
*  PWM_Back_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Back_SaveConfig(void) 
{

    #if(!PWM_Back_UsingFixedFunction)
        #if(!PWM_Back_PWMModeIsCenterAligned)
            PWM_Back_backup.PWMPeriod = PWM_Back_ReadPeriod();
        #endif /* (!PWM_Back_PWMModeIsCenterAligned) */
        PWM_Back_backup.PWMUdb = PWM_Back_ReadCounter();
        #if (PWM_Back_UseStatus)
            PWM_Back_backup.InterruptMaskValue = PWM_Back_STATUS_MASK;
        #endif /* (PWM_Back_UseStatus) */

        #if(PWM_Back_DeadBandMode == PWM_Back__B_PWM__DBM_256_CLOCKS || \
            PWM_Back_DeadBandMode == PWM_Back__B_PWM__DBM_2_4_CLOCKS)
            PWM_Back_backup.PWMdeadBandValue = PWM_Back_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Back_KillModeMinTime)
             PWM_Back_backup.PWMKillCounterPeriod = PWM_Back_ReadKillTime();
        #endif /* (PWM_Back_KillModeMinTime) */

        #if(PWM_Back_UseControl)
            PWM_Back_backup.PWMControlRegister = PWM_Back_ReadControlRegister();
        #endif /* (PWM_Back_UseControl) */
    #endif  /* (!PWM_Back_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Back_RestoreConfig
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
*  PWM_Back_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Back_RestoreConfig(void) 
{
        #if(!PWM_Back_UsingFixedFunction)
            #if(!PWM_Back_PWMModeIsCenterAligned)
                PWM_Back_WritePeriod(PWM_Back_backup.PWMPeriod);
            #endif /* (!PWM_Back_PWMModeIsCenterAligned) */

            PWM_Back_WriteCounter(PWM_Back_backup.PWMUdb);

            #if (PWM_Back_UseStatus)
                PWM_Back_STATUS_MASK = PWM_Back_backup.InterruptMaskValue;
            #endif /* (PWM_Back_UseStatus) */

            #if(PWM_Back_DeadBandMode == PWM_Back__B_PWM__DBM_256_CLOCKS || \
                PWM_Back_DeadBandMode == PWM_Back__B_PWM__DBM_2_4_CLOCKS)
                PWM_Back_WriteDeadTime(PWM_Back_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Back_KillModeMinTime)
                PWM_Back_WriteKillTime(PWM_Back_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Back_KillModeMinTime) */

            #if(PWM_Back_UseControl)
                PWM_Back_WriteControlRegister(PWM_Back_backup.PWMControlRegister);
            #endif /* (PWM_Back_UseControl) */
        #endif  /* (!PWM_Back_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Back_Sleep
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
*  PWM_Back_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Back_Sleep(void) 
{
    #if(PWM_Back_UseControl)
        if(PWM_Back_CTRL_ENABLE == (PWM_Back_CONTROL & PWM_Back_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Back_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Back_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Back_UseControl) */

    /* Stop component */
    PWM_Back_Stop();

    /* Save registers configuration */
    PWM_Back_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Back_Wakeup
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
*  PWM_Back_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Back_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Back_RestoreConfig();

    if(PWM_Back_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Back_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
