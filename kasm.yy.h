#ifndef KASM_YY_H
#define KASM_YY_H

int yyparse(void);
int yylex(void);
int yywrap()
{
return 1;
}

#endif
