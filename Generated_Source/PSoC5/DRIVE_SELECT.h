/*******************************************************************************
* File Name: DRIVE_SELECT.h  
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

#if !defined(CY_PINS_DRIVE_SELECT_H) /* Pins DRIVE_SELECT_H */
#define CY_PINS_DRIVE_SELECT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DRIVE_SELECT_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DRIVE_SELECT__PORT == 15 && ((DRIVE_SELECT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    DRIVE_SELECT_Write(uint8 value) ;
void    DRIVE_SELECT_SetDriveMode(uint8 mode) ;
uint8   DRIVE_SELECT_ReadDataReg(void) ;
uint8   DRIVE_SELECT_Read(void) ;
uint8   DRIVE_SELECT_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define DRIVE_SELECT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define DRIVE_SELECT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define DRIVE_SELECT_DM_RES_UP          PIN_DM_RES_UP
#define DRIVE_SELECT_DM_RES_DWN         PIN_DM_RES_DWN
#define DRIVE_SELECT_DM_OD_LO           PIN_DM_OD_LO
#define DRIVE_SELECT_DM_OD_HI           PIN_DM_OD_HI
#define DRIVE_SELECT_DM_STRONG          PIN_DM_STRONG
#define DRIVE_SELECT_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define DRIVE_SELECT_MASK               DRIVE_SELECT__MASK
#define DRIVE_SELECT_SHIFT              DRIVE_SELECT__SHIFT
#define DRIVE_SELECT_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DRIVE_SELECT_PS                     (* (reg8 *) DRIVE_SELECT__PS)
/* Data Register */
#define DRIVE_SELECT_DR                     (* (reg8 *) DRIVE_SELECT__DR)
/* Port Number */
#define DRIVE_SELECT_PRT_NUM                (* (reg8 *) DRIVE_SELECT__PRT) 
/* Connect to Analog Globals */                                                  
#define DRIVE_SELECT_AG                     (* (reg8 *) DRIVE_SELECT__AG)                       
/* Analog MUX bux enable */
#define DRIVE_SELECT_AMUX                   (* (reg8 *) DRIVE_SELECT__AMUX) 
/* Bidirectional Enable */                                                        
#define DRIVE_SELECT_BIE                    (* (reg8 *) DRIVE_SELECT__BIE)
/* Bit-mask for Aliased Register Access */
#define DRIVE_SELECT_BIT_MASK               (* (reg8 *) DRIVE_SELECT__BIT_MASK)
/* Bypass Enable */
#define DRIVE_SELECT_BYP                    (* (reg8 *) DRIVE_SELECT__BYP)
/* Port wide control signals */                                                   
#define DRIVE_SELECT_CTL                    (* (reg8 *) DRIVE_SELECT__CTL)
/* Drive Modes */
#define DRIVE_SELECT_DM0                    (* (reg8 *) DRIVE_SELECT__DM0) 
#define DRIVE_SELECT_DM1                    (* (reg8 *) DRIVE_SELECT__DM1)
#define DRIVE_SELECT_DM2                    (* (reg8 *) DRIVE_SELECT__DM2) 
/* Input Buffer Disable Override */
#define DRIVE_SELECT_INP_DIS                (* (reg8 *) DRIVE_SELECT__INP_DIS)
/* LCD Common or Segment Drive */
#define DRIVE_SELECT_LCD_COM_SEG            (* (reg8 *) DRIVE_SELECT__LCD_COM_SEG)
/* Enable Segment LCD */
#define DRIVE_SELECT_LCD_EN                 (* (reg8 *) DRIVE_SELECT__LCD_EN)
/* Slew Rate Control */
#define DRIVE_SELECT_SLW                    (* (reg8 *) DRIVE_SELECT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DRIVE_SELECT_PRTDSI__CAPS_SEL       (* (reg8 *) DRIVE_SELECT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DRIVE_SELECT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DRIVE_SELECT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DRIVE_SELECT_PRTDSI__OE_SEL0        (* (reg8 *) DRIVE_SELECT__PRTDSI__OE_SEL0) 
#define DRIVE_SELECT_PRTDSI__OE_SEL1        (* (reg8 *) DRIVE_SELECT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DRIVE_SELECT_PRTDSI__OUT_SEL0       (* (reg8 *) DRIVE_SELECT__PRTDSI__OUT_SEL0) 
#define DRIVE_SELECT_PRTDSI__OUT_SEL1       (* (reg8 *) DRIVE_SELECT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DRIVE_SELECT_PRTDSI__SYNC_OUT       (* (reg8 *) DRIVE_SELECT__PRTDSI__SYNC_OUT) 


#if defined(DRIVE_SELECT__INTSTAT)  /* Interrupt Registers */

    #define DRIVE_SELECT_INTSTAT                (* (reg8 *) DRIVE_SELECT__INTSTAT)
    #define DRIVE_SELECT_SNAP                   (* (reg8 *) DRIVE_SELECT__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DRIVE_SELECT_H */


/* [] END OF FILE */
