%{
#include <stdlib.h>
#include "definitions.h"
#include "yacc.tab.h"
#include <string.h>
void yyerror(char *);
%}

%%

">="            { return GE; }
"<="            { return LE; }
"=="            { return EQ; }
"!="            { return NE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"repeat"        { return REPEAT; }
"until"         { return UNTIL; }
"switch"        { return SWITCH; }
"case"          { return CASE; }
"default"       { return DEFAULT; }
"if"            { return IF; }
"else"          { return ELSE; }
"print"         { return PRINT; }
"def"           { return DEF; }
"as"            { return AS; }
"var"           { return VAR; }
"const"         { return CONST; }
"int"           { return INT; }
"float"         { return FLOAT; }
"string"        { return STRING; }
[ \t\n]+        {;}       /* ignore whitespace */

[-()<>=+*/;:{}&|.] { return *yytext; }

[a-zA-Z][a-zA-Z0-9_]* {
                        yylval.varName = yytext;
                        return IDENTIFIER;
                     }

0+|0*\.0+   {
                yylval.iValue = atoi(yytext);
                return INTNUM;
            }

[1-9][0-9]* {
                yylval.iValue = atoi(yytext);
                return INTNUM;
            }

[0-9]*\.[0-9]+ {
                yylval.fValue = atof(yytext);
                return FLOATNUM;
            }

\"[^\"]*\"   {
                yylval.sValue = strdup(yytext+1);
                yylval.sValue[yyleng-2] = 0;
                return QUOTESTRING;
            }

.               { yyerror("Unknown character"); }

%%

int yywrap(void) {
    return 1;
}