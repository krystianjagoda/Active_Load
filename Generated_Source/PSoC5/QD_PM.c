/*******************************************************************************
* File Name: QD_PM.c
* Version 3.0
*
* Description:
*  This file contains the setup, control and status commands to support 
*  component operations in low power mode.  
*
* Note:
*  None.
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "QD.h"

static QD_BACKUP_STRUCT QD_backup = {0u};


/*******************************************************************************
* Function Name: QD_SaveConfig
********************************************************************************
* Summary:
*  Saves the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QD_SaveConfig(void) 
{
    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
        QD_Cnt8_SaveConfig();
    #else 
        /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) || 
         * (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
         */
        QD_Cnt16_SaveConfig();
    #endif /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QD_RestoreConfig
********************************************************************************
* Summary:
*  Restores the current user configuration of the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QD_RestoreConfig(void) 
{
    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
        QD_Cnt8_RestoreConfig();
    #else 
        /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) || 
         * (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT) 
         */
        QD_Cnt16_RestoreConfig();
    #endif /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) */
}


/*******************************************************************************
* Function Name: QD_Sleep
********************************************************************************
* 
* Summary:
*  Prepare Quadrature Decoder Component goes to sleep.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QD_backup - modified when non-retention registers are saved.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QD_Sleep(void) 
{
    if (0u != (QD_SR_AUX_CONTROL & QD_INTERRUPTS_ENABLE))
    {
        QD_backup.enableState = 1u;
    }
    else /* The Quadrature Decoder Component is disabled */
    {
        QD_backup.enableState = 0u;
    }

    QD_Stop();
    QD_SaveConfig();
}


/*******************************************************************************
* Function Name: QD_Wakeup
********************************************************************************
*
* Summary:
*  Prepare Quadrature Decoder Component to wake up.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  QD_backup - used when non-retention registers are restored.
*
*******************************************************************************/
void QD_Wakeup(void) 
{
    QD_RestoreConfig();

    if (QD_backup.enableState != 0u)
    {
        #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
            QD_Cnt8_Enable();
        #else 
            /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) || 
            *  (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT) 
            */
            QD_Cnt16_Enable();
        #endif /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) */

        /* Enable component's operation */
        QD_Enable();
    } /* Do nothing if component's block was disabled before */
}


/* [] END OF FILE */

