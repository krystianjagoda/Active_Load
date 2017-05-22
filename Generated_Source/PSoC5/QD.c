/*******************************************************************************
* File Name: QD.c  
* Version 3.0
*
* Description:
*  This file provides the source code to the API for the Quadrature Decoder
*  component.
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

#if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
    #include "QD_PVT.h"
#endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */

uint8 QD_initVar = 0u;


/*******************************************************************************
* Function Name: QD_Init
********************************************************************************
*
* Summary:
*  Inits/Restores default QuadDec configuration provided with customizer.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QD_Init(void) 
{
    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
        /* Disable Interrupt. */
        CyIntDisable(QD_ISR_NUMBER);
        /* Set the ISR to point to the QD_isr Interrupt. */
        (void) CyIntSetVector(QD_ISR_NUMBER, & QD_ISR);
        /* Set the priority. */
        CyIntSetPriority(QD_ISR_NUMBER, QD_ISR_PRIORITY);
    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: QD_Enable
********************************************************************************
*
* Summary:
*  This function enable interrupts from Component and also enable Component's
*  ISR in case of 32-bit counter.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QD_Enable(void) 
{
    uint8 enableInterrupts;

    QD_SetInterruptMask(QD_INIT_INT_MASK);

    /* Clear pending interrupts. */
    (void) QD_GetEvents();
    
    enableInterrupts = CyEnterCriticalSection();

    /* Enable interrupts from Statusi register */
    QD_SR_AUX_CONTROL |= QD_INTERRUPTS_ENABLE;

    CyExitCriticalSection(enableInterrupts);        

    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
        /* Enable Component interrupts */
        CyIntEnable(QD_ISR_NUMBER);
    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: QD_Start
********************************************************************************
*
* Summary:
*  Initializes UDBs and other relevant hardware.
*  Resets counter, enables or disables all relevant interrupts.
*  Starts monitoring the inputs and counting.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  QD_initVar - used to check initial configuration, modified on
*  first function call.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QD_Start(void) 
{
    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
        QD_Cnt8_Start();
        QD_Cnt8_WriteCounter(QD_COUNTER_INIT_VALUE);
    #else
        /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) || 
        *  (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT) 
        */
        QD_Cnt16_Start();
        QD_Cnt16_WriteCounter(QD_COUNTER_INIT_VALUE);
    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT */
    
    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)        
       QD_count32SoftPart = 0;
    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */

    if (QD_initVar == 0u)
    {
        QD_Init();
        QD_initVar = 1u;
    }

    QD_Enable();
}


/*******************************************************************************
* Function Name: QD_Stop
********************************************************************************
*
* Summary:
*  Turns off UDBs and other relevant hardware.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void QD_Stop(void) 
{
    uint8 enableInterrupts;

    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
        QD_Cnt8_Stop();
    #else 
        /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) ||
        *  (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
        */
        QD_Cnt16_Stop();    /* counter disable */
    #endif /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) */
 
    enableInterrupts = CyEnterCriticalSection();

    /* Disable interrupts interrupts from Statusi register */
    QD_SR_AUX_CONTROL &= (uint8) (~QD_INTERRUPTS_ENABLE);

    CyExitCriticalSection(enableInterrupts);

    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
        CyIntDisable(QD_ISR_NUMBER);    /* interrupt disable */
    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */
}


