/*******************************************************************************
* File Name: REV_POLARITY.c  
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
#include "REV_POLARITY.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 REV_POLARITY__PORT == 15 && ((REV_POLARITY__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: REV_POLARITY_Write
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
void REV_POLARITY_Write(uint8 value) 
{
    uint8 staticBits = (REV_POLARITY_DR & (uint8)(~REV_POLARITY_MASK));
    REV_POLARITY_DR = staticBits | ((uint8)(value << REV_POLARITY_SHIFT) & REV_POLARITY_MASK);
}


/*******************************************************************************
* Function Name: REV_POLARITY_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  REV_POLARITY_DM_STRONG     Strong Drive 
*  REV_POLARITY_DM_OD_HI      Open Drain, Drives High 
*  REV_POLARITY_DM_OD_LO      Open Drain, Drives Low 
*  REV_POLARITY_DM_RES_UP     Resistive Pull Up 
*  REV_POLARITY_DM_RES_DWN    Resistive Pull Down 
*  REV_POLARITY_DM_RES_UPDWN  Resistive Pull Up/Down 
*  REV_POLARITY_DM_DIG_HIZ    High Impedance Digital 
*  REV_POLARITY_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void REV_POLARITY_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(REV_POLARITY_0, mode);
}


/*******************************************************************************
* Function Name: REV_POLARITY_Read
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
*  Macro REV_POLARITY_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 REV_POLARITY_Read(void) 
{
    return (REV_POLARITY_PS & REV_POLARITY_MASK) >> REV_POLARITY_SHIFT;
}


/*******************************************************************************
* Function Name: REV_POLARITY_ReadDataReg
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
uint8 REV_POLARITY_ReadDataReg(void) 
{
    return (REV_POLARITY_DR & REV_POLARITY_MASK) >> REV_POLARITY_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(REV_POLARITY_INTSTAT) 

    /*******************************************************************************
    * Function Name: REV_POLARITY_ClearInterrupt
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
    uint8 REV_POLARITY_ClearInterrupt(void) 
    {
        return (REV_POLARITY_INTSTAT & REV_POLARITY_MASK) >> REV_POLARITY_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
