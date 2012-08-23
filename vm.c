#include "instruction.h"
#include "mem.h"
#include "registers.h"
#include "vm.h"

#define INIT_PC 0

const char * vm_err_str = "No Error";

bool condition_match( instruction ins )
{
bool retn = false;
switch( ins.cond )
	{
	case COND_GT:
		retn = registers.status.gt;
		break;

	case COND_GTE:
		retn = !registers.status.lt;
		break;

	case COND_LT:
		retn = registers.status.lt;
		break;

	case COND_LTE:
		retn = !registers.status.gt;
		break;

	case COND_EQ:
		retn = !registers.status.lt && !registers.status.gt;
		break;

	case COND_NEQ:
		retn = registers.status.lt || registers.status.gt;
		break;

	case COND_EXECUTE_ALWAYS:
		retn = true;
		break;

	default:
		retn = false;
		break;
	}
return retn;
}

bool instruction_step( void )
{
kraken_t pc;
bool success;
kraken_t next_pc;

pc = registers.names.pc;
next_pc = pc + 1;

success = false;/*assume failure*/
if( address_is_mem( pc ) )
	{
	if( condition_match( *(instruction*)(memory+pc) ) )
		{
		if( ins_is_unary( *(instruction*)(memory+pc) ) )
			{
			instruction_unary ins = *(instruction_unary*)(memory+pc);
			success = true;/*assume success*/
			switch( ins.subopcode )
				{
				case INS_UNARY_ZERO:
					registers.array[ ins.reg1 ] = 0;
					break;

				case INS_UNARY_TERMINATE:
					vm_err_str = "Program exited normally";
					success = false;
					break;

				case INS_UNARY_READ:
					if( address_is_valid( ins.reg2 ) )
						{
						registers.array[ ins.reg1 ] = mem_read( ins.reg2 );
						}
						else
						{
						vm_err_str = "Access violation on memory read";
						success = false;
						}
					break;

				case INS_UNARY_WRITE:
					if( address_is_valid( ins.reg2 ) )
						{
						mem_write( ins.reg2, ins.reg1 );
						}
					else
						{
						vm_err_str = "Access violation on memory write";
						success = false;
						}
					break;

				case INS_UNARY_MOVE:
					registers.array[ ins.reg1 ] = registers.array[ ins.reg2 ];
					break;

				case INS_UNARY_BRANCH:
					next_pc = registers.array[ ins.reg1 ];
					success = true;
					break;

				default:
					vm_err_str = "Unknown instruction";
					success = false;
					break;
				}
			}
		else
			{
			instruction ins = *(instruction*)(memory+pc);
			success = true;/*assume success*/
			switch( ins.opcode )
				{
				case INS_ADD:
					registers.array[ ins.reg1 ] = registers.array[ ins.reg2 ] + registers.array[ ins.reg3 ];
					break;

				case INS_SUB:
					registers.array[ ins.reg1 ] = registers.array[ ins.reg2 ] - registers.array[ ins.reg3 ];
					break;

				case INS_OR:
					registers.array[ ins.reg1 ] = registers.array[ ins.reg2 ] | registers.array[ ins.reg3 ];
					break;

				case INS_AND:
					registers.array[ ins.reg1 ] = registers.array[ ins.reg2 ] & registers.array[ ins.reg3 ];
					break;

				case INS_XOR:
					registers.array[ ins.reg1 ] = registers.array[ ins.reg2 ] ^ registers.array[ ins.reg3 ];
					break;

				default:
					vm_err_str = "Unknown instruction";
					success = false;
					break;
				}
			}
		}
	else
		{
		/*we had nothing to do, and we successfully did it*/
		success = true;
		}
	}
else
	{
	success = false;
	}

registers.names.pc = next_pc;
return success;
}
