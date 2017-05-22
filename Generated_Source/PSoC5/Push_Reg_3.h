/*******************************************************************************
* File Name: Push_Reg_3.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_Push_Reg_3_H) /* CY_STATUS_REG_Push_Reg_3_H */
#define CY_STATUS_REG_Push_Reg_3_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} Push_Reg_3_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 Push_Reg_3_Read(void) ;
void Push_Reg_3_InterruptEnable(void) ;
void Push_Reg_3_InterruptDisable(void) ;
void Push_Reg_3_WriteMask(uint8 mask) ;
uint8 Push_Reg_3_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define Push_Reg_3_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define Push_Reg_3_INPUTS              1


/***************************************
*             Registers
***************************************/

/* Status Register */
#define Push_Reg_3_Status             (* (reg8 *) Push_Reg_3_sts_sts_reg__STATUS_REG )
#define Push_Reg_3_Status_PTR         (  (reg8 *) Push_Reg_3_sts_sts_reg__STATUS_REG )
#define Push_Reg_3_Status_Mask        (* (reg8 *) Push_Reg_3_sts_sts_reg__MASK_REG )
#define Push_Reg_3_Status_Aux_Ctrl    (* (reg8 *) Push_Reg_3_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_Push_Reg_3_H */


/* [] END OF FILE */
