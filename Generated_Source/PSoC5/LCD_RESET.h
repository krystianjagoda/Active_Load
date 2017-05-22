/*******************************************************************************
* File Name: LCD_RESET.h  
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

#if !defined(CY_PINS_LCD_RESET_H) /* Pins LCD_RESET_H */
#define CY_PINS_LCD_RESET_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "LCD_RESET_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 LCD_RESET__PORT == 15 && ((LCD_RESET__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    LCD_RESET_Write(uint8 value) ;
void    LCD_RESET_SetDriveMode(uint8 mode) ;
uint8   LCD_RESET_ReadDataReg(void) ;
uint8   LCD_RESET_Read(void) ;
uint8   LCD_RESET_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LCD_RESET_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define LCD_RESET_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define LCD_RESET_DM_RES_UP          PIN_DM_RES_UP
#define LCD_RESET_DM_RES_DWN         PIN_DM_RES_DWN
#define LCD_RESET_DM_OD_LO           PIN_DM_OD_LO
#define LCD_RESET_DM_OD_HI           PIN_DM_OD_HI
#define LCD_RESET_DM_STRONG          PIN_DM_STRONG
#define LCD_RESET_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define LCD_RESET_MASK               LCD_RESET__MASK
#define LCD_RESET_SHIFT              LCD_RESET__SHIFT
#define LCD_RESET_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LCD_RESET_PS                     (* (reg8 *) LCD_RESET__PS)
/* Data Register */
#define LCD_RESET_DR                     (* (reg8 *) LCD_RESET__DR)
/* Port Number */
#define LCD_RESET_PRT_NUM                (* (reg8 *) LCD_RESET__PRT) 
/* Connect to Analog Globals */                                                  
#define LCD_RESET_AG                     (* (reg8 *) LCD_RESET__AG)                       
/* Analog MUX bux enable */
#define LCD_RESET_AMUX                   (* (reg8 *) LCD_RESET__AMUX) 
/* Bidirectional Enable */                                                        
#define LCD_RESET_BIE                    (* (reg8 *) LCD_RESET__BIE)
/* Bit-mask for Aliased Register Access */
#define LCD_RESET_BIT_MASK               (* (reg8 *) LCD_RESET__BIT_MASK)
/* Bypass Enable */
#define LCD_RESET_BYP                    (* (reg8 *) LCD_RESET__BYP)
/* Port wide control signals */                                                   
#define LCD_RESET_CTL                    (* (reg8 *) LCD_RESET__CTL)
/* Drive Modes */
#define LCD_RESET_DM0                    (* (reg8 *) LCD_RESET__DM0) 
#define LCD_RESET_DM1                    (* (reg8 *) LCD_RESET__DM1)
#define LCD_RESET_DM2                    (* (reg8 *) LCD_RESET__DM2) 
/* Input Buffer Disable Override */
#define LCD_RESET_INP_DIS                (* (reg8 *) LCD_RESET__INP_DIS)
/* LCD Common or Segment Drive */
#define LCD_RESET_LCD_COM_SEG            (* (reg8 *) LCD_RESET__LCD_COM_SEG)
/* Enable Segment LCD */
#define LCD_RESET_LCD_EN                 (* (reg8 *) LCD_RESET__LCD_EN)
/* Slew Rate Control */
#define LCD_RESET_SLW                    (* (reg8 *) LCD_RESET__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define LCD_RESET_PRTDSI__CAPS_SEL       (* (reg8 *) LCD_RESET__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define LCD_RESET_PRTDSI__DBL_SYNC_IN    (* (reg8 *) LCD_RESET__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define LCD_RESET_PRTDSI__OE_SEL0        (* (reg8 *) LCD_RESET__PRTDSI__OE_SEL0) 
#define LCD_RESET_PRTDSI__OE_SEL1        (* (reg8 *) LCD_RESET__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define LCD_RESET_PRTDSI__OUT_SEL0       (* (reg8 *) LCD_RESET__PRTDSI__OUT_SEL0) 
#define LCD_RESET_PRTDSI__OUT_SEL1       (* (reg8 *) LCD_RESET__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define LCD_RESET_PRTDSI__SYNC_OUT       (* (reg8 *) LCD_RESET__PRTDSI__SYNC_OUT) 


#if defined(LCD_RESET__INTSTAT)  /* Interrupt Registers */

    #define LCD_RESET_INTSTAT                (* (reg8 *) LCD_RESET__INTSTAT)
    #define LCD_RESET_SNAP                   (* (reg8 *) LCD_RESET__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_LCD_RESET_H */


/* [] END OF FILE */
