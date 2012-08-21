#ifndef REGISTERS_H
#define REGISTERS_H

#include "config.h"

typedef struct
	{
	kraken_t r0;
	kraken_t r1;
	kraken_t r2;
	kraken_t r3;
	kraken_t r4;
	kraken_t r5;
	kraken_t r6;
	kraken_t pc;
	}register_stack;

typedef struct
	{
	unsigned int gt:1;
	unsigned int lt:1;
	}status_register;

typedef struct
	{
	union
		{
		register_stack names;
		kraken_t array[ NUM_REGISTERS ];
		};
	status_register status;
	}register_stack_t;

register_stack_t registers;

void print_register_stack( void );
#endif
