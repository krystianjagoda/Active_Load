/*******************************************************************************
* File Name: CAP_EN.h  
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

#if !defined(CY_PINS_CAP_EN_H) /* Pins CAP_EN_H */
#define CY_PINS_CAP_EN_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CAP_EN_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CAP_EN__PORT == 15 && ((CAP_EN__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    CAP_EN_Write(uint8 value) ;
void    CAP_EN_SetDriveMode(uint8 mode) ;
uint8   CAP_EN_ReadDataReg(void) ;
uint8   CAP_EN_Read(void) ;
uint8   CAP_EN_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CAP_EN_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define CAP_EN_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define CAP_EN_DM_RES_UP          PIN_DM_RES_UP
#define CAP_EN_DM_RES_DWN         PIN_DM_RES_DWN
#define CAP_EN_DM_OD_LO           PIN_DM_OD_LO
#define CAP_EN_DM_OD_HI           PIN_DM_OD_HI
#define CAP_EN_DM_STRONG          PIN_DM_STRONG
#define CAP_EN_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define CAP_EN_MASK               CAP_EN__MASK
#define CAP_EN_SHIFT              CAP_EN__SHIFT
#define CAP_EN_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CAP_EN_PS                     (* (reg8 *) CAP_EN__PS)
/* Data Register */
#define CAP_EN_DR                     (* (reg8 *) CAP_EN__DR)
/* Port Number */
#define CAP_EN_PRT_NUM                (* (reg8 *) CAP_EN__PRT) 
/* Connect to Analog Globals */                                                  
#define CAP_EN_AG                     (* (reg8 *) CAP_EN__AG)                       
/* Analog MUX bux enable */
#define CAP_EN_AMUX                   (* (reg8 *) CAP_EN__AMUX) 
/* Bidirectional Enable */                                                        
#define CAP_EN_BIE                    (* (reg8 *) CAP_EN__BIE)
/* Bit-mask for Aliased Register Access */
#define CAP_EN_BIT_MASK               (* (reg8 *) CAP_EN__BIT_MASK)
/* Bypass Enable */
#define CAP_EN_BYP                    (* (reg8 *) CAP_EN__BYP)
/* Port wide control signals */                                                   
#define CAP_EN_CTL                    (* (reg8 *) CAP_EN__CTL)
/* Drive Modes */
#define CAP_EN_DM0                    (* (reg8 *) CAP_EN__DM0) 
#define CAP_EN_DM1                    (* (reg8 *) CAP_EN__DM1)
#define CAP_EN_DM2                    (* (reg8 *) CAP_EN__DM2) 
/* Input Buffer Disable Override */
#define CAP_EN_INP_DIS                (* (reg8 *) CAP_EN__INP_DIS)
/* LCD Common or Segment Drive */
#define CAP_EN_LCD_COM_SEG            (* (reg8 *) CAP_EN__LCD_COM_SEG)
/* Enable Segment LCD */
#define CAP_EN_LCD_EN                 (* (reg8 *) CAP_EN__LCD_EN)
/* Slew Rate Control */
#define CAP_EN_SLW                    (* (reg8 *) CAP_EN__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CAP_EN_PRTDSI__CAPS_SEL       (* (reg8 *) CAP_EN__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CAP_EN_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CAP_EN__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CAP_EN_PRTDSI__OE_SEL0        (* (reg8 *) CAP_EN__PRTDSI__OE_SEL0) 
#define CAP_EN_PRTDSI__OE_SEL1        (* (reg8 *) CAP_EN__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CAP_EN_PRTDSI__OUT_SEL0       (* (reg8 *) CAP_EN__PRTDSI__OUT_SEL0) 
#define CAP_EN_PRTDSI__OUT_SEL1       (* (reg8 *) CAP_EN__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CAP_EN_PRTDSI__SYNC_OUT       (* (reg8 *) CAP_EN__PRTDSI__SYNC_OUT) 


#if defined(CAP_EN__INTSTAT)  /* Interrupt Registers */

    #define CAP_EN_INTSTAT                (* (reg8 *) CAP_EN__INTSTAT)
    #define CAP_EN_SNAP                   (* (reg8 *) CAP_EN__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CAP_EN_H */


/* [] END OF FILE */