/*******************************************************************************
* Function Name: QD_GetCounter
********************************************************************************
*
* Summary:
*  Reports the current value of the counter.
*
* Parameters:
*  None.
*
* Return:
*  The counter value. Return type is signed and per the counter size setting.
*  A positive value indicates clockwise movement (B before A).
*
* Global variables:
*  QD_count32SoftPart - used to get hi 16 bit for current value
*  of the 32-bit counter, when Counter size equal 32-bit.
*
*******************************************************************************/
int16 QD_GetCounter(void) 
{
    int16 count;
    uint16 tmpCnt;

    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
        int16 hwCount;

        CyIntDisable(QD_ISR_NUMBER);

        tmpCnt = QD_Cnt16_ReadCounter();
        hwCount = (int16) ((int32) tmpCnt - (int32) QD_COUNTER_INIT_VALUE);
        count = QD_count32SoftPart + hwCount;

        CyIntEnable(QD_ISR_NUMBER);
    #else 
        /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) || 
        *  (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT)
        */
        #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
            tmpCnt = QD_Cnt8_ReadCounter();
        #else /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) */
            tmpCnt = QD_Cnt16_ReadCounter();
        #endif  /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT */

        count = (int16) ((int32) tmpCnt -
                (int32) QD_COUNTER_INIT_VALUE);

    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */ 

    return (count);
}


/*******************************************************************************
* Function Name: QD_SetCounter
********************************************************************************
*
* Summary:
*  Sets the current value of the counter.
*
* Parameters:
*  value:  The new value. Parameter type is signed and per the counter size
*  setting.
*
* Return:
*  None.
*
* Global variables:
*  QD_count32SoftPart - modified to set hi 16 bit for current
*  value of the 32-bit counter, when Counter size equal 32-bit.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void QD_SetCounter(int16 value) 
{
    #if ((QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) || \
         (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT))
        uint16 count;
        
        if (value >= 0)
        {
            count = (uint16) value + QD_COUNTER_INIT_VALUE;
        }
        else
        {
            count = QD_COUNTER_INIT_VALUE - (uint16)(-value);
        }
        #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
            QD_Cnt8_WriteCounter(count);
        #else /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) */
            QD_Cnt16_WriteCounter(count);
        #endif  /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT */
    #else /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT) */
        CyIntDisable(QD_ISR_NUMBER);

        QD_Cnt16_WriteCounter(QD_COUNTER_INIT_VALUE);
        QD_count32SoftPart = value;

        CyIntEnable(QD_ISR_NUMBER);
    #endif  /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT) ||
             * (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT)
             */
}


/*******************************************************************************
* Function Name: QD_GetEvents
********************************************************************************
* 
* Summary:
*   Reports the current status of events. This function clears the bits of the 
*   status register.
*
* Parameters:
*  None.
*
* Return:
*  The events, as bits in an unsigned 8-bit value:
*    Bit      Description
*     0        Counter overflow.
*     1        Counter underflow.
*     2        Counter reset due to index, if index input is used.
*     3        Invalid A, B inputs state transition.
*
*******************************************************************************/
uint8 QD_GetEvents(void) 
{
    return (QD_STATUS_REG & QD_INIT_INT_MASK);
}


/*******************************************************************************
* Function Name: QD_SetInterruptMask
********************************************************************************
*
* Summary:
*  Enables / disables interrupts due to the events.
*  For the 32-bit counter, the overflow, underflow and reset interrupts cannot
*  be disabled, these bits are ignored.
*
* Parameters:
*  mask: Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*
* Return:
*  None.
*
*******************************************************************************/
void QD_SetInterruptMask(uint8 mask) 
{
    #if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
        /* Underflow, Overflow and Reset interrupts for 32-bit Counter are always enable */
        mask |= (QD_COUNTER_OVERFLOW | QD_COUNTER_UNDERFLOW |
                 QD_COUNTER_RESET);
    #endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */

    QD_STATUS_MASK = mask;
}


/*******************************************************************************
* Function Name: QD_GetInterruptMask
********************************************************************************
*
* Summary:
*  Reports the current interrupt mask settings.
*
* Parameters:
*  None.
*
* Return:
*  Enable / disable bits in an 8-bit value, where 1 enables the interrupt.
*  For the 32-bit counter, the overflow, underflow and reset enable bits are
*  always set.
*
*******************************************************************************/
uint8 QD_GetInterruptMask(void) 
{
    return (QD_STATUS_MASK & QD_INIT_INT_MASK);
}


/* [] END OF FILE */
