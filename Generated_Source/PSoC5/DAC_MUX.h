/*******************************************************************************
* File Name: DAC_MUX.h
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

#if !defined(CY_AMUX_DAC_MUX_H)
#define CY_AMUX_DAC_MUX_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void DAC_MUX_Start(void) ;
#define DAC_MUX_Init() DAC_MUX_Start()
void DAC_MUX_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void DAC_MUX_Stop(void); */
/* void DAC_MUX_Select(uint8 channel); */
/* void DAC_MUX_Connect(uint8 channel); */
/* void DAC_MUX_Disconnect(uint8 channel); */
/* void DAC_MUX_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define DAC_MUX_CHANNELS  3u
#define DAC_MUX_MUXTYPE   1
#define DAC_MUX_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define DAC_MUX_NULL_CHANNEL 0xFFu
#define DAC_MUX_MUX_SINGLE   1
#define DAC_MUX_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if DAC_MUX_MUXTYPE == DAC_MUX_MUX_SINGLE
# if !DAC_MUX_ATMOSTONE
#  define DAC_MUX_Connect(channel) DAC_MUX_Set(channel)
# endif
# define DAC_MUX_Disconnect(channel) DAC_MUX_Unset(channel)
#else
# if !DAC_MUX_ATMOSTONE
void DAC_MUX_Connect(uint8 channel) ;
# endif
void DAC_MUX_Disconnect(uint8 channel) ;
#endif

#if DAC_MUX_ATMOSTONE
# define DAC_MUX_Stop() DAC_MUX_DisconnectAll()
# define DAC_MUX_Select(channel) DAC_MUX_FastSelect(channel)
void DAC_MUX_DisconnectAll(void) ;
#else
# define DAC_MUX_Stop() DAC_MUX_Start()
void DAC_MUX_Select(uint8 channel) ;
# define DAC_MUX_DisconnectAll() DAC_MUX_Start()
#endif

#endif /* CY_AMUX_DAC_MUX_H */


/* [] END OF FILE */
