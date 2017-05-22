/*******************************************************************************
* File Name: REV_POLARITY.h  
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

#if !defined(CY_PINS_REV_POLARITY_H) /* Pins REV_POLARITY_H */
#define CY_PINS_REV_POLARITY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "REV_POLARITY_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 REV_POLARITY__PORT == 15 && ((REV_POLARITY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    REV_POLARITY_Write(uint8 value) ;
void    REV_POLARITY_SetDriveMode(uint8 mode) ;
uint8   REV_POLARITY_ReadDataReg(void) ;
uint8   REV_POLARITY_Read(void) ;
uint8   REV_POLARITY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define REV_POLARITY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define REV_POLARITY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define REV_POLARITY_DM_RES_UP          PIN_DM_RES_UP
#define REV_POLARITY_DM_RES_DWN         PIN_DM_RES_DWN
#define REV_POLARITY_DM_OD_LO           PIN_DM_OD_LO
#define REV_POLARITY_DM_OD_HI           PIN_DM_OD_HI
#define REV_POLARITY_DM_STRONG          PIN_DM_STRONG
#define REV_POLARITY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define REV_POLARITY_MASK               REV_POLARITY__MASK
#define REV_POLARITY_SHIFT              REV_POLARITY__SHIFT
#define REV_POLARITY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define REV_POLARITY_PS                     (* (reg8 *) REV_POLARITY__PS)
/* Data Register */
#define REV_POLARITY_DR                     (* (reg8 *) REV_POLARITY__DR)
/* Port Number */
#define REV_POLARITY_PRT_NUM                (* (reg8 *) REV_POLARITY__PRT) 
/* Connect to Analog Globals */                                                  
#define REV_POLARITY_AG                     (* (reg8 *) REV_POLARITY__AG)                       
/* Analog MUX bux enable */
#define REV_POLARITY_AMUX                   (* (reg8 *) REV_POLARITY__AMUX) 
/* Bidirectional Enable */                                                        
#define REV_POLARITY_BIE                    (* (reg8 *) REV_POLARITY__BIE)
/* Bit-mask for Aliased Register Access */
#define REV_POLARITY_BIT_MASK               (* (reg8 *) REV_POLARITY__BIT_MASK)
/* Bypass Enable */
#define REV_POLARITY_BYP                    (* (reg8 *) REV_POLARITY__BYP)
/* Port wide control signals */                                                   
#define REV_POLARITY_CTL                    (* (reg8 *) REV_POLARITY__CTL)
/* Drive Modes */
#define REV_POLARITY_DM0                    (* (reg8 *) REV_POLARITY__DM0) 
#define REV_POLARITY_DM1                    (* (reg8 *) REV_POLARITY__DM1)
#define REV_POLARITY_DM2                    (* (reg8 *) REV_POLARITY__DM2) 
/* Input Buffer Disable Override */
#define REV_POLARITY_INP_DIS                (* (reg8 *) REV_POLARITY__INP_DIS)
/* LCD Common or Segment Drive */
#define REV_POLARITY_LCD_COM_SEG            (* (reg8 *) REV_POLARITY__LCD_COM_SEG)
/* Enable Segment LCD */
#define REV_POLARITY_LCD_EN                 (* (reg8 *) REV_POLARITY__LCD_EN)
/* Slew Rate Control */
#define REV_POLARITY_SLW                    (* (reg8 *) REV_POLARITY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define REV_POLARITY_PRTDSI__CAPS_SEL       (* (reg8 *) REV_POLARITY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define REV_POLARITY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) REV_POLARITY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define REV_POLARITY_PRTDSI__OE_SEL0        (* (reg8 *) REV_POLARITY__PRTDSI__OE_SEL0) 
#define REV_POLARITY_PRTDSI__OE_SEL1        (* (reg8 *) REV_POLARITY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define REV_POLARITY_PRTDSI__OUT_SEL0       (* (reg8 *) REV_POLARITY__PRTDSI__OUT_SEL0) 
#define REV_POLARITY_PRTDSI__OUT_SEL1       (* (reg8 *) REV_POLARITY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define REV_POLARITY_PRTDSI__SYNC_OUT       (* (reg8 *) REV_POLARITY__PRTDSI__SYNC_OUT) 


#if defined(REV_POLARITY__INTSTAT)  /* Interrupt Registers */

    #define REV_POLARITY_INTSTAT                (* (reg8 *) REV_POLARITY__INTSTAT)
    #define REV_POLARITY_SNAP                   (* (reg8 *) REV_POLARITY__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_REV_POLARITY_H */


/* [] END OF FILE */
