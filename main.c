#include "mem.h"
#include "loader.h"
#include "registers.h"
#include "vm.h"

#include <stdlib.h>
#include <stdio.h>

int main(int numArgs, const char * args[] )
{
int inscnt = 0;

if( numArgs != 2 )
	{
	printf("usage: %s initmemfile\n", args[0] );
	exit(7);
	}

load_filename( args[1] );

while( instruction_step() )
	{
	inscnt++;
	}
inscnt++;

printf("machine exit due to:%s\n", vm_err_str );
printf("executed %i instructions\n", inscnt );
return 5;
}
