/*******************************************************************************
* File Name: PWM_BUZZER.c  
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
#include "PWM_BUZZER.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 PWM_BUZZER__PORT == 15 && ((PWM_BUZZER__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: PWM_BUZZER_Write
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
void PWM_BUZZER_Write(uint8 value) 
{
    uint8 staticBits = (PWM_BUZZER_DR & (uint8)(~PWM_BUZZER_MASK));
    PWM_BUZZER_DR = staticBits | ((uint8)(value << PWM_BUZZER_SHIFT) & PWM_BUZZER_MASK);
}


/*******************************************************************************
* Function Name: PWM_BUZZER_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  PWM_BUZZER_DM_STRONG     Strong Drive 
*  PWM_BUZZER_DM_OD_HI      Open Drain, Drives High 
*  PWM_BUZZER_DM_OD_LO      Open Drain, Drives Low 
*  PWM_BUZZER_DM_RES_UP     Resistive Pull Up 
*  PWM_BUZZER_DM_RES_DWN    Resistive Pull Down 
*  PWM_BUZZER_DM_RES_UPDWN  Resistive Pull Up/Down 
*  PWM_BUZZER_DM_DIG_HIZ    High Impedance Digital 
*  PWM_BUZZER_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void PWM_BUZZER_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(PWM_BUZZER_0, mode);
}


/*******************************************************************************
* Function Name: PWM_BUZZER_Read
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
*  Macro PWM_BUZZER_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 PWM_BUZZER_Read(void) 
{
    return (PWM_BUZZER_PS & PWM_BUZZER_MASK) >> PWM_BUZZER_SHIFT;
}


/*******************************************************************************
* Function Name: PWM_BUZZER_ReadDataReg
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
uint8 PWM_BUZZER_ReadDataReg(void) 
{
    return (PWM_BUZZER_DR & PWM_BUZZER_MASK) >> PWM_BUZZER_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(PWM_BUZZER_INTSTAT) 

    /*******************************************************************************
    * Function Name: PWM_BUZZER_ClearInterrupt
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
    uint8 PWM_BUZZER_ClearInterrupt(void) 
    {
        return (PWM_BUZZER_INTSTAT & PWM_BUZZER_MASK) >> PWM_BUZZER_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
