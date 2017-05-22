/*******************************************************************************
* File Name: ResistiveTouch_1_ADC_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_ResistiveTouch_1_ADC_AMux_H)
#define CY_AMUX_ResistiveTouch_1_ADC_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void ResistiveTouch_1_ADC_AMux_Start(void) ;
#define ResistiveTouch_1_ADC_AMux_Init() ResistiveTouch_1_ADC_AMux_Start()
void ResistiveTouch_1_ADC_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void ResistiveTouch_1_ADC_AMux_Stop(void); */
/* void ResistiveTouch_1_ADC_AMux_Select(uint8 channel); */
/* void ResistiveTouch_1_ADC_AMux_Connect(uint8 channel); */
/* void ResistiveTouch_1_ADC_AMux_Disconnect(uint8 channel); */
/* void ResistiveTouch_1_ADC_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define ResistiveTouch_1_ADC_AMux_CHANNELS  2u
#define ResistiveTouch_1_ADC_AMux_MUXTYPE   1
#define ResistiveTouch_1_ADC_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define ResistiveTouch_1_ADC_AMux_NULL_CHANNEL 0xFFu
#define ResistiveTouch_1_ADC_AMux_MUX_SINGLE   1
#define ResistiveTouch_1_ADC_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if ResistiveTouch_1_ADC_AMux_MUXTYPE == ResistiveTouch_1_ADC_AMux_MUX_SINGLE
# if !ResistiveTouch_1_ADC_AMux_ATMOSTONE
#  define ResistiveTouch_1_ADC_AMux_Connect(channel) ResistiveTouch_1_ADC_AMux_Set(channel)
# endif
# define ResistiveTouch_1_ADC_AMux_Disconnect(channel) ResistiveTouch_1_ADC_AMux_Unset(channel)
#else
# if !ResistiveTouch_1_ADC_AMux_ATMOSTONE
void ResistiveTouch_1_ADC_AMux_Connect(uint8 channel) ;
# endif
void ResistiveTouch_1_ADC_AMux_Disconnect(uint8 channel) ;
#endif

#if ResistiveTouch_1_ADC_AMux_ATMOSTONE
# define ResistiveTouch_1_ADC_AMux_Stop() ResistiveTouch_1_ADC_AMux_DisconnectAll()
# define ResistiveTouch_1_ADC_AMux_Select(channel) ResistiveTouch_1_ADC_AMux_FastSelect(channel)
void ResistiveTouch_1_ADC_AMux_DisconnectAll(void) ;
#else
# define ResistiveTouch_1_ADC_AMux_Stop() ResistiveTouch_1_ADC_AMux_Start()
void ResistiveTouch_1_ADC_AMux_Select(uint8 channel) ;
# define ResistiveTouch_1_ADC_AMux_DisconnectAll() ResistiveTouch_1_ADC_AMux_Start()
#endif

#endif /* CY_AMUX_ResistiveTouch_1_ADC_AMux_H */


/* [] END OF FILE */
