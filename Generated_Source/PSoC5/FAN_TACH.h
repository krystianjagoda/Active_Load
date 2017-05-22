/*******************************************************************************
* File Name: FAN_TACH.h  
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

#if !defined(CY_PINS_FAN_TACH_H) /* Pins FAN_TACH_H */
#define CY_PINS_FAN_TACH_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "FAN_TACH_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 FAN_TACH__PORT == 15 && ((FAN_TACH__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    FAN_TACH_Write(uint8 value) ;
void    FAN_TACH_SetDriveMode(uint8 mode) ;
uint8   FAN_TACH_ReadDataReg(void) ;
uint8   FAN_TACH_Read(void) ;
uint8   FAN_TACH_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define FAN_TACH_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define FAN_TACH_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define FAN_TACH_DM_RES_UP          PIN_DM_RES_UP
#define FAN_TACH_DM_RES_DWN         PIN_DM_RES_DWN
#define FAN_TACH_DM_OD_LO           PIN_DM_OD_LO
#define FAN_TACH_DM_OD_HI           PIN_DM_OD_HI
#define FAN_TACH_DM_STRONG          PIN_DM_STRONG
#define FAN_TACH_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define FAN_TACH_MASK               FAN_TACH__MASK
#define FAN_TACH_SHIFT              FAN_TACH__SHIFT
#define FAN_TACH_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define FAN_TACH_PS                     (* (reg8 *) FAN_TACH__PS)
/* Data Register */
#define FAN_TACH_DR                     (* (reg8 *) FAN_TACH__DR)
/* Port Number */
#define FAN_TACH_PRT_NUM                (* (reg8 *) FAN_TACH__PRT) 
/* Connect to Analog Globals */                                                  
#define FAN_TACH_AG                     (* (reg8 *) FAN_TACH__AG)                       
/* Analog MUX bux enable */
#define FAN_TACH_AMUX                   (* (reg8 *) FAN_TACH__AMUX) 
/* Bidirectional Enable */                                                        
#define FAN_TACH_BIE                    (* (reg8 *) FAN_TACH__BIE)
/* Bit-mask for Aliased Register Access */
#define FAN_TACH_BIT_MASK               (* (reg8 *) FAN_TACH__BIT_MASK)
/* Bypass Enable */
#define FAN_TACH_BYP                    (* (reg8 *) FAN_TACH__BYP)
/* Port wide control signals */                                                   
#define FAN_TACH_CTL                    (* (reg8 *) FAN_TACH__CTL)
/* Drive Modes */
#define FAN_TACH_DM0                    (* (reg8 *) FAN_TACH__DM0) 
#define FAN_TACH_DM1                    (* (reg8 *) FAN_TACH__DM1)
#define FAN_TACH_DM2                    (* (reg8 *) FAN_TACH__DM2) 
/* Input Buffer Disable Override */
#define FAN_TACH_INP_DIS                (* (reg8 *) FAN_TACH__INP_DIS)
/* LCD Common or Segment Drive */
#define FAN_TACH_LCD_COM_SEG            (* (reg8 *) FAN_TACH__LCD_COM_SEG)
/* Enable Segment LCD */
#define FAN_TACH_LCD_EN                 (* (reg8 *) FAN_TACH__LCD_EN)
/* Slew Rate Control */
#define FAN_TACH_SLW                    (* (reg8 *) FAN_TACH__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define FAN_TACH_PRTDSI__CAPS_SEL       (* (reg8 *) FAN_TACH__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define FAN_TACH_PRTDSI__DBL_SYNC_IN    (* (reg8 *) FAN_TACH__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define FAN_TACH_PRTDSI__OE_SEL0        (* (reg8 *) FAN_TACH__PRTDSI__OE_SEL0) 
#define FAN_TACH_PRTDSI__OE_SEL1        (* (reg8 *) FAN_TACH__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define FAN_TACH_PRTDSI__OUT_SEL0       (* (reg8 *) FAN_TACH__PRTDSI__OUT_SEL0) 
#define FAN_TACH_PRTDSI__OUT_SEL1       (* (reg8 *) FAN_TACH__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define FAN_TACH_PRTDSI__SYNC_OUT       (* (reg8 *) FAN_TACH__PRTDSI__SYNC_OUT) 


#if defined(FAN_TACH__INTSTAT)  /* Interrupt Registers */

    #define FAN_TACH_INTSTAT                (* (reg8 *) FAN_TACH__INTSTAT)
    #define FAN_TACH_SNAP                   (* (reg8 *) FAN_TACH__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_FAN_TACH_H */


/* [] END OF FILE */
