/*******************************************************************************
* File Name: Push.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Push_H) /* Pins Push_H */
#define CY_PINS_Push_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Push_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Push__PORT == 15 && ((Push__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Push_Write(uint8 value) ;
void    Push_SetDriveMode(uint8 mode) ;
uint8   Push_ReadDataReg(void) ;
uint8   Push_Read(void) ;
uint8   Push_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Push_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Push_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Push_DM_RES_UP          PIN_DM_RES_UP
#define Push_DM_RES_DWN         PIN_DM_RES_DWN
#define Push_DM_OD_LO           PIN_DM_OD_LO
#define Push_DM_OD_HI           PIN_DM_OD_HI
#define Push_DM_STRONG          PIN_DM_STRONG
#define Push_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Push_MASK               Push__MASK
#define Push_SHIFT              Push__SHIFT
#define Push_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Push_PS                     (* (reg8 *) Push__PS)
/* Data Register */
#define Push_DR                     (* (reg8 *) Push__DR)
/* Port Number */
#define Push_PRT_NUM                (* (reg8 *) Push__PRT) 
/* Connect to Analog Globals */                                                  
#define Push_AG                     (* (reg8 *) Push__AG)                       
/* Analog MUX bux enable */
#define Push_AMUX                   (* (reg8 *) Push__AMUX) 
/* Bidirectional Enable */                                                        
#define Push_BIE                    (* (reg8 *) Push__BIE)
/* Bit-mask for Aliased Register Access */
#define Push_BIT_MASK               (* (reg8 *) Push__BIT_MASK)
/* Bypass Enable */
#define Push_BYP                    (* (reg8 *) Push__BYP)
/* Port wide control signals */                                                   
#define Push_CTL                    (* (reg8 *) Push__CTL)
/* Drive Modes */
#define Push_DM0                    (* (reg8 *) Push__DM0) 
#define Push_DM1                    (* (reg8 *) Push__DM1)
#define Push_DM2                    (* (reg8 *) Push__DM2) 
/* Input Buffer Disable Override */
#define Push_INP_DIS                (* (reg8 *) Push__INP_DIS)
/* LCD Common or Segment Drive */
#define Push_LCD_COM_SEG            (* (reg8 *) Push__LCD_COM_SEG)
/* Enable Segment LCD */
#define Push_LCD_EN                 (* (reg8 *) Push__LCD_EN)
/* Slew Rate Control */
#define Push_SLW                    (* (reg8 *) Push__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Push_PRTDSI__CAPS_SEL       (* (reg8 *) Push__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Push_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Push__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Push_PRTDSI__OE_SEL0        (* (reg8 *) Push__PRTDSI__OE_SEL0) 
#define Push_PRTDSI__OE_SEL1        (* (reg8 *) Push__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Push_PRTDSI__OUT_SEL0       (* (reg8 *) Push__PRTDSI__OUT_SEL0) 
#define Push_PRTDSI__OUT_SEL1       (* (reg8 *) Push__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Push_PRTDSI__SYNC_OUT       (* (reg8 *) Push__PRTDSI__SYNC_OUT) 


#if defined(Push__INTSTAT)  /* Interrupt Registers */

    #define Push_INTSTAT                (* (reg8 *) Push__INTSTAT)
    #define Push_SNAP                   (* (reg8 *) Push__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Push_H */


/* [] END OF FILE */
