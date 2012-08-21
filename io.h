#ifndef IO_H
#define IO_H

#include <stdbool.h>
#include <stdint.h>
#include "config.h"

typedef kraken_t (*io_read_func)( kraken_t address );
typedef void    (*io_write_func)( kraken_t address, kraken_t data );

extern io_read_func read_jmptbl[IO_MEM];
extern io_write_func write_jmptbl[IO_MEM];

#endif
