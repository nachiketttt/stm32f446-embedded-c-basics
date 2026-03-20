#include <stdint.h>
#include <stdio.h>
int main(void)
{
    uint32_t *pClkctrlreg = (uint32_t*)0x40023830;
    uint32_t *pPortAModeReg = (uint32_t*)0x40020000;
    uint32_t *pPortAOutReg = (uint32_t*)0x40020014;

    //1. Enable the clk for gpioa peripheral in ahb1
    *pClkctrlreg|=(1<<0);

    //2. Config the mode of gpioa mode reg
    //a. clr the 11th and 10th bit
    *pPortAModeReg &=~(3<<10);
    //b. make 10th bit set to 1
    *pPortAModeReg |=(1<<10);
    while(1)
    {
		//3. Set 5th bit of the o/p data register to make i/o pin 5 as high
		*pPortAOutReg|=(1<<5);
		//gives delay while led on
		for(uint32_t i=0;i<300000;i++);
		//turn off led
		*pPortAOutReg&=~(1<<5);
		//gives delay while led off
		for(uint32_t i=0;i<300000;i++);
    }
}
