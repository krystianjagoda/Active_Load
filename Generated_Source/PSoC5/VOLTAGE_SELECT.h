/*******************************************************************************
* File Name: VOLTAGE_SELECT.h  
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

#if !defined(CY_PINS_VOLTAGE_SELECT_H) /* Pins VOLTAGE_SELECT_H */
#define CY_PINS_VOLTAGE_SELECT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VOLTAGE_SELECT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VOLTAGE_SELECT__PORT == 15 && ((VOLTAGE_SELECT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    VOLTAGE_SELECT_Write(uint8 value) ;
void    VOLTAGE_SELECT_SetDriveMode(uint8 mode) ;
uint8   VOLTAGE_SELECT_ReadDataReg(void) ;
uint8   VOLTAGE_SELECT_Read(void) ;
uint8   VOLTAGE_SELECT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define VOLTAGE_SELECT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define VOLTAGE_SELECT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define VOLTAGE_SELECT_DM_RES_UP          PIN_DM_RES_UP
#define VOLTAGE_SELECT_DM_RES_DWN         PIN_DM_RES_DWN
#define VOLTAGE_SELECT_DM_OD_LO           PIN_DM_OD_LO
#define VOLTAGE_SELECT_DM_OD_HI           PIN_DM_OD_HI
#define VOLTAGE_SELECT_DM_STRONG          PIN_DM_STRONG
#define VOLTAGE_SELECT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define VOLTAGE_SELECT_MASK               VOLTAGE_SELECT__MASK
#define VOLTAGE_SELECT_SHIFT              VOLTAGE_SELECT__SHIFT
#define VOLTAGE_SELECT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VOLTAGE_SELECT_PS                     (* (reg8 *) VOLTAGE_SELECT__PS)
/* Data Register */
#define VOLTAGE_SELECT_DR                     (* (reg8 *) VOLTAGE_SELECT__DR)
/* Port Number */
#define VOLTAGE_SELECT_PRT_NUM                (* (reg8 *) VOLTAGE_SELECT__PRT) 
/* Connect to Analog Globals */                                                  
#define VOLTAGE_SELECT_AG                     (* (reg8 *) VOLTAGE_SELECT__AG)                       
/* Analog MUX bux enable */
#define VOLTAGE_SELECT_AMUX                   (* (reg8 *) VOLTAGE_SELECT__AMUX) 
/* Bidirectional Enable */                                                        
#define VOLTAGE_SELECT_BIE                    (* (reg8 *) VOLTAGE_SELECT__BIE)
/* Bit-mask for Aliased Register Access */
#define VOLTAGE_SELECT_BIT_MASK               (* (reg8 *) VOLTAGE_SELECT__BIT_MASK)
/* Bypass Enable */
#define VOLTAGE_SELECT_BYP                    (* (reg8 *) VOLTAGE_SELECT__BYP)
/* Port wide control signals */                                                   
#define VOLTAGE_SELECT_CTL                    (* (reg8 *) VOLTAGE_SELECT__CTL)
/* Drive Modes */
#define VOLTAGE_SELECT_DM0                    (* (reg8 *) VOLTAGE_SELECT__DM0) 
#define VOLTAGE_SELECT_DM1                    (* (reg8 *) VOLTAGE_SELECT__DM1)
#define VOLTAGE_SELECT_DM2                    (* (reg8 *) VOLTAGE_SELECT__DM2) 
/* Input Buffer Disable Override */
#define VOLTAGE_SELECT_INP_DIS                (* (reg8 *) VOLTAGE_SELECT__INP_DIS)
/* LCD Common or Segment Drive */
#define VOLTAGE_SELECT_LCD_COM_SEG            (* (reg8 *) VOLTAGE_SELECT__LCD_COM_SEG)
/* Enable Segment LCD */
#define VOLTAGE_SELECT_LCD_EN                 (* (reg8 *) VOLTAGE_SELECT__LCD_EN)
/* Slew Rate Control */
#define VOLTAGE_SELECT_SLW                    (* (reg8 *) VOLTAGE_SELECT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VOLTAGE_SELECT_PRTDSI__CAPS_SEL       (* (reg8 *) VOLTAGE_SELECT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VOLTAGE_SELECT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VOLTAGE_SELECT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VOLTAGE_SELECT_PRTDSI__OE_SEL0        (* (reg8 *) VOLTAGE_SELECT__PRTDSI__OE_SEL0) 
#define VOLTAGE_SELECT_PRTDSI__OE_SEL1        (* (reg8 *) VOLTAGE_SELECT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VOLTAGE_SELECT_PRTDSI__OUT_SEL0       (* (reg8 *) VOLTAGE_SELECT__PRTDSI__OUT_SEL0) 
#define VOLTAGE_SELECT_PRTDSI__OUT_SEL1       (* (reg8 *) VOLTAGE_SELECT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VOLTAGE_SELECT_PRTDSI__SYNC_OUT       (* (reg8 *) VOLTAGE_SELECT__PRTDSI__SYNC_OUT) 


#if defined(VOLTAGE_SELECT__INTSTAT)  /* Interrupt Registers */

    #define VOLTAGE_SELECT_INTSTAT                (* (reg8 *) VOLTAGE_SELECT__INTSTAT)
    #define VOLTAGE_SELECT_SNAP                   (* (reg8 *) VOLTAGE_SELECT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VOLTAGE_SELECT_H */


/* [] END OF FILE */
