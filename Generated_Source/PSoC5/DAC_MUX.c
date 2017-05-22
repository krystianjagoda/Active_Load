/*******************************************************************************
* File Name: DAC_MUX.c
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

#include "DAC_MUX.h"

static uint8 DAC_MUX_lastChannel = DAC_MUX_NULL_CHANNEL;


/*******************************************************************************
* Function Name: DAC_MUX_Start
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
void DAC_MUX_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < DAC_MUX_CHANNELS ; chan++)
    {
#if (DAC_MUX_MUXTYPE == DAC_MUX_MUX_SINGLE)
        DAC_MUX_Unset(chan);
#else
        DAC_MUX_CYAMUXSIDE_A_Unset(chan);
        DAC_MUX_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    DAC_MUX_lastChannel = DAC_MUX_NULL_CHANNEL;
}


#if (!DAC_MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: DAC_MUX_Select
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
void DAC_MUX_Select(uint8 channel) 
{
    DAC_MUX_DisconnectAll();        /* Disconnect all previous connections */
    DAC_MUX_Connect(channel);       /* Make the given selection */
    DAC_MUX_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: DAC_MUX_FastSelect
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
void DAC_MUX_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( DAC_MUX_lastChannel != DAC_MUX_NULL_CHANNEL)
    {
        DAC_MUX_Disconnect(DAC_MUX_lastChannel);
    }

    /* Make the new channel connection */
#if (DAC_MUX_MUXTYPE == DAC_MUX_MUX_SINGLE)
    DAC_MUX_Set(channel);
#else
    DAC_MUX_CYAMUXSIDE_A_Set(channel);
    DAC_MUX_CYAMUXSIDE_B_Set(channel);
#endif


    DAC_MUX_lastChannel = channel;   /* Update last channel */
}


#if (DAC_MUX_MUXTYPE == DAC_MUX_MUX_DIFF)
#if (!DAC_MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: DAC_MUX_Connect
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
void DAC_MUX_Connect(uint8 channel) 
{
    DAC_MUX_CYAMUXSIDE_A_Set(channel);
    DAC_MUX_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: DAC_MUX_Disconnect
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
void DAC_MUX_Disconnect(uint8 channel) 
{
    DAC_MUX_CYAMUXSIDE_A_Unset(channel);
    DAC_MUX_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (DAC_MUX_ATMOSTONE)
/*******************************************************************************
* Function Name: DAC_MUX_DisconnectAll
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
void DAC_MUX_DisconnectAll(void) 
{
    if(DAC_MUX_lastChannel != DAC_MUX_NULL_CHANNEL) 
    {
        DAC_MUX_Disconnect(DAC_MUX_lastChannel);
        DAC_MUX_lastChannel = DAC_MUX_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
