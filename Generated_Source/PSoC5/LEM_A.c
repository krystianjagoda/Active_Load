/*******************************************************************************
* File Name: LEM_A.c  
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
#include "LEM_A.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LEM_A__PORT == 15 && ((LEM_A__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LEM_A_Write
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
void LEM_A_Write(uint8 value) 
{
    uint8 staticBits = (LEM_A_DR & (uint8)(~LEM_A_MASK));
    LEM_A_DR = staticBits | ((uint8)(value << LEM_A_SHIFT) & LEM_A_MASK);
}


/*******************************************************************************
* Function Name: LEM_A_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LEM_A_DM_STRONG     Strong Drive 
*  LEM_A_DM_OD_HI      Open Drain, Drives High 
*  LEM_A_DM_OD_LO      Open Drain, Drives Low 
*  LEM_A_DM_RES_UP     Resistive Pull Up 
*  LEM_A_DM_RES_DWN    Resistive Pull Down 
*  LEM_A_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LEM_A_DM_DIG_HIZ    High Impedance Digital 
*  LEM_A_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LEM_A_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LEM_A_0, mode);
}


/*******************************************************************************
* Function Name: LEM_A_Read
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
*  Macro LEM_A_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LEM_A_Read(void) 
{
    return (LEM_A_PS & LEM_A_MASK) >> LEM_A_SHIFT;
}


/*******************************************************************************
* Function Name: LEM_A_ReadDataReg
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
uint8 LEM_A_ReadDataReg(void) 
{
    return (LEM_A_DR & LEM_A_MASK) >> LEM_A_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LEM_A_INTSTAT) 

    /*******************************************************************************
    * Function Name: LEM_A_ClearInterrupt
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
    uint8 LEM_A_ClearInterrupt(void) 
    {
        return (LEM_A_INTSTAT & LEM_A_MASK) >> LEM_A_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
