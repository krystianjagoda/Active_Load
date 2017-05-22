/*******************************************************************************
* File Name: Button4.h  
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

#if !defined(CY_PINS_Button4_H) /* Pins Button4_H */
#define CY_PINS_Button4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Button4_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Button4__PORT == 15 && ((Button4__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Button4_Write(uint8 value) ;
void    Button4_SetDriveMode(uint8 mode) ;
uint8   Button4_ReadDataReg(void) ;
uint8   Button4_Read(void) ;
uint8   Button4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button4_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Button4_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Button4_DM_RES_UP          PIN_DM_RES_UP
#define Button4_DM_RES_DWN         PIN_DM_RES_DWN
#define Button4_DM_OD_LO           PIN_DM_OD_LO
#define Button4_DM_OD_HI           PIN_DM_OD_HI
#define Button4_DM_STRONG          PIN_DM_STRONG
#define Button4_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Button4_MASK               Button4__MASK
#define Button4_SHIFT              Button4__SHIFT
#define Button4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button4_PS                     (* (reg8 *) Button4__PS)
/* Data Register */
#define Button4_DR                     (* (reg8 *) Button4__DR)
/* Port Number */
#define Button4_PRT_NUM                (* (reg8 *) Button4__PRT) 
/* Connect to Analog Globals */                                                  
#define Button4_AG                     (* (reg8 *) Button4__AG)                       
/* Analog MUX bux enable */
#define Button4_AMUX                   (* (reg8 *) Button4__AMUX) 
/* Bidirectional Enable */                                                        
#define Button4_BIE                    (* (reg8 *) Button4__BIE)
/* Bit-mask for Aliased Register Access */
#define Button4_BIT_MASK               (* (reg8 *) Button4__BIT_MASK)
/* Bypass Enable */
#define Button4_BYP                    (* (reg8 *) Button4__BYP)
/* Port wide control signals */                                                   
#define Button4_CTL                    (* (reg8 *) Button4__CTL)
/* Drive Modes */
#define Button4_DM0                    (* (reg8 *) Button4__DM0) 
#define Button4_DM1                    (* (reg8 *) Button4__DM1)
#define Button4_DM2                    (* (reg8 *) Button4__DM2) 
/* Input Buffer Disable Override */
#define Button4_INP_DIS                (* (reg8 *) Button4__INP_DIS)
/* LCD Common or Segment Drive */
#define Button4_LCD_COM_SEG            (* (reg8 *) Button4__LCD_COM_SEG)
/* Enable Segment LCD */
#define Button4_LCD_EN                 (* (reg8 *) Button4__LCD_EN)
/* Slew Rate Control */
#define Button4_SLW                    (* (reg8 *) Button4__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Button4_PRTDSI__CAPS_SEL       (* (reg8 *) Button4__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Button4_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Button4__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Button4_PRTDSI__OE_SEL0        (* (reg8 *) Button4__PRTDSI__OE_SEL0) 
#define Button4_PRTDSI__OE_SEL1        (* (reg8 *) Button4__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Button4_PRTDSI__OUT_SEL0       (* (reg8 *) Button4__PRTDSI__OUT_SEL0) 
#define Button4_PRTDSI__OUT_SEL1       (* (reg8 *) Button4__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Button4_PRTDSI__SYNC_OUT       (* (reg8 *) Button4__PRTDSI__SYNC_OUT) 


#if defined(Button4__INTSTAT)  /* Interrupt Registers */

    #define Button4_INTSTAT                (* (reg8 *) Button4__INTSTAT)
    #define Button4_SNAP                   (* (reg8 *) Button4__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Button4_H */


/* [] END OF FILE */
