#include "registers.h"
#include <stdio.h>

register_stack_t registers=
	{
		{{0,0,0,0,0,0,0,0}},
		{0,0}
	};


void print_register_stack( void )
{
size_t i;
for( i = 0; i < NUM_REGISTERS; ++i )
	{
	printf("R%i:%04x\n", i, registers.array[i] );
	}
printf("psr.gt:%i\n", registers.status.gt );
printf("psr.lt:%i\n", registers.status.lt );
}
