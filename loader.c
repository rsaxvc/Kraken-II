#include "loader.h"
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

void load_filename( const char * filename )
{
int fd;
fd = open( filename, O_RDONLY );
if( fd > 0 )
	{
	size_t cnt;
	memset( memory, 0x00, sizeof( memory ) );
	cnt = read( fd, memory, sizeof( memory ) );
	printf("Read %"PRIuPTR" 8-bit bytes from %s, zeroing %"PRIuPTR" 16-bit bytes\n", cnt, filename, sizeof( memory ) - cnt );
	if( cnt % 2 != 0 )
		{
		printf("WARNING:Read odd number of bytes\n");
		}
	close( fd );
	}
else
	{
	printf("Error opening:%s\n", filename );
	exit(5);
	}
}
