/*******************************************************************************
* File Name: VOLTAGE_SELECT.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "VOLTAGE_SELECT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 VOLTAGE_SELECT__PORT == 15 && ((VOLTAGE_SELECT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: VOLTAGE_SELECT_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void VOLTAGE_SELECT_Write(uint8 value) 
{
    uint8 staticBits = (VOLTAGE_SELECT_DR & (uint8)(~VOLTAGE_SELECT_MASK));
    VOLTAGE_SELECT_DR = staticBits | ((uint8)(value << VOLTAGE_SELECT_SHIFT) & VOLTAGE_SELECT_MASK);
}


/*******************************************************************************
* Function Name: VOLTAGE_SELECT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  VOLTAGE_SELECT_DM_STRONG     Strong Drive 
*  VOLTAGE_SELECT_DM_OD_HI      Open Drain, Drives High 
*  VOLTAGE_SELECT_DM_OD_LO      Open Drain, Drives Low 
*  VOLTAGE_SELECT_DM_RES_UP     Resistive Pull Up 
*  VOLTAGE_SELECT_DM_RES_DWN    Resistive Pull Down 
*  VOLTAGE_SELECT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  VOLTAGE_SELECT_DM_DIG_HIZ    High Impedance Digital 
*  VOLTAGE_SELECT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void VOLTAGE_SELECT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(VOLTAGE_SELECT_0, mode);
}


/*******************************************************************************
* Function Name: VOLTAGE_SELECT_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro VOLTAGE_SELECT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 VOLTAGE_SELECT_Read(void) 
{
    return (VOLTAGE_SELECT_PS & VOLTAGE_SELECT_MASK) >> VOLTAGE_SELECT_SHIFT;
}


/*******************************************************************************
* Function Name: VOLTAGE_SELECT_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 VOLTAGE_SELECT_ReadDataReg(void) 
{
    return (VOLTAGE_SELECT_DR & VOLTAGE_SELECT_MASK) >> VOLTAGE_SELECT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(VOLTAGE_SELECT_INTSTAT) 

    /*******************************************************************************
    * Function Name: VOLTAGE_SELECT_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 VOLTAGE_SELECT_ClearInterrupt(void) 
    {
        return (VOLTAGE_SELECT_INTSTAT & VOLTAGE_SELECT_MASK) >> VOLTAGE_SELECT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
