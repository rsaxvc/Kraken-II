#ifndef MEM_H
#define MEM_H

#include <stdbool.h>
#include <stdint.h>

#include "config.h"
#include "io.h"


bool address_is_mem(   kraken_t address );
bool address_is_io(    kraken_t address );
bool address_is_valid( kraken_t address );

extern kraken_t memory[PHYSICAL_MEM];
kraken_t mem_read( kraken_t address );
void mem_write( kraken_t address, kraken_t value );


#endif
