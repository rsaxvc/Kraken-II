#include "mem.h"
#include <stdlib.h>

kraken_t memory[ PHYSICAL_MEM ];

bool address_is_mem(   kraken_t address )
{
return address < PHYSICAL_MEM;
}

bool address_is_io(    kraken_t address )
{
return address >= PHYSICAL_MEM && ( address - PHYSICAL_MEM ) < IO_MEM;
}

bool address_is_valid( kraken_t address )
{
return address_is_mem( address ) || address_is_io( address );
}


kraken_t mem_read( kraken_t address )
{
if( address_is_mem( address ) )
	{
	return memory[ address ];
	}
else if( address_is_io( address ) )
	{
	return read_jmptbl[ address - PHYSICAL_MEM ]( address );
	}
else
	{
	exit(2);
	}
}

void mem_write( kraken_t address, kraken_t value )
{
if( address_is_mem( address ) )
	{
	memory[ address ] = value;
	}
else if( address_is_io( address ) )
	{
	write_jmptbl[ address - PHYSICAL_MEM ]( address, value );
	}
else
	{
	exit(3);
	}
}
