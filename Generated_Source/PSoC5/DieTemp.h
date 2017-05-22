/*******************************************************************************
* File Name: DieTemp_DieTemp.h
* Version 2.0
*
* Description:
*  Defines the API to acquire the Die Temperature.
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_DIE_TEMP_DieTemp_H)
#define CY_DIE_TEMP_DieTemp_H


#include <cytypes.h>
#include <CyLib.h>
#include <CySpc.h>

#if !defined (CY_PSOC5LP)
    #error Component DieTemp_v2_0 requires cy_boot v3.0 or later
#endif /* (CY_ PSOC5LP) */


/***************************************
*       Function Prototypes
***************************************/

cystatus DieTemp_Start(void)                 ;
cystatus DieTemp_Query(int16 * temperature)  ;
cystatus DieTemp_GetTemp(int16 * temperature);
void DieTemp_Stop(void)                      ;


#endif /* CY_DIE_TEMP_DieTemp_H */


/* [] END OF FILE */



