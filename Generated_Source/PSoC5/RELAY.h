/*******************************************************************************
* File Name: RELAY.h  
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

#if !defined(CY_PINS_RELAY_H) /* Pins RELAY_H */
#define CY_PINS_RELAY_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RELAY_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RELAY__PORT == 15 && ((RELAY__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RELAY_Write(uint8 value) ;
void    RELAY_SetDriveMode(uint8 mode) ;
uint8   RELAY_ReadDataReg(void) ;
uint8   RELAY_Read(void) ;
uint8   RELAY_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RELAY_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RELAY_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RELAY_DM_RES_UP          PIN_DM_RES_UP
#define RELAY_DM_RES_DWN         PIN_DM_RES_DWN
#define RELAY_DM_OD_LO           PIN_DM_OD_LO
#define RELAY_DM_OD_HI           PIN_DM_OD_HI
#define RELAY_DM_STRONG          PIN_DM_STRONG
#define RELAY_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RELAY_MASK               RELAY__MASK
#define RELAY_SHIFT              RELAY__SHIFT
#define RELAY_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RELAY_PS                     (* (reg8 *) RELAY__PS)
/* Data Register */
#define RELAY_DR                     (* (reg8 *) RELAY__DR)
/* Port Number */
#define RELAY_PRT_NUM                (* (reg8 *) RELAY__PRT) 
/* Connect to Analog Globals */                                                  
#define RELAY_AG                     (* (reg8 *) RELAY__AG)                       
/* Analog MUX bux enable */
#define RELAY_AMUX                   (* (reg8 *) RELAY__AMUX) 
/* Bidirectional Enable */                                                        
#define RELAY_BIE                    (* (reg8 *) RELAY__BIE)
/* Bit-mask for Aliased Register Access */
#define RELAY_BIT_MASK               (* (reg8 *) RELAY__BIT_MASK)
/* Bypass Enable */
#define RELAY_BYP                    (* (reg8 *) RELAY__BYP)
/* Port wide control signals */                                                   
#define RELAY_CTL                    (* (reg8 *) RELAY__CTL)
/* Drive Modes */
#define RELAY_DM0                    (* (reg8 *) RELAY__DM0) 
#define RELAY_DM1                    (* (reg8 *) RELAY__DM1)
#define RELAY_DM2                    (* (reg8 *) RELAY__DM2) 
/* Input Buffer Disable Override */
#define RELAY_INP_DIS                (* (reg8 *) RELAY__INP_DIS)
/* LCD Common or Segment Drive */
#define RELAY_LCD_COM_SEG            (* (reg8 *) RELAY__LCD_COM_SEG)
/* Enable Segment LCD */
#define RELAY_LCD_EN                 (* (reg8 *) RELAY__LCD_EN)
/* Slew Rate Control */
#define RELAY_SLW                    (* (reg8 *) RELAY__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RELAY_PRTDSI__CAPS_SEL       (* (reg8 *) RELAY__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RELAY_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RELAY__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RELAY_PRTDSI__OE_SEL0        (* (reg8 *) RELAY__PRTDSI__OE_SEL0) 
#define RELAY_PRTDSI__OE_SEL1        (* (reg8 *) RELAY__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RELAY_PRTDSI__OUT_SEL0       (* (reg8 *) RELAY__PRTDSI__OUT_SEL0) 
#define RELAY_PRTDSI__OUT_SEL1       (* (reg8 *) RELAY__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RELAY_PRTDSI__SYNC_OUT       (* (reg8 *) RELAY__PRTDSI__SYNC_OUT) 


#if defined(RELAY__INTSTAT)  /* Interrupt Registers */

    #define RELAY_INTSTAT                (* (reg8 *) RELAY__INTSTAT)
    #define RELAY_SNAP                   (* (reg8 *) RELAY__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RELAY_H */


/* [] END OF FILE */
