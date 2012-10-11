%{
#include <stdio.h>
%}
digit [0-9]

%option noyywrap
%option yylineno

%%
r+{digit}, printf("register:%s\n",yytext );
r+{digit} printf("last register:%s\n",yytext );
add     printf("add:%s\n", yytext);
sub     printf("subtract\n");
and     printf("bitwise-and\n");
or      printf("bitwise-or\n");
xor     printf("bitwise-xor\n");
ashift  printf("arithmetic shift\n");
lshift  printf("logical shift\n");
mul     printf("multiply\n");
cmp     printf("compare\n");
%%

