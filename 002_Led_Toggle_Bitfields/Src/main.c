#include <stdint.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
	RCC_AHB1ENR_t volatile *const pClkctrlreg= (RCC_AHB1ENR_t*)0x40023830;

	GPIOx_MODE_t volatile *const pPortAModeReg= (GPIOx_MODE_t*)0x40020000;

	GPIOx_ODR_t volatile *const pPortAOutReg= (GPIOx_ODR_t*)0x40020014;

	//1. Enable the clk for gpioa peripheral in ahb1
	pClkctrlreg->gpioa_en=1;

        //2. Config the mode of gpioa mode reg
        //a. clr the 11th and 10th bit
	pPortAModeReg->pin_5=0;
	
	//b. make 10th bit set to 1
	pPortAModeReg->pin_5=1;
	pPortAOutReg->pin_5=1;
	
	for(;;);
	while(1)
	{
		//3. Set 5th bit of the o/p data register to make i/o pin 5 as high
		pPortAOutReg->pin_5=1;
		//gives delay while led on
		for(uint32_t i=0;i<30000;i++);
		//turn off led
		pPortAOutReg->pin_5=0;
		//gives delay while led off
		for(uint32_t i=0;i<30000;i++);
	}

}
