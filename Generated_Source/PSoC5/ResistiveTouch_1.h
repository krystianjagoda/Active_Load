/*******************************************************************************
* File Name: ResistiveTouch_1.h
* Version 2.0
*
* Description:
*  This file provides the constants and parameter values for the ResistiveTouch
*  component.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_RESISTIVE_TOUCH_ResistiveTouch_1_H)
#define CY_RESISTIVE_TOUCH_ResistiveTouch_1_H

#include "cytypes.h"
#include "ResistiveTouch_1_ADC.h"
#include "ResistiveTouch_1_AMux.h"


/***************************************
*        Function Prototypes
****************************************/

void ResistiveTouch_1_Start(void) ;
void ResistiveTouch_1_Stop(void) ;
void ResistiveTouch_1_Init(void) ; 
void ResistiveTouch_1_Enable(void) ;
void ResistiveTouch_1_ActivateX(void) ;
void ResistiveTouch_1_ActivateY(void);
int16 ResistiveTouch_1_Measure(void) ;
uint8 ResistiveTouch_1_TouchDetect(void) ;

void ResistiveTouch_1_SaveConfig(void) ;
void ResistiveTouch_1_RestoreConfig(void) ;
void ResistiveTouch_1_Sleep(void) ; 
void ResistiveTouch_1_Wakeup(void) ; 

/* Macros for emWinGraphics Library */
#define CYTOUCH_START()         ResistiveTouch_1_Start() 
#define CYTOUCH_STOP()          ResistiveTouch_1_Stop()
#define CYTOUCH_MEASURE()       ResistiveTouch_1_Measure()
#define CYTOUCH_ACTIVATE_X()    ResistiveTouch_1_ActivateX()
#define CYTOUCH_ACTIVATE_Y()    ResistiveTouch_1_ActivateY()
#define CYTOUCH_TOUCHED()       ResistiveTouch_1_TouchDetect()


/***************************************
*   Variable with external linkage
***************************************/

extern uint8 ResistiveTouch_1_initVar;


/***************************************
*       Constants
***************************************/

/* AMUX channel definitions */
#define ResistiveTouch_1_AMUX_XP_CHAN   (0)
#define ResistiveTouch_1_AMUX_YP_CHAN   (1)
#define ResistiveTouch_1_AMUX_NO_CHAN   (-1)

/* The screen is touched if the measured value is lower than the specified
* threshold.
*/
#define ResistiveTouch_1_TOUCH_THRESHOLD        (0x778)


#endif /* CY_RESIST_TOUCH_ResistiveTouch_1_H */


/* [] END OF FILE */
