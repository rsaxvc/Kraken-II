#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdbool.h>

typedef struct
	{
	unsigned int opcode:4;
	unsigned int reg1:3;
	unsigned int reg2:3;
	unsigned int reg3:3;
	unsigned int cond:3;
	}instruction_binary;

typedef struct
	{
	unsigned int opcode:4;//ALWAYS INS_UNARY
	unsigned int reg1:3;
	unsigned int reg2:3;
	unsigned int subopcode:3;
	unsigned int cond:3;
	}instruction_unary;

typedef instruction_binary instruction;

bool ins_is_unary( instruction );
bool ins_is_binary( instruction );

enum
	{
	COND_RESERVED_1,
	COND_GT,
	COND_GTE,
	COND_LT,
	COND_LTE,
	COND_EQ,
	COND_NEQ,
	COND_EXECUTE_ALWAYS,
	COND_COUNT
	};

enum
	{
	INS_ADD,
	INS_SUB,
	INS_SHIFT_ARITH,
	INS_SHIFT_LOGIC,
	INS_OR,
	INS_AND,
	INS_XOR,
	INS_MUL,
	INS_RESERVED_1,
	INS_RESERVED_2,
	INS_RESERVED_3,
	INS_RESERVED_4,
	INS_RESERVED_5,
	INS_RESERVED_6,
	INS_RESERVED_7,
	INS_UNARY, //use the next enum
	INS_COUNT
	};

enum
	{
	INS_UNARY_BRANCH,
	INS_UNARY_ZERO,
	INS_UNARY_READ,
	INS_UNARY_WRITE,
	INS_UNARY_MOVE,
	INS_UNARY_LOAD_IMM,
	INS_UNARY_COMPARE,
	INS_UNARY_TERMINATE,
	INS_UNARY_COUNT
	};

#endif
