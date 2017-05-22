/*******************************************************************************
* File Name: ResistiveTouch_1_ADC_AMux.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "ResistiveTouch_1_ADC_AMux.h"

static uint8 ResistiveTouch_1_ADC_AMux_lastChannel = ResistiveTouch_1_ADC_AMux_NULL_CHANNEL;


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_AMux_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_ADC_AMux_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < ResistiveTouch_1_ADC_AMux_CHANNELS ; chan++)
    {
#if (ResistiveTouch_1_ADC_AMux_MUXTYPE == ResistiveTouch_1_ADC_AMux_MUX_SINGLE)
        ResistiveTouch_1_ADC_AMux_Unset(chan);
#else
        ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_A_Unset(chan);
        ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    ResistiveTouch_1_ADC_AMux_lastChannel = ResistiveTouch_1_ADC_AMux_NULL_CHANNEL;
}


#if (!ResistiveTouch_1_ADC_AMux_ATMOSTONE)
/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_AMux_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_ADC_AMux_Select(uint8 channel) 
{
    ResistiveTouch_1_ADC_AMux_DisconnectAll();        /* Disconnect all previous connections */
    ResistiveTouch_1_ADC_AMux_Connect(channel);       /* Make the given selection */
    ResistiveTouch_1_ADC_AMux_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_AMux_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_ADC_AMux_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( ResistiveTouch_1_ADC_AMux_lastChannel != ResistiveTouch_1_ADC_AMux_NULL_CHANNEL)
    {
        ResistiveTouch_1_ADC_AMux_Disconnect(ResistiveTouch_1_ADC_AMux_lastChannel);
    }

    /* Make the new channel connection */
#if (ResistiveTouch_1_ADC_AMux_MUXTYPE == ResistiveTouch_1_ADC_AMux_MUX_SINGLE)
    ResistiveTouch_1_ADC_AMux_Set(channel);
#else
    ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_A_Set(channel);
    ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_B_Set(channel);
#endif


    ResistiveTouch_1_ADC_AMux_lastChannel = channel;   /* Update last channel */
}


#if (ResistiveTouch_1_ADC_AMux_MUXTYPE == ResistiveTouch_1_ADC_AMux_MUX_DIFF)
#if (!ResistiveTouch_1_ADC_AMux_ATMOSTONE)
/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_AMux_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_ADC_AMux_Connect(uint8 channel) 
{
    ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_A_Set(channel);
    ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_AMux_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_ADC_AMux_Disconnect(uint8 channel) 
{
    ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_A_Unset(channel);
    ResistiveTouch_1_ADC_AMux_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (ResistiveTouch_1_ADC_AMux_ATMOSTONE)
/*******************************************************************************
* Function Name: ResistiveTouch_1_ADC_AMux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void ResistiveTouch_1_ADC_AMux_DisconnectAll(void) 
{
    if(ResistiveTouch_1_ADC_AMux_lastChannel != ResistiveTouch_1_ADC_AMux_NULL_CHANNEL) 
    {
        ResistiveTouch_1_ADC_AMux_Disconnect(ResistiveTouch_1_ADC_AMux_lastChannel);
        ResistiveTouch_1_ADC_AMux_lastChannel = ResistiveTouch_1_ADC_AMux_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
