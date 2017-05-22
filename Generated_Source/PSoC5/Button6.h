/*******************************************************************************
* File Name: Button6.h  
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

#if !defined(CY_PINS_Button6_H) /* Pins Button6_H */
#define CY_PINS_Button6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Button6_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Button6__PORT == 15 && ((Button6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Button6_Write(uint8 value) ;
void    Button6_SetDriveMode(uint8 mode) ;
uint8   Button6_ReadDataReg(void) ;
uint8   Button6_Read(void) ;
uint8   Button6_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Button6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Button6_DM_RES_UP          PIN_DM_RES_UP
#define Button6_DM_RES_DWN         PIN_DM_RES_DWN
#define Button6_DM_OD_LO           PIN_DM_OD_LO
#define Button6_DM_OD_HI           PIN_DM_OD_HI
#define Button6_DM_STRONG          PIN_DM_STRONG
#define Button6_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Button6_MASK               Button6__MASK
#define Button6_SHIFT              Button6__SHIFT
#define Button6_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button6_PS                     (* (reg8 *) Button6__PS)
/* Data Register */
#define Button6_DR                     (* (reg8 *) Button6__DR)
/* Port Number */
#define Button6_PRT_NUM                (* (reg8 *) Button6__PRT) 
/* Connect to Analog Globals */                                                  
#define Button6_AG                     (* (reg8 *) Button6__AG)                       
/* Analog MUX bux enable */
#define Button6_AMUX                   (* (reg8 *) Button6__AMUX) 
/* Bidirectional Enable */                                                        
#define Button6_BIE                    (* (reg8 *) Button6__BIE)
/* Bit-mask for Aliased Register Access */
#define Button6_BIT_MASK               (* (reg8 *) Button6__BIT_MASK)
/* Bypass Enable */
#define Button6_BYP                    (* (reg8 *) Button6__BYP)
/* Port wide control signals */                                                   
#define Button6_CTL                    (* (reg8 *) Button6__CTL)
/* Drive Modes */
#define Button6_DM0                    (* (reg8 *) Button6__DM0) 
#define Button6_DM1                    (* (reg8 *) Button6__DM1)
#define Button6_DM2                    (* (reg8 *) Button6__DM2) 
/* Input Buffer Disable Override */
#define Button6_INP_DIS                (* (reg8 *) Button6__INP_DIS)
/* LCD Common or Segment Drive */
#define Button6_LCD_COM_SEG            (* (reg8 *) Button6__LCD_COM_SEG)
/* Enable Segment LCD */
#define Button6_LCD_EN                 (* (reg8 *) Button6__LCD_EN)
/* Slew Rate Control */
#define Button6_SLW                    (* (reg8 *) Button6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Button6_PRTDSI__CAPS_SEL       (* (reg8 *) Button6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Button6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Button6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Button6_PRTDSI__OE_SEL0        (* (reg8 *) Button6__PRTDSI__OE_SEL0) 
#define Button6_PRTDSI__OE_SEL1        (* (reg8 *) Button6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Button6_PRTDSI__OUT_SEL0       (* (reg8 *) Button6__PRTDSI__OUT_SEL0) 
#define Button6_PRTDSI__OUT_SEL1       (* (reg8 *) Button6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Button6_PRTDSI__SYNC_OUT       (* (reg8 *) Button6__PRTDSI__SYNC_OUT) 


#if defined(Button6__INTSTAT)  /* Interrupt Registers */

    #define Button6_INTSTAT                (* (reg8 *) Button6__INTSTAT)
    #define Button6_SNAP                   (* (reg8 *) Button6__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Button6_H */


/* [] END OF FILE */
