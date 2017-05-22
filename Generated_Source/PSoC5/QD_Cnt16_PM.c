/*******************************************************************************
* File Name: QD_Cnt16_PM.c  
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

#include "QD_Cnt16.h"

static QD_Cnt16_backupStruct QD_Cnt16_backup;


/*******************************************************************************
* Function Name: QD_Cnt16_SaveConfig
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
*  QD_Cnt16_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void QD_Cnt16_SaveConfig(void) 
{
    #if (!QD_Cnt16_UsingFixedFunction)

        QD_Cnt16_backup.CounterUdb = QD_Cnt16_ReadCounter();

        #if(!QD_Cnt16_ControlRegRemoved)
            QD_Cnt16_backup.CounterControlRegister = QD_Cnt16_ReadControlRegister();
        #endif /* (!QD_Cnt16_ControlRegRemoved) */

    #endif /* (!QD_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QD_Cnt16_RestoreConfig
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
*  QD_Cnt16_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void QD_Cnt16_RestoreConfig(void) 
{      
    #if (!QD_Cnt16_UsingFixedFunction)

       QD_Cnt16_WriteCounter(QD_Cnt16_backup.CounterUdb);

        #if(!QD_Cnt16_ControlRegRemoved)
            QD_Cnt16_WriteControlRegister(QD_Cnt16_backup.CounterControlRegister);
        #endif /* (!QD_Cnt16_ControlRegRemoved) */

    #endif /* (!QD_Cnt16_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: QD_Cnt16_Sleep
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
*  QD_Cnt16_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void QD_Cnt16_Sleep(void) 
{
    #if(!QD_Cnt16_ControlRegRemoved)
        /* Save Counter's enable state */
        if(QD_Cnt16_CTRL_ENABLE == (QD_Cnt16_CONTROL & QD_Cnt16_CTRL_ENABLE))
        {
            /* Counter is enabled */
            QD_Cnt16_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            QD_Cnt16_backup.CounterEnableState = 0u;
        }
    #else
        QD_Cnt16_backup.CounterEnableState = 1u;
        if(QD_Cnt16_backup.CounterEnableState != 0u)
        {
            QD_Cnt16_backup.CounterEnableState = 0u;
        }
    #endif /* (!QD_Cnt16_ControlRegRemoved) */
    
    QD_Cnt16_Stop();
    QD_Cnt16_SaveConfig();
}


/*******************************************************************************
* Function Name: QD_Cnt16_Wakeup
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
*  QD_Cnt16_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void QD_Cnt16_Wakeup(void) 
{
    QD_Cnt16_RestoreConfig();
    #if(!QD_Cnt16_ControlRegRemoved)
        if(QD_Cnt16_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            QD_Cnt16_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!QD_Cnt16_ControlRegRemoved) */
    
}


/* [] END OF FILE */
