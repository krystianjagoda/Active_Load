/*******************************************************************************
* File Name: ResistiveTouch_1_xm.h  
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

#if !defined(CY_PINS_ResistiveTouch_1_xm_H) /* Pins ResistiveTouch_1_xm_H */
#define CY_PINS_ResistiveTouch_1_xm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ResistiveTouch_1_xm_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ResistiveTouch_1_xm__PORT == 15 && ((ResistiveTouch_1_xm__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ResistiveTouch_1_xm_Write(uint8 value) ;
void    ResistiveTouch_1_xm_SetDriveMode(uint8 mode) ;
uint8   ResistiveTouch_1_xm_ReadDataReg(void) ;
uint8   ResistiveTouch_1_xm_Read(void) ;
uint8   ResistiveTouch_1_xm_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ResistiveTouch_1_xm_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ResistiveTouch_1_xm_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ResistiveTouch_1_xm_DM_RES_UP          PIN_DM_RES_UP
#define ResistiveTouch_1_xm_DM_RES_DWN         PIN_DM_RES_DWN
#define ResistiveTouch_1_xm_DM_OD_LO           PIN_DM_OD_LO
#define ResistiveTouch_1_xm_DM_OD_HI           PIN_DM_OD_HI
#define ResistiveTouch_1_xm_DM_STRONG          PIN_DM_STRONG
#define ResistiveTouch_1_xm_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ResistiveTouch_1_xm_MASK               ResistiveTouch_1_xm__MASK
#define ResistiveTouch_1_xm_SHIFT              ResistiveTouch_1_xm__SHIFT
#define ResistiveTouch_1_xm_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ResistiveTouch_1_xm_PS                     (* (reg8 *) ResistiveTouch_1_xm__PS)
/* Data Register */
#define ResistiveTouch_1_xm_DR                     (* (reg8 *) ResistiveTouch_1_xm__DR)
/* Port Number */
#define ResistiveTouch_1_xm_PRT_NUM                (* (reg8 *) ResistiveTouch_1_xm__PRT) 
/* Connect to Analog Globals */                                                  
#define ResistiveTouch_1_xm_AG                     (* (reg8 *) ResistiveTouch_1_xm__AG)                       
/* Analog MUX bux enable */
#define ResistiveTouch_1_xm_AMUX                   (* (reg8 *) ResistiveTouch_1_xm__AMUX) 
/* Bidirectional Enable */                                                        
#define ResistiveTouch_1_xm_BIE                    (* (reg8 *) ResistiveTouch_1_xm__BIE)
/* Bit-mask for Aliased Register Access */
#define ResistiveTouch_1_xm_BIT_MASK               (* (reg8 *) ResistiveTouch_1_xm__BIT_MASK)
/* Bypass Enable */
#define ResistiveTouch_1_xm_BYP                    (* (reg8 *) ResistiveTouch_1_xm__BYP)
/* Port wide control signals */                                                   
#define ResistiveTouch_1_xm_CTL                    (* (reg8 *) ResistiveTouch_1_xm__CTL)
/* Drive Modes */
#define ResistiveTouch_1_xm_DM0                    (* (reg8 *) ResistiveTouch_1_xm__DM0) 
#define ResistiveTouch_1_xm_DM1                    (* (reg8 *) ResistiveTouch_1_xm__DM1)
#define ResistiveTouch_1_xm_DM2                    (* (reg8 *) ResistiveTouch_1_xm__DM2) 
/* Input Buffer Disable Override */
#define ResistiveTouch_1_xm_INP_DIS                (* (reg8 *) ResistiveTouch_1_xm__INP_DIS)
/* LCD Common or Segment Drive */
#define ResistiveTouch_1_xm_LCD_COM_SEG            (* (reg8 *) ResistiveTouch_1_xm__LCD_COM_SEG)
/* Enable Segment LCD */
#define ResistiveTouch_1_xm_LCD_EN                 (* (reg8 *) ResistiveTouch_1_xm__LCD_EN)
/* Slew Rate Control */
#define ResistiveTouch_1_xm_SLW                    (* (reg8 *) ResistiveTouch_1_xm__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ResistiveTouch_1_xm_PRTDSI__CAPS_SEL       (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ResistiveTouch_1_xm_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ResistiveTouch_1_xm_PRTDSI__OE_SEL0        (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__OE_SEL0) 
#define ResistiveTouch_1_xm_PRTDSI__OE_SEL1        (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ResistiveTouch_1_xm_PRTDSI__OUT_SEL0       (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__OUT_SEL0) 
#define ResistiveTouch_1_xm_PRTDSI__OUT_SEL1       (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ResistiveTouch_1_xm_PRTDSI__SYNC_OUT       (* (reg8 *) ResistiveTouch_1_xm__PRTDSI__SYNC_OUT) 


#if defined(ResistiveTouch_1_xm__INTSTAT)  /* Interrupt Registers */

    #define ResistiveTouch_1_xm_INTSTAT                (* (reg8 *) ResistiveTouch_1_xm__INTSTAT)
    #define ResistiveTouch_1_xm_SNAP                   (* (reg8 *) ResistiveTouch_1_xm__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ResistiveTouch_1_xm_H */


/* [] END OF FILE */
