/*******************************************************************************
* File Name: Push.c  
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
#include "Push.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Push__PORT == 15 && ((Push__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Push_Write
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
void Push_Write(uint8 value) 
{
    uint8 staticBits = (Push_DR & (uint8)(~Push_MASK));
    Push_DR = staticBits | ((uint8)(value << Push_SHIFT) & Push_MASK);
}


/*******************************************************************************
* Function Name: Push_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Push_DM_STRONG     Strong Drive 
*  Push_DM_OD_HI      Open Drain, Drives High 
*  Push_DM_OD_LO      Open Drain, Drives Low 
*  Push_DM_RES_UP     Resistive Pull Up 
*  Push_DM_RES_DWN    Resistive Pull Down 
*  Push_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Push_DM_DIG_HIZ    High Impedance Digital 
*  Push_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Push_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Push_0, mode);
}


/*******************************************************************************
* Function Name: Push_Read
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
*  Macro Push_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Push_Read(void) 
{
    return (Push_PS & Push_MASK) >> Push_SHIFT;
}


/*******************************************************************************
* Function Name: Push_ReadDataReg
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
uint8 Push_ReadDataReg(void) 
{
    return (Push_DR & Push_MASK) >> Push_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Push_INTSTAT) 

    /*******************************************************************************
    * Function Name: Push_ClearInterrupt
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
    uint8 Push_ClearInterrupt(void) 
    {
        return (Push_INTSTAT & Push_MASK) >> Push_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
