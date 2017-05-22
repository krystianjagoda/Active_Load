/*******************************************************************************
* File Name: PWM_Fan_PM.c
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

#include "PWM_Fan.h"

static PWM_Fan_backupStruct PWM_Fan_backup;


/*******************************************************************************
* Function Name: PWM_Fan_SaveConfig
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
*  PWM_Fan_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void PWM_Fan_SaveConfig(void) 
{

    #if(!PWM_Fan_UsingFixedFunction)
        #if(!PWM_Fan_PWMModeIsCenterAligned)
            PWM_Fan_backup.PWMPeriod = PWM_Fan_ReadPeriod();
        #endif /* (!PWM_Fan_PWMModeIsCenterAligned) */
        PWM_Fan_backup.PWMUdb = PWM_Fan_ReadCounter();
        #if (PWM_Fan_UseStatus)
            PWM_Fan_backup.InterruptMaskValue = PWM_Fan_STATUS_MASK;
        #endif /* (PWM_Fan_UseStatus) */

        #if(PWM_Fan_DeadBandMode == PWM_Fan__B_PWM__DBM_256_CLOCKS || \
            PWM_Fan_DeadBandMode == PWM_Fan__B_PWM__DBM_2_4_CLOCKS)
            PWM_Fan_backup.PWMdeadBandValue = PWM_Fan_ReadDeadTime();
        #endif /*  deadband count is either 2-4 clocks or 256 clocks */

        #if(PWM_Fan_KillModeMinTime)
             PWM_Fan_backup.PWMKillCounterPeriod = PWM_Fan_ReadKillTime();
        #endif /* (PWM_Fan_KillModeMinTime) */

        #if(PWM_Fan_UseControl)
            PWM_Fan_backup.PWMControlRegister = PWM_Fan_ReadControlRegister();
        #endif /* (PWM_Fan_UseControl) */
    #endif  /* (!PWM_Fan_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: PWM_Fan_RestoreConfig
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
*  PWM_Fan_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Fan_RestoreConfig(void) 
{
        #if(!PWM_Fan_UsingFixedFunction)
            #if(!PWM_Fan_PWMModeIsCenterAligned)
                PWM_Fan_WritePeriod(PWM_Fan_backup.PWMPeriod);
            #endif /* (!PWM_Fan_PWMModeIsCenterAligned) */

            PWM_Fan_WriteCounter(PWM_Fan_backup.PWMUdb);

            #if (PWM_Fan_UseStatus)
                PWM_Fan_STATUS_MASK = PWM_Fan_backup.InterruptMaskValue;
            #endif /* (PWM_Fan_UseStatus) */

            #if(PWM_Fan_DeadBandMode == PWM_Fan__B_PWM__DBM_256_CLOCKS || \
                PWM_Fan_DeadBandMode == PWM_Fan__B_PWM__DBM_2_4_CLOCKS)
                PWM_Fan_WriteDeadTime(PWM_Fan_backup.PWMdeadBandValue);
            #endif /* deadband count is either 2-4 clocks or 256 clocks */

            #if(PWM_Fan_KillModeMinTime)
                PWM_Fan_WriteKillTime(PWM_Fan_backup.PWMKillCounterPeriod);
            #endif /* (PWM_Fan_KillModeMinTime) */

            #if(PWM_Fan_UseControl)
                PWM_Fan_WriteControlRegister(PWM_Fan_backup.PWMControlRegister);
            #endif /* (PWM_Fan_UseControl) */
        #endif  /* (!PWM_Fan_UsingFixedFunction) */
    }


/*******************************************************************************
* Function Name: PWM_Fan_Sleep
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
*  PWM_Fan_backup.PWMEnableState:  Is modified depending on the enable
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void PWM_Fan_Sleep(void) 
{
    #if(PWM_Fan_UseControl)
        if(PWM_Fan_CTRL_ENABLE == (PWM_Fan_CONTROL & PWM_Fan_CTRL_ENABLE))
        {
            /*Component is enabled */
            PWM_Fan_backup.PWMEnableState = 1u;
        }
        else
        {
            /* Component is disabled */
            PWM_Fan_backup.PWMEnableState = 0u;
        }
    #endif /* (PWM_Fan_UseControl) */

    /* Stop component */
    PWM_Fan_Stop();

    /* Save registers configuration */
    PWM_Fan_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Fan_Wakeup
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
*  PWM_Fan_backup.pwmEnable:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void PWM_Fan_Wakeup(void) 
{
     /* Restore registers values */
    PWM_Fan_RestoreConfig();

    if(PWM_Fan_backup.PWMEnableState != 0u)
    {
        /* Enable component's operation */
        PWM_Fan_Enable();
    } /* Do nothing if component's block was disabled before */

}


/* [] END OF FILE */
