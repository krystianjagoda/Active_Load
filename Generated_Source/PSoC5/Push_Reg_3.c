/*******************************************************************************
* File Name: Push_Reg_3.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Push_Reg_3.h"

#if !defined(Push_Reg_3_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: Push_Reg_3_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 Push_Reg_3_Read(void) 
{ 
    return Push_Reg_3_Status;
}


/*******************************************************************************
* Function Name: Push_Reg_3_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Push_Reg_3_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Push_Reg_3_Status_Aux_Ctrl |= Push_Reg_3_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Push_Reg_3_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Push_Reg_3_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    Push_Reg_3_Status_Aux_Ctrl &= (uint8)(~Push_Reg_3_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: Push_Reg_3_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void Push_Reg_3_WriteMask(uint8 mask) 
{
    #if(Push_Reg_3_INPUTS < 8u)
    	mask &= ((uint8)(1u << Push_Reg_3_INPUTS) - 1u);
	#endif /* End Push_Reg_3_INPUTS < 8u */
    Push_Reg_3_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: Push_Reg_3_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 Push_Reg_3_ReadMask(void) 
{
    return Push_Reg_3_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
