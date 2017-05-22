/*******************************************************************************
* File Name: DRIVE_SELECT.c  
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
#include "DRIVE_SELECT.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 DRIVE_SELECT__PORT == 15 && ((DRIVE_SELECT__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: DRIVE_SELECT_Write
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
void DRIVE_SELECT_Write(uint8 value) 
{
    uint8 staticBits = (DRIVE_SELECT_DR & (uint8)(~DRIVE_SELECT_MASK));
    DRIVE_SELECT_DR = staticBits | ((uint8)(value << DRIVE_SELECT_SHIFT) & DRIVE_SELECT_MASK);
}


/*******************************************************************************
* Function Name: DRIVE_SELECT_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  DRIVE_SELECT_DM_STRONG     Strong Drive 
*  DRIVE_SELECT_DM_OD_HI      Open Drain, Drives High 
*  DRIVE_SELECT_DM_OD_LO      Open Drain, Drives Low 
*  DRIVE_SELECT_DM_RES_UP     Resistive Pull Up 
*  DRIVE_SELECT_DM_RES_DWN    Resistive Pull Down 
*  DRIVE_SELECT_DM_RES_UPDWN  Resistive Pull Up/Down 
*  DRIVE_SELECT_DM_DIG_HIZ    High Impedance Digital 
*  DRIVE_SELECT_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void DRIVE_SELECT_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(DRIVE_SELECT_0, mode);
}


/*******************************************************************************
* Function Name: DRIVE_SELECT_Read
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
*  Macro DRIVE_SELECT_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 DRIVE_SELECT_Read(void) 
{
    return (DRIVE_SELECT_PS & DRIVE_SELECT_MASK) >> DRIVE_SELECT_SHIFT;
}


/*******************************************************************************
* Function Name: DRIVE_SELECT_ReadDataReg
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
uint8 DRIVE_SELECT_ReadDataReg(void) 
{
    return (DRIVE_SELECT_DR & DRIVE_SELECT_MASK) >> DRIVE_SELECT_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(DRIVE_SELECT_INTSTAT) 

    /*******************************************************************************
    * Function Name: DRIVE_SELECT_ClearInterrupt
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
    uint8 DRIVE_SELECT_ClearInterrupt(void) 
    {
        return (DRIVE_SELECT_INTSTAT & DRIVE_SELECT_MASK) >> DRIVE_SELECT_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
