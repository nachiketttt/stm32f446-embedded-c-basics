#include <stdint.h>
#include <stdio.h>
void delay(void)
{
	for(uint32_t i=0;i<300000;i++);
}
int main(void)
{
    uint32_t volatile *const pClkctrlreg = (uint32_t*)0x40023830;
    uint32_t volatile *const pPortAModeReg = (uint32_t*)0x40020000;
    uint32_t volatile *const pPortAOutReg = (uint32_t*)0x40020014;
    uint32_t volatile *const pPortAInReg = (uint32_t*)0x40020010;
    uint32_t volatile *const pPullupDownReg = (uint32_t*)0x4002000C;
    //1. clock enable for gpioa
    *pClkctrlreg|=(1<<0);

    //2. config PA0, PA1, PA4, PA6 as output (rows)
    //a. clr the 0,1,2,3,8,9,12,13 bits
    *pPortAModeReg&=~(0xF<<0);//clearing the 0,1,2,3 bits
    *pPortAModeReg&=~(0x33<<8);//clearing the 9,8,12,13 bits
    //b. setting the bits
    *pPortAModeReg|=(0x5<<0);//setting the 0,1,2,3 bits
    *pPortAModeReg|=(0x11<<8);//setting the 9,8,12,13 bits

    //3. config PA7,PA8,PA9,PA10 as input (columns)
    //clear all the bits from 14 to 21
    *pPortAModeReg&=~(0xFF<<14);

    //4. enable internal pull up resistors for PA7,PA8,PA9,PA10
    *pPullupDownReg&=~(0xFF<<14);
    *pPullupDownReg|=(0x55<<14);
while(1)
{
    //make all rows high
    *pPortAOutReg|=(0x53);
    //make r1 low or pa0 low
    *pPortAOutReg&=~(1<<0);

    //scan the columns
    //check c1(pa7) low or high
    if(!(*pPortAInReg & (1<<7))){
    	//key is pressed
    	delay();
    	printf("1\n");
    }
    //check c2(pa8) low or high
    if(!(*pPortAInReg & (1<<8))){
    	//key is pressed
    	delay();
        printf("2\n");
    }
    //check c3(pa9) low or high
    if(!(*pPortAInReg & (1<<9))){
    	//key is pressed
    	delay();
    	printf("3\n");
    }
    //check c4(pa10) low or high
    if(!(*pPortAInReg & (1<<10))){
    	//key is pressed
    	delay();
    	printf("A\n");
    }
    //make all rows high
    *pPortAOutReg|=(0x53);
    //make r2 low or pa1 low
    *pPortAOutReg&=~(1<<1);
    //scan the columns
    //check c1(pa7) low or high
    if(!(*pPortAInReg & (1<<7))){
    	//key is pressed
    	delay();
    	printf("4\n");
    }
    //check c2(pa8) low or high
    if(!(*pPortAInReg & (1<<8))){
    	//key is pressed
    	delay();
        printf("5\n");
    }
    //check c3(pa9) low or high
    if(!(*pPortAInReg & (1<<9))){
    	//key is pressed
    	delay();
    	printf("6\n");
    }
    //check c4(pa10) low or high
    if(!(*pPortAInReg & (1<<10))){
    	//key is pressed
    	delay();
    	printf("B\n");
    }
    *pPortAOutReg|=(0x53);
    //make r3 low or pa4 low
    *pPortAOutReg&=~(1<<4);
    //scan the columns
    //check c1(pa7) low or high
    if(!(*pPortAInReg & (1<<7))){
    	//key is pressed
    	delay();
    	printf("7\n");
    }
    //check c2(pa8) low or high
    if(!(*pPortAInReg & (1<<8))){
    	//key is pressed
    	delay();
        printf("8\n");
    }
    //check c3(pa9) low or high
    if(!(*pPortAInReg & (1<<9))){
    	//key is pressed
    	delay();
    	printf("9\n");
    }
    //check c4(pa10) low or high
    if(!(*pPortAInReg & (1<<10))){
    	//key is pressed
    	delay();
    	printf("C\n");
    }
    *pPortAOutReg|=(0x53);
    //make r4 low or pa6 low
    *pPortAOutReg&=~(1<<6);
    //scan the columns
    //check c1(pa7) low or high
    if(!(*pPortAInReg & (1<<7))){
    	//key is pressed
    	delay();
    	printf("*\n");
    }
    //check c2(pa8) low or high
    if(!(*pPortAInReg & (1<<8))){
    	//key is pressed
    	delay();
        printf("0\n");
    }
    //check c3(pa9) low or high
    if(!(*pPortAInReg & (1<<9))){
    	//key is pressed
    	delay();
    	printf("#\n");
    }
    //check c4(pa10) low or high
    if(!(*pPortAInReg & (1<<10))){
    	//key is pressed
    	delay();
    	printf("D\n");
    }
}//while loop






}
