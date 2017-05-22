/*******************************************************************************
* File Name: Button3.c  
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
#include "Button3.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Button3__PORT == 15 && ((Button3__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Button3_Write
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
void Button3_Write(uint8 value) 
{
    uint8 staticBits = (Button3_DR & (uint8)(~Button3_MASK));
    Button3_DR = staticBits | ((uint8)(value << Button3_SHIFT) & Button3_MASK);
}


/*******************************************************************************
* Function Name: Button3_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Button3_DM_STRONG     Strong Drive 
*  Button3_DM_OD_HI      Open Drain, Drives High 
*  Button3_DM_OD_LO      Open Drain, Drives Low 
*  Button3_DM_RES_UP     Resistive Pull Up 
*  Button3_DM_RES_DWN    Resistive Pull Down 
*  Button3_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Button3_DM_DIG_HIZ    High Impedance Digital 
*  Button3_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Button3_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Button3_0, mode);
}


/*******************************************************************************
* Function Name: Button3_Read
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
*  Macro Button3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Button3_Read(void) 
{
    return (Button3_PS & Button3_MASK) >> Button3_SHIFT;
}


/*******************************************************************************
* Function Name: Button3_ReadDataReg
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
uint8 Button3_ReadDataReg(void) 
{
    return (Button3_DR & Button3_MASK) >> Button3_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Button3_INTSTAT) 

    /*******************************************************************************
    * Function Name: Button3_ClearInterrupt
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
    uint8 Button3_ClearInterrupt(void) 
    {
        return (Button3_INTSTAT & Button3_MASK) >> Button3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
