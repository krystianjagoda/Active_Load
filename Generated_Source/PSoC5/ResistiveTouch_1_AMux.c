/*******************************************************************************
* File Name: ResistiveTouch_1_AMux.c
* Version 1.80
*
*  Description:
*    This file contains functions for the AMuxSeq.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "ResistiveTouch_1_AMux.h"

uint8 ResistiveTouch_1_AMux_initVar = 0u;


/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_Start
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_AMux_Start(void)
{
    ResistiveTouch_1_AMux_DisconnectAll();
    ResistiveTouch_1_AMux_initVar = 1u;
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_Init
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_AMux_Init(void)
{
    ResistiveTouch_1_AMux_DisconnectAll();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_Stop
********************************************************************************
* Summary:
*  Disconnect all channels. The next time Next is called, channel 0 will be
*  connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_AMux_Stop(void)
{
    ResistiveTouch_1_AMux_DisconnectAll();
}

#if (ResistiveTouch_1_AMux_MUXTYPE == ResistiveTouch_1_AMux_MUX_DIFF)

/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_Next
********************************************************************************
* Summary:
*  Disconnects the previous channel and connects the next one in the sequence.
*  When Next is called for the first time after Init, Start, Enable, Stop, or
*  DisconnectAll, it connects channel 0.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_AMux_Next(void)
{
    ResistiveTouch_1_AMux_CYAMUXSIDE_A_Next();
    ResistiveTouch_1_AMux_CYAMUXSIDE_B_Next();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels. The next time Next is called, channel
*  0 will be connected.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_AMux_DisconnectAll(void)
{
    ResistiveTouch_1_AMux_CYAMUXSIDE_A_DisconnectAll();
    ResistiveTouch_1_AMux_CYAMUXSIDE_B_DisconnectAll();
}


/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 ResistiveTouch_1_AMux_GetChannel(void)
{
    return ResistiveTouch_1_AMux_CYAMUXSIDE_A_curChannel;
}

#else

/*******************************************************************************
* Function Name: ResistiveTouch_1_AMux_GetChannel
********************************************************************************
* Summary:
*  The currently connected channel is retuned. If no channel is connected
*  returns -1.
*
* Parameters:
*  void
*
* Return:
*  The current channel or -1.
*
*******************************************************************************/
int8 ResistiveTouch_1_AMux_GetChannel(void)
{
    return ResistiveTouch_1_AMux_curChannel;
}

#endif


/* [] END OF FILE */
