/*******************************************************************************
* File Name: PWM_DRIVE.h  
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

#if !defined(CY_PINS_PWM_DRIVE_H) /* Pins PWM_DRIVE_H */
#define CY_PINS_PWM_DRIVE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "PWM_DRIVE_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 PWM_DRIVE__PORT == 15 && ((PWM_DRIVE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    PWM_DRIVE_Write(uint8 value) ;
void    PWM_DRIVE_SetDriveMode(uint8 mode) ;
uint8   PWM_DRIVE_ReadDataReg(void) ;
uint8   PWM_DRIVE_Read(void) ;
uint8   PWM_DRIVE_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define PWM_DRIVE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define PWM_DRIVE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define PWM_DRIVE_DM_RES_UP          PIN_DM_RES_UP
#define PWM_DRIVE_DM_RES_DWN         PIN_DM_RES_DWN
#define PWM_DRIVE_DM_OD_LO           PIN_DM_OD_LO
#define PWM_DRIVE_DM_OD_HI           PIN_DM_OD_HI
#define PWM_DRIVE_DM_STRONG          PIN_DM_STRONG
#define PWM_DRIVE_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define PWM_DRIVE_MASK               PWM_DRIVE__MASK
#define PWM_DRIVE_SHIFT              PWM_DRIVE__SHIFT
#define PWM_DRIVE_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define PWM_DRIVE_PS                     (* (reg8 *) PWM_DRIVE__PS)
/* Data Register */
#define PWM_DRIVE_DR                     (* (reg8 *) PWM_DRIVE__DR)
/* Port Number */
#define PWM_DRIVE_PRT_NUM                (* (reg8 *) PWM_DRIVE__PRT) 
/* Connect to Analog Globals */                                                  
#define PWM_DRIVE_AG                     (* (reg8 *) PWM_DRIVE__AG)                       
/* Analog MUX bux enable */
#define PWM_DRIVE_AMUX                   (* (reg8 *) PWM_DRIVE__AMUX) 
/* Bidirectional Enable */                                                        
#define PWM_DRIVE_BIE                    (* (reg8 *) PWM_DRIVE__BIE)
/* Bit-mask for Aliased Register Access */
#define PWM_DRIVE_BIT_MASK               (* (reg8 *) PWM_DRIVE__BIT_MASK)
/* Bypass Enable */
#define PWM_DRIVE_BYP                    (* (reg8 *) PWM_DRIVE__BYP)
/* Port wide control signals */                                                   
#define PWM_DRIVE_CTL                    (* (reg8 *) PWM_DRIVE__CTL)
/* Drive Modes */
#define PWM_DRIVE_DM0                    (* (reg8 *) PWM_DRIVE__DM0) 
#define PWM_DRIVE_DM1                    (* (reg8 *) PWM_DRIVE__DM1)
#define PWM_DRIVE_DM2                    (* (reg8 *) PWM_DRIVE__DM2) 
/* Input Buffer Disable Override */
#define PWM_DRIVE_INP_DIS                (* (reg8 *) PWM_DRIVE__INP_DIS)
/* LCD Common or Segment Drive */
#define PWM_DRIVE_LCD_COM_SEG            (* (reg8 *) PWM_DRIVE__LCD_COM_SEG)
/* Enable Segment LCD */
#define PWM_DRIVE_LCD_EN                 (* (reg8 *) PWM_DRIVE__LCD_EN)
/* Slew Rate Control */
#define PWM_DRIVE_SLW                    (* (reg8 *) PWM_DRIVE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define PWM_DRIVE_PRTDSI__CAPS_SEL       (* (reg8 *) PWM_DRIVE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define PWM_DRIVE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) PWM_DRIVE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define PWM_DRIVE_PRTDSI__OE_SEL0        (* (reg8 *) PWM_DRIVE__PRTDSI__OE_SEL0) 
#define PWM_DRIVE_PRTDSI__OE_SEL1        (* (reg8 *) PWM_DRIVE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define PWM_DRIVE_PRTDSI__OUT_SEL0       (* (reg8 *) PWM_DRIVE__PRTDSI__OUT_SEL0) 
#define PWM_DRIVE_PRTDSI__OUT_SEL1       (* (reg8 *) PWM_DRIVE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define PWM_DRIVE_PRTDSI__SYNC_OUT       (* (reg8 *) PWM_DRIVE__PRTDSI__SYNC_OUT) 


#if defined(PWM_DRIVE__INTSTAT)  /* Interrupt Registers */

    #define PWM_DRIVE_INTSTAT                (* (reg8 *) PWM_DRIVE__INTSTAT)
    #define PWM_DRIVE_SNAP                   (* (reg8 *) PWM_DRIVE__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_PWM_DRIVE_H */


/* [] END OF FILE */
