/*******************************************************************************
* File Name: Button5_Reg.h  
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

#if !defined(CY_STATUS_REG_Button5_Reg_H) /* CY_STATUS_REG_Button5_Reg_H */
#define CY_STATUS_REG_Button5_Reg_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} Button5_Reg_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 Button5_Reg_Read(void) ;
void Button5_Reg_InterruptEnable(void) ;
void Button5_Reg_InterruptDisable(void) ;
void Button5_Reg_WriteMask(uint8 mask) ;
uint8 Button5_Reg_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define Button5_Reg_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define Button5_Reg_INPUTS              1


/***************************************
*             Registers
***************************************/

/* Status Register */
#define Button5_Reg_Status             (* (reg8 *) Button5_Reg_sts_sts_reg__STATUS_REG )
#define Button5_Reg_Status_PTR         (  (reg8 *) Button5_Reg_sts_sts_reg__STATUS_REG )
#define Button5_Reg_Status_Mask        (* (reg8 *) Button5_Reg_sts_sts_reg__MASK_REG )
#define Button5_Reg_Status_Aux_Ctrl    (* (reg8 *) Button5_Reg_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_Button5_Reg_H */


/* [] END OF FILE */
