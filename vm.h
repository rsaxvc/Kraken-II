#ifndef VM_H
#define VM_H

#include <stdbool.h>

extern const char * vm_err_str;
bool instruction_step( void );

#endif
