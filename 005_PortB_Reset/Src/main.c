#include <stdint.h>
#include <stdio.h>

int main(void)
{
	uint32_t *pResetPortA=(uint32_t*)0x40023810;
	*pResetPortA&=~(1<<1);//clearing the bit
	*pResetPortA|=(1<<1);//resetting port a
	*pResetPortA&=~(1<<1);//release

	for(;;);
}
