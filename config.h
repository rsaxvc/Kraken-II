#ifndef CONFIG_H
#define CONFIG_H

#include <stdint.h>

#define PHYSICAL_MEM (32*1024) //in kraken_t units
#define IO_MEM (4)
#define TOTAL_MEM ( PHYSICAL_MEM + IO_MEM )
#define NUM_REGISTERS 8

typedef uint16_t kraken_t;

#endif
