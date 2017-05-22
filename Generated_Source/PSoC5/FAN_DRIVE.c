/*******************************************************************************
* File Name: FAN_DRIVE.c  
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
#include "FAN_DRIVE.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 FAN_DRIVE__PORT == 15 && ((FAN_DRIVE__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: FAN_DRIVE_Write
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
void FAN_DRIVE_Write(uint8 value) 
{
    uint8 staticBits = (FAN_DRIVE_DR & (uint8)(~FAN_DRIVE_MASK));
    FAN_DRIVE_DR = staticBits | ((uint8)(value << FAN_DRIVE_SHIFT) & FAN_DRIVE_MASK);
}


/*******************************************************************************
* Function Name: FAN_DRIVE_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  FAN_DRIVE_DM_STRONG     Strong Drive 
*  FAN_DRIVE_DM_OD_HI      Open Drain, Drives High 
*  FAN_DRIVE_DM_OD_LO      Open Drain, Drives Low 
*  FAN_DRIVE_DM_RES_UP     Resistive Pull Up 
*  FAN_DRIVE_DM_RES_DWN    Resistive Pull Down 
*  FAN_DRIVE_DM_RES_UPDWN  Resistive Pull Up/Down 
*  FAN_DRIVE_DM_DIG_HIZ    High Impedance Digital 
*  FAN_DRIVE_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void FAN_DRIVE_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(FAN_DRIVE_0, mode);
}


/*******************************************************************************
* Function Name: FAN_DRIVE_Read
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
*  Macro FAN_DRIVE_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 FAN_DRIVE_Read(void) 
{
    return (FAN_DRIVE_PS & FAN_DRIVE_MASK) >> FAN_DRIVE_SHIFT;
}


/*******************************************************************************
* Function Name: FAN_DRIVE_ReadDataReg
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
uint8 FAN_DRIVE_ReadDataReg(void) 
{
    return (FAN_DRIVE_DR & FAN_DRIVE_MASK) >> FAN_DRIVE_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(FAN_DRIVE_INTSTAT) 

    /*******************************************************************************
    * Function Name: FAN_DRIVE_ClearInterrupt
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
    uint8 FAN_DRIVE_ClearInterrupt(void) 
    {
        return (FAN_DRIVE_INTSTAT & FAN_DRIVE_MASK) >> FAN_DRIVE_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
