/*******************************************************************************
* File Name: ResistiveTouch_1.c
* Version 2.0
*
* Description:
*  This file provides the API source code for the Resistive Touch component.
*
* Note:
*
********************************************************************************
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CyLib.h"
#include "ResistiveTouch_1.h"
#include "ResistiveTouch_1_xm.h"
#include "ResistiveTouch_1_xp.h"
#include "ResistiveTouch_1_ym.h"
#include "ResistiveTouch_1_yp.h"

uint8 ResistiveTouch_1_initVar = 0u;
static uint8 ResistiveTouch_1_measurementFlag = 0u;


/*******************************************************************************
* Function Name: ResistiveTouch_1_Init
********************************************************************************
*
* Summary:
*  Calls the Init() function of the ADC and AMux components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_Init(void) 
{
    ResistiveTouch_1_AMux_Init();
    ResistiveTouch_1_ADC_Init();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_Start
********************************************************************************
*
* Summary:
*  Calls Init() if the component has not been initialized before. Calls Enable()
*  to begin the component operation.
*
* Parameters:
*  None
*
* Return:
*  None
* 
* Global variables:
*  ResistiveTouch_1_initVar - Indicates whether the component has been
*                             initialized.
*
*******************************************************************************/
void ResistiveTouch_1_Start(void)  
{
    if(ResistiveTouch_1_initVar == 0u)
    {    
        ResistiveTouch_1_Init();
        ResistiveTouch_1_initVar = 1u;
    }
    ResistiveTouch_1_Enable();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_Stop
********************************************************************************
*
* Summary:
*  Stops the ADC and AMux components.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_Stop(void)  
{
    ResistiveTouch_1_ADC_Stop();
    ResistiveTouch_1_AMux_Stop();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_Enable
********************************************************************************
*
* Summary:
*  Enables the ADC component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_Enable(void)  
{
    ResistiveTouch_1_ADC_Enable();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ActivateX
********************************************************************************
*
* Summary: 
*  Configures the pins to measure the Y-axis.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ActivateX(void) 
{
    /* Pins configuration to measure Y. */
    CyPins_SetPinDriveMode(ResistiveTouch_1_ym_0, PIN_DM_STRONG);
    CyPins_SetPinDriveMode(ResistiveTouch_1_yp_0, PIN_DM_STRONG);
    CyPins_SetPinDriveMode(ResistiveTouch_1_xp_0, PIN_DM_ALG_HIZ);
    CyPins_SetPinDriveMode(ResistiveTouch_1_xm_0, PIN_DM_ALG_HIZ);
    
    /* Switch AMux if channel 0 is not selected. */
    if(ResistiveTouch_1_AMux_GetChannel() != ResistiveTouch_1_AMUX_XP_CHAN)
    {
        ResistiveTouch_1_AMux_Next();
    }
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_ActivateY
********************************************************************************
*
* Summary: 
*  Configures the pins to measure X-axis.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void ResistiveTouch_1_ActivateY(void) 
{
    /* Pins configuration to measure X. */
    CyPins_SetPinDriveMode(ResistiveTouch_1_xm_0, PIN_DM_STRONG);
    CyPins_SetPinDriveMode(ResistiveTouch_1_xp_0, PIN_DM_STRONG);
    CyPins_SetPinDriveMode(ResistiveTouch_1_yp_0, PIN_DM_ALG_HIZ);
    CyPins_SetPinDriveMode(ResistiveTouch_1_ym_0, PIN_DM_ALG_HIZ);
    
    /* Switch AMux if channel 1 is not selected. */
    if(ResistiveTouch_1_AMux_GetChannel() == ResistiveTouch_1_AMUX_XP_CHAN)
    {
        ResistiveTouch_1_AMux_Next();
    }
    /* Switch AMux to channel 1 if AMux is disconnected. */
    else if(ResistiveTouch_1_AMux_GetChannel() == ResistiveTouch_1_AMUX_NO_CHAN)
    {
        ResistiveTouch_1_AMux_Next();
        ResistiveTouch_1_AMux_Next();
    }
    else
    {
        /* Channel 1 is already selected. */
    }
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_TouchDetect
********************************************************************************
*
* Summary:
*  Determines if the screen is touched.
*
* Parameters:
*  None
*
* Return:
*  uint8: The touch state.
*  0 - untouched
*  1 - touched
*
*******************************************************************************/
uint8 ResistiveTouch_1_TouchDetect(void) 
{
    /* Configure x+ pin to detect touch. */
    CyPins_SetPinDriveMode(ResistiveTouch_1_xp_0, PIN_DM_STRONG);

    /* Add delay for signal to stabilize. */
    CyDelayUs(5u);

    CyPins_SetPinDriveMode(ResistiveTouch_1_xp_0, PIN_DM_RES_UP);
    
    /* Switch AMux if channel 0 is not selected. */
    if(ResistiveTouch_1_AMux_GetChannel() != ResistiveTouch_1_AMUX_XP_CHAN)
    {
        ResistiveTouch_1_AMux_Next();
    }

    /* Configure x-, y+ and y- to detect touch. */
    CyPins_SetPinDriveMode(ResistiveTouch_1_xm_0, PIN_DM_ALG_HIZ);
    CyPins_SetPinDriveMode(ResistiveTouch_1_yp_0, PIN_DM_ALG_HIZ);
    CyPins_SetPinDriveMode(ResistiveTouch_1_ym_0, PIN_DM_STRONG);

    /* Add delay for signal to stabilize. The delay is dependant on whether
    * the measurement has been done before touch detect or not.
    */
    if (ResistiveTouch_1_measurementFlag == 0u)
    {
        CyDelayUs(20u);
    }
    else
    {
        ResistiveTouch_1_measurementFlag = 0u;
        CyDelayUs(8u);        
    }
    /* The screen is touched if the measured value is lower than the specified
    * threshold.
    */
    return ((ResistiveTouch_1_Measure() < ResistiveTouch_1_TOUCH_THRESHOLD) ? 1u : 0u);
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_Measure
********************************************************************************
*
* Summary:
*  Returns the result of the ADC conversion. Does not return until ADC
*  conversion is complete.
*
* Parameters:
*  None
*
* Return:
*  int16: the result of the ADC conversion.
*
*******************************************************************************/
int16 ResistiveTouch_1_Measure(void) 
{       
    int16 result;

    /* Trigger the ADC conversion and wait for results (blocking). */
    ResistiveTouch_1_ADC_StartConvert();
    (void)ResistiveTouch_1_ADC_IsEndConversion(ResistiveTouch_1_ADC_WAIT_FOR_RESULT);
    result = ResistiveTouch_1_ADC_GetResult16();

    /* Assert a flag indicating that the measurement has been done. */
    ResistiveTouch_1_measurementFlag = 1u;
    return (result);
}


/* [] END OF FILE */
