/*******************************************************************************
* File Name: ResistiveTouch_1_ym.h  
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

#if !defined(CY_PINS_ResistiveTouch_1_ym_H) /* Pins ResistiveTouch_1_ym_H */
#define CY_PINS_ResistiveTouch_1_ym_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "ResistiveTouch_1_ym_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 ResistiveTouch_1_ym__PORT == 15 && ((ResistiveTouch_1_ym__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    ResistiveTouch_1_ym_Write(uint8 value) ;
void    ResistiveTouch_1_ym_SetDriveMode(uint8 mode) ;
uint8   ResistiveTouch_1_ym_ReadDataReg(void) ;
uint8   ResistiveTouch_1_ym_Read(void) ;
uint8   ResistiveTouch_1_ym_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ResistiveTouch_1_ym_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define ResistiveTouch_1_ym_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define ResistiveTouch_1_ym_DM_RES_UP          PIN_DM_RES_UP
#define ResistiveTouch_1_ym_DM_RES_DWN         PIN_DM_RES_DWN
#define ResistiveTouch_1_ym_DM_OD_LO           PIN_DM_OD_LO
#define ResistiveTouch_1_ym_DM_OD_HI           PIN_DM_OD_HI
#define ResistiveTouch_1_ym_DM_STRONG          PIN_DM_STRONG
#define ResistiveTouch_1_ym_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define ResistiveTouch_1_ym_MASK               ResistiveTouch_1_ym__MASK
#define ResistiveTouch_1_ym_SHIFT              ResistiveTouch_1_ym__SHIFT
#define ResistiveTouch_1_ym_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ResistiveTouch_1_ym_PS                     (* (reg8 *) ResistiveTouch_1_ym__PS)
/* Data Register */
#define ResistiveTouch_1_ym_DR                     (* (reg8 *) ResistiveTouch_1_ym__DR)
/* Port Number */
#define ResistiveTouch_1_ym_PRT_NUM                (* (reg8 *) ResistiveTouch_1_ym__PRT) 
/* Connect to Analog Globals */                                                  
#define ResistiveTouch_1_ym_AG                     (* (reg8 *) ResistiveTouch_1_ym__AG)                       
/* Analog MUX bux enable */
#define ResistiveTouch_1_ym_AMUX                   (* (reg8 *) ResistiveTouch_1_ym__AMUX) 
/* Bidirectional Enable */                                                        
#define ResistiveTouch_1_ym_BIE                    (* (reg8 *) ResistiveTouch_1_ym__BIE)
/* Bit-mask for Aliased Register Access */
#define ResistiveTouch_1_ym_BIT_MASK               (* (reg8 *) ResistiveTouch_1_ym__BIT_MASK)
/* Bypass Enable */
#define ResistiveTouch_1_ym_BYP                    (* (reg8 *) ResistiveTouch_1_ym__BYP)
/* Port wide control signals */                                                   
#define ResistiveTouch_1_ym_CTL                    (* (reg8 *) ResistiveTouch_1_ym__CTL)
/* Drive Modes */
#define ResistiveTouch_1_ym_DM0                    (* (reg8 *) ResistiveTouch_1_ym__DM0) 
#define ResistiveTouch_1_ym_DM1                    (* (reg8 *) ResistiveTouch_1_ym__DM1)
#define ResistiveTouch_1_ym_DM2                    (* (reg8 *) ResistiveTouch_1_ym__DM2) 
/* Input Buffer Disable Override */
#define ResistiveTouch_1_ym_INP_DIS                (* (reg8 *) ResistiveTouch_1_ym__INP_DIS)
/* LCD Common or Segment Drive */
#define ResistiveTouch_1_ym_LCD_COM_SEG            (* (reg8 *) ResistiveTouch_1_ym__LCD_COM_SEG)
/* Enable Segment LCD */
#define ResistiveTouch_1_ym_LCD_EN                 (* (reg8 *) ResistiveTouch_1_ym__LCD_EN)
/* Slew Rate Control */
#define ResistiveTouch_1_ym_SLW                    (* (reg8 *) ResistiveTouch_1_ym__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define ResistiveTouch_1_ym_PRTDSI__CAPS_SEL       (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define ResistiveTouch_1_ym_PRTDSI__DBL_SYNC_IN    (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define ResistiveTouch_1_ym_PRTDSI__OE_SEL0        (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__OE_SEL0) 
#define ResistiveTouch_1_ym_PRTDSI__OE_SEL1        (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define ResistiveTouch_1_ym_PRTDSI__OUT_SEL0       (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__OUT_SEL0) 
#define ResistiveTouch_1_ym_PRTDSI__OUT_SEL1       (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define ResistiveTouch_1_ym_PRTDSI__SYNC_OUT       (* (reg8 *) ResistiveTouch_1_ym__PRTDSI__SYNC_OUT) 


#if defined(ResistiveTouch_1_ym__INTSTAT)  /* Interrupt Registers */

    #define ResistiveTouch_1_ym_INTSTAT                (* (reg8 *) ResistiveTouch_1_ym__INTSTAT)
    #define ResistiveTouch_1_ym_SNAP                   (* (reg8 *) ResistiveTouch_1_ym__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_ResistiveTouch_1_ym_H */


/* [] END OF FILE */
