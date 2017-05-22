/*******************************************************************************
* File Name: Button1.h  
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

#if !defined(CY_PINS_Button1_H) /* Pins Button1_H */
#define CY_PINS_Button1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Button1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Button1__PORT == 15 && ((Button1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    Button1_Write(uint8 value) ;
void    Button1_SetDriveMode(uint8 mode) ;
uint8   Button1_ReadDataReg(void) ;
uint8   Button1_Read(void) ;
uint8   Button1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define Button1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define Button1_DM_RES_UP          PIN_DM_RES_UP
#define Button1_DM_RES_DWN         PIN_DM_RES_DWN
#define Button1_DM_OD_LO           PIN_DM_OD_LO
#define Button1_DM_OD_HI           PIN_DM_OD_HI
#define Button1_DM_STRONG          PIN_DM_STRONG
#define Button1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define Button1_MASK               Button1__MASK
#define Button1_SHIFT              Button1__SHIFT
#define Button1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button1_PS                     (* (reg8 *) Button1__PS)
/* Data Register */
#define Button1_DR                     (* (reg8 *) Button1__DR)
/* Port Number */
#define Button1_PRT_NUM                (* (reg8 *) Button1__PRT) 
/* Connect to Analog Globals */                                                  
#define Button1_AG                     (* (reg8 *) Button1__AG)                       
/* Analog MUX bux enable */
#define Button1_AMUX                   (* (reg8 *) Button1__AMUX) 
/* Bidirectional Enable */                                                        
#define Button1_BIE                    (* (reg8 *) Button1__BIE)
/* Bit-mask for Aliased Register Access */
#define Button1_BIT_MASK               (* (reg8 *) Button1__BIT_MASK)
/* Bypass Enable */
#define Button1_BYP                    (* (reg8 *) Button1__BYP)
/* Port wide control signals */                                                   
#define Button1_CTL                    (* (reg8 *) Button1__CTL)
/* Drive Modes */
#define Button1_DM0                    (* (reg8 *) Button1__DM0) 
#define Button1_DM1                    (* (reg8 *) Button1__DM1)
#define Button1_DM2                    (* (reg8 *) Button1__DM2) 
/* Input Buffer Disable Override */
#define Button1_INP_DIS                (* (reg8 *) Button1__INP_DIS)
/* LCD Common or Segment Drive */
#define Button1_LCD_COM_SEG            (* (reg8 *) Button1__LCD_COM_SEG)
/* Enable Segment LCD */
#define Button1_LCD_EN                 (* (reg8 *) Button1__LCD_EN)
/* Slew Rate Control */
#define Button1_SLW                    (* (reg8 *) Button1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Button1_PRTDSI__CAPS_SEL       (* (reg8 *) Button1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Button1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Button1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Button1_PRTDSI__OE_SEL0        (* (reg8 *) Button1__PRTDSI__OE_SEL0) 
#define Button1_PRTDSI__OE_SEL1        (* (reg8 *) Button1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Button1_PRTDSI__OUT_SEL0       (* (reg8 *) Button1__PRTDSI__OUT_SEL0) 
#define Button1_PRTDSI__OUT_SEL1       (* (reg8 *) Button1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Button1_PRTDSI__SYNC_OUT       (* (reg8 *) Button1__PRTDSI__SYNC_OUT) 


#if defined(Button1__INTSTAT)  /* Interrupt Registers */

    #define Button1_INTSTAT                (* (reg8 *) Button1__INTSTAT)
    #define Button1_SNAP                   (* (reg8 *) Button1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Button1_H */


/* [] END OF FILE */
