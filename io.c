#include "io.h"

#include <stdio.h>
#include <stdlib.h>

static kraken_t console_read( kraken_t address )
{
printf("fixme\n");
return 0;
}

static void console_write( kraken_t address, kraken_t value )
{
printf("%c",value);
}

static size_t vmname_offset;

static kraken_t vmname_read( kraken_t address )
{
static const uint8_t vmname[]="KrakenVM";
kraken_t buffer;

buffer = vmname[ vmname_offset++ ];
if( vmname_offset == sizeof( vmname ) )
	{
	vmname_offset = 0;
	}
return buffer;
}

static void vmname_write( kraken_t address, kraken_t value )
{
vmname_offset = 0;
}

static kraken_t rand_read( kraken_t address )
{
return rand();
}

static void rand_write( kraken_t address, kraken_t value )
{
srand( value );
}

static kraken_t fail_read( kraken_t address )
{
printf("failed to read from address %04x\n", address );
return 0;
}

static void fail_write( kraken_t address, kraken_t value )
{
printf("failed to write from address %04x\n", address );
}

io_read_func read_jmptbl[IO_MEM]=
	{
	console_read,
	vmname_read,
	rand_read,
	fail_read,
	};

io_write_func write_jmptbl[IO_MEM]=
	{
	console_write,
	vmname_write,
	rand_write,
	fail_write
	};
