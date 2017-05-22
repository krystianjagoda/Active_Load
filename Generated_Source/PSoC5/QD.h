/*******************************************************************************
* File Name: QD.h  
* Version 3.0
*
* Description:
*  This file provides constants and parameter values for the Quadrature
*  Decoder component.
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

#if !defined(CY_QUADRATURE_DECODER_QD_H)
#define CY_QUADRATURE_DECODER_QD_H

#include "cyfitter.h"
#include "CyLib.h"
#include "cytypes.h"

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component QuadDec_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */

#define QD_COUNTER_SIZE               (16u)
#define QD_COUNTER_SIZE_8_BIT         (8u)
#define QD_COUNTER_SIZE_16_BIT        (16u)
#define QD_COUNTER_SIZE_32_BIT        (32u)

#if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
    #include "QD_Cnt8.h"
#else 
    /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) || 
    *  (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT) 
    */
    #include "QD_Cnt16.h"
#endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT */

extern uint8 QD_initVar;


/***************************************
*   Conditional Compilation Parameters
***************************************/

#define QD_COUNTER_RESOLUTION         (2u)


/***************************************
*       Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} QD_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void  QD_Init(void) ;
void  QD_Start(void) ;
void  QD_Stop(void) ;
void  QD_Enable(void) ;
uint8 QD_GetEvents(void) ;
void  QD_SetInterruptMask(uint8 mask) ;
uint8 QD_GetInterruptMask(void) ;
int16 QD_GetCounter(void) ;
void  QD_SetCounter(int16 value)
;
void  QD_Sleep(void) ;
void  QD_Wakeup(void) ;
void  QD_SaveConfig(void) ;
void  QD_RestoreConfig(void) ;

#if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
    CY_ISR_PROTO(QD_ISR);
#endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */


/***************************************
*           API Constants
***************************************/

#if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
    #define QD_ISR_NUMBER             ((uint8) QD_isr__INTC_NUMBER)
    #define QD_ISR_PRIORITY           ((uint8) QD_isr__INTC_PRIOR_NUM)
#endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT */


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define QD_GLITCH_FILTERING           (0u)
#define QD_INDEX_INPUT                (0u)


/***************************************
*    Initial Parameter Constants
***************************************/

#if (QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT)
    #define QD_COUNTER_INIT_VALUE    (0x80u)
#else 
    /* (QD_COUNTER_SIZE == QD_COUNTER_SIZE_16_BIT) ||
    *  (QD_COUNTER_SIZE == QD_COUNTER_SIZE_32_BIT)
    */
    #define QD_COUNTER_INIT_VALUE    (0x8000u)
    #define QD_COUNTER_MAX_VALUE     (0x7FFFu)
#endif /* QD_COUNTER_SIZE == QD_COUNTER_SIZE_8_BIT */


/***************************************
*             Registers
***************************************/

#define QD_STATUS_REG                 (* (reg8 *) QD_bQuadDec_Stsreg__STATUS_REG)
#define QD_STATUS_PTR                 (  (reg8 *) QD_bQuadDec_Stsreg__STATUS_REG)
#define QD_STATUS_MASK                (* (reg8 *) QD_bQuadDec_Stsreg__MASK_REG)
#define QD_STATUS_MASK_PTR            (  (reg8 *) QD_bQuadDec_Stsreg__MASK_REG)
#define QD_SR_AUX_CONTROL             (* (reg8 *) QD_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)
#define QD_SR_AUX_CONTROL_PTR         (  (reg8 *) QD_bQuadDec_Stsreg__STATUS_AUX_CTL_REG)


/***************************************
*        Register Constants
***************************************/

#define QD_COUNTER_OVERFLOW_SHIFT     (0x00u)
#define QD_COUNTER_UNDERFLOW_SHIFT    (0x01u)
#define QD_COUNTER_RESET_SHIFT        (0x02u)
#define QD_INVALID_IN_SHIFT           (0x03u)
#define QD_COUNTER_OVERFLOW           ((uint8) (0x01u << QD_COUNTER_OVERFLOW_SHIFT))
#define QD_COUNTER_UNDERFLOW          ((uint8) (0x01u << QD_COUNTER_UNDERFLOW_SHIFT))
#define QD_COUNTER_RESET              ((uint8) (0x01u << QD_COUNTER_RESET_SHIFT))
#define QD_INVALID_IN                 ((uint8) (0x01u << QD_INVALID_IN_SHIFT))

#define QD_INTERRUPTS_ENABLE_SHIFT    (0x04u)
#define QD_INTERRUPTS_ENABLE          ((uint8)(0x01u << QD_INTERRUPTS_ENABLE_SHIFT))
#define QD_INIT_INT_MASK              (0x0Fu)


/******************************************************************************************
* Following code are OBSOLETE and must not be used starting from Quadrature Decoder 2.20
******************************************************************************************/
#define QD_DISABLE                    (0x00u)


#endif /* CY_QUADRATURE_DECODER_QD_H */


/* [] END OF FILE */
