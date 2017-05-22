/*******************************************************************************
* File Name: INPUT_OK.h  
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

#if !defined(CY_PINS_INPUT_OK_H) /* Pins INPUT_OK_H */
#define CY_PINS_INPUT_OK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "INPUT_OK_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 INPUT_OK__PORT == 15 && ((INPUT_OK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    INPUT_OK_Write(uint8 value) ;
void    INPUT_OK_SetDriveMode(uint8 mode) ;
uint8   INPUT_OK_ReadDataReg(void) ;
uint8   INPUT_OK_Read(void) ;
uint8   INPUT_OK_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define INPUT_OK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define INPUT_OK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define INPUT_OK_DM_RES_UP          PIN_DM_RES_UP
#define INPUT_OK_DM_RES_DWN         PIN_DM_RES_DWN
#define INPUT_OK_DM_OD_LO           PIN_DM_OD_LO
#define INPUT_OK_DM_OD_HI           PIN_DM_OD_HI
#define INPUT_OK_DM_STRONG          PIN_DM_STRONG
#define INPUT_OK_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define INPUT_OK_MASK               INPUT_OK__MASK
#define INPUT_OK_SHIFT              INPUT_OK__SHIFT
#define INPUT_OK_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define INPUT_OK_PS                     (* (reg8 *) INPUT_OK__PS)
/* Data Register */
#define INPUT_OK_DR                     (* (reg8 *) INPUT_OK__DR)
/* Port Number */
#define INPUT_OK_PRT_NUM                (* (reg8 *) INPUT_OK__PRT) 
/* Connect to Analog Globals */                                                  
#define INPUT_OK_AG                     (* (reg8 *) INPUT_OK__AG)                       
/* Analog MUX bux enable */
#define INPUT_OK_AMUX                   (* (reg8 *) INPUT_OK__AMUX) 
/* Bidirectional Enable */                                                        
#define INPUT_OK_BIE                    (* (reg8 *) INPUT_OK__BIE)
/* Bit-mask for Aliased Register Access */
#define INPUT_OK_BIT_MASK               (* (reg8 *) INPUT_OK__BIT_MASK)
/* Bypass Enable */
#define INPUT_OK_BYP                    (* (reg8 *) INPUT_OK__BYP)
/* Port wide control signals */                                                   
#define INPUT_OK_CTL                    (* (reg8 *) INPUT_OK__CTL)
/* Drive Modes */
#define INPUT_OK_DM0                    (* (reg8 *) INPUT_OK__DM0) 
#define INPUT_OK_DM1                    (* (reg8 *) INPUT_OK__DM1)
#define INPUT_OK_DM2                    (* (reg8 *) INPUT_OK__DM2) 
/* Input Buffer Disable Override */
#define INPUT_OK_INP_DIS                (* (reg8 *) INPUT_OK__INP_DIS)
/* LCD Common or Segment Drive */
#define INPUT_OK_LCD_COM_SEG            (* (reg8 *) INPUT_OK__LCD_COM_SEG)
/* Enable Segment LCD */
#define INPUT_OK_LCD_EN                 (* (reg8 *) INPUT_OK__LCD_EN)
/* Slew Rate Control */
#define INPUT_OK_SLW                    (* (reg8 *) INPUT_OK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define INPUT_OK_PRTDSI__CAPS_SEL       (* (reg8 *) INPUT_OK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define INPUT_OK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) INPUT_OK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define INPUT_OK_PRTDSI__OE_SEL0        (* (reg8 *) INPUT_OK__PRTDSI__OE_SEL0) 
#define INPUT_OK_PRTDSI__OE_SEL1        (* (reg8 *) INPUT_OK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define INPUT_OK_PRTDSI__OUT_SEL0       (* (reg8 *) INPUT_OK__PRTDSI__OUT_SEL0) 
#define INPUT_OK_PRTDSI__OUT_SEL1       (* (reg8 *) INPUT_OK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define INPUT_OK_PRTDSI__SYNC_OUT       (* (reg8 *) INPUT_OK__PRTDSI__SYNC_OUT) 


#if defined(INPUT_OK__INTSTAT)  /* Interrupt Registers */

    #define INPUT_OK_INTSTAT                (* (reg8 *) INPUT_OK__INTSTAT)
    #define INPUT_OK_SNAP                   (* (reg8 *) INPUT_OK__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_INPUT_OK_H */


/* [] END OF FILE */
