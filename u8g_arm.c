/*
  
  u8g_arm.c
  

  u8g utility procedures for LPC122x

  Universal 8bit Graphics Library
  
  Copyright (c) 2013, olikraus@gmail.com
  All rights reserved.

  Redistribution and use in source and binary forms, with or without modification, 
  are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this list 
    of conditions and the following disclaimer.
    
  * Redistributions in binary form must reproduce the above copyright notice, this 
    list of conditions and the following disclaimer in the documentation and/or other 
    materials provided with the distribution.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
  CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
  INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
  MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
  NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; 
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER 
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
  STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  

 
  The following delay procedures must be implemented for u8glib. This is done in this file:

  void u8g_Delay(uint16_t val)		Delay by "val" milliseconds
  void u8g_MicroDelay(void)		Delay be one microsecond
  void u8g_10MicroDelay(void)	Delay by 10 microseconds
  
  Additional requirements:
  
      SysTick must be enabled, but SysTick IRQ is not required. Any LOAD values are fine,
      it is prefered to have at least 1ms
      Example:
        SysTick->LOAD = (SystemCoreClock/1000UL*(unsigned long)SYS_TICK_PERIOD_IN_MS) - 1;
	SysTick->VAL = 0;
	SysTick->CTRL = 7;   // enable, generate interrupt (SysTick_Handler), do not divide by 2
*/
#include <device.h>
#include <stdio.h>
#include "u8g_arm.h"

/*========================================================================*/
/* system clock setup for LPC122x */

// uint32_t SystemCoreClock = 12000000;

/*========================================================================*/
/* Generic ARM delay procedure, based on the system timer (SysTick) */

/*
  Delay by the provided number of system ticks.
  The delay must be smaller than the RELOAD value.
  This delay has an imprecision of about +/- 20 system ticks.   
*/

/*========================================================================*/
/*
  The following delay procedures must be implemented for u8glib

  void u8g_Delay(uint16_t val)		Delay by "val" milliseconds
  void u8g_MicroDelay(void)		Delay be one microsecond
  void u8g_10MicroDelay(void)	Delay by 10 microseconds

*/

void u8g_Delay(uint16_t val)
{
    
    CyDelay(val);
}

void u8g_MicroDelay(void)
{
    CyDelayUs(1);
}

void u8g_10MicroDelay(void)
{
    CyDelayUs(10);
}




/*========================================================================*/
/* u8glib com procedure */

/* gps board */
/*
uint16_t u8g_pin_a0 = PIN(0,11);
uint16_t u8g_pin_cs = PIN(0,6);
uint16_t u8g_pin_rst = PIN(0,5);
*/

/* eval board */
uint16_t u8g_pin_a0 = PIN(1,1);
uint16_t u8g_pin_cs = PIN(1,2);
uint16_t u8g_pin_rst = PIN(1,0);


uint8_t u8g_com_hw_spi_fn(u8g_t *u8g, uint8_t msg, uint8_t arg_val, void *arg_ptr)
{
  switch(msg)
  {
    case U8G_COM_MSG_STOP:
      break;
    
    case U8G_COM_MSG_INIT:

       if ( arg_val <= U8G_SPI_CLK_CYCLE_50NS )
      {
	SPIM_Start();   // 50
      }
      else if ( arg_val <= U8G_SPI_CLK_CYCLE_300NS )
      {
	SPIM_Start();   // 300
      }
      else if ( arg_val <= U8G_SPI_CLK_CYCLE_400NS )
      {
	SPIM_Start();   // 400
      }
      else
      {
	SPIM_Start();   // 1200
      }

//      set_gpio_mode(u8g_pin_rst, 1, 0);		/* output, no pullup */
//      set_gpio_mode(u8g_pin_cs, 1, 0);		/* output, no pullup */
//      set_gpio_mode(u8g_pin_a0, 1, 0);		/* output, no pullup */

      u8g_MicroDelay();      
      break;
    
    case U8G_COM_MSG_ADDRESS:                     /* define cmd (arg_val = 0) or data mode (arg_val = 1) */
      u8g_10MicroDelay();
      LCD_A0_Write(arg_val);
      u8g_10MicroDelay();
     break;

    case U8G_COM_MSG_CHIP_SELECT:
      if ( arg_val == 0 )
      {
        /* disable */
	uint8_t i;
	/* this delay is required to avoid that the display is switched off too early --> DOGS102 with LPC1114 */
	for( i = 0; i < 5; i++ )
	  u8g_10MicroDelay();
        LCD_CS_Write(1);
      }
      else
      {
        /* enable */
        LCD_CS_Write(0);
      }
      u8g_MicroDelay();
      break;
      
    case U8G_COM_MSG_RESET:
        LCD_RESET_Write(arg_val);
      u8g_10MicroDelay();
      break;
      
    case U8G_COM_MSG_WRITE_BYTE:
      SPIM_WriteTxData(arg_val);
      u8g_MicroDelay();
      break;
    
    case U8G_COM_MSG_WRITE_SEQ:
    case U8G_COM_MSG_WRITE_SEQ_P:
      {
        register uint8_t *ptr = arg_ptr;
        while( arg_val > 0 )
        {
          SPIM_WriteTxData(*ptr++);
          arg_val--;
        }
      }
      break;
  }
  return 1;
}

