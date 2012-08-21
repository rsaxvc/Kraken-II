#include "instruction.h"

bool ins_is_unary( instruction ins )
{
return ins.opcode == INS_UNARY;
}

bool ins_is_binary( instruction ins )
{
return ins.opcode != INS_UNARY;
}
