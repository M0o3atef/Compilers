%{
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

#include "definitions.h"

/* prototypes */
nodeType *opr(int oper, int nops, ...);
nodeType* conFloat(double value);
nodeType *conInt(int value);
nodeType* conString(char* value);
int defSym(char* name, int type, bool isVar);
int getIndex(char* varName);
nodeType *id(int index);
void freeNode(nodeType *p);
int ex(nodeType *p);
int yylex(void);

void yyerror(char *s);
symbolEntry* sym[MAXNUMOFSYMS];                    /* symbol table */
int nextSymNum = 0;
int yydebug=1;
%}

%union {
    double fValue;              /* Floating deciamal value */
    int iValue;                 /* integer value */
    char* sValue;              /* String value */
    char* varName;             /* variable Name */
    nodeType *nPtr;             /* node pointer */
};

%token <iValue> INTNUM
%token <fValue> FLOATNUM
%token <sValue> QUOTESTRING
%token <varName> IDENTIFIER
%token WHILE FOR REPEAT UNTIL SWITCH CASE DEFAULT IF PRINT DEF AS VAR CONST INT FLOAT STRING
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%left '&'
%left '|'
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list case_stmt case_list defult_stmt logic_list logic_expr

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

stmt:     DEF IDENTIFIER AS INT VAR '=' expr ';'         { $$ = opr(DEF, 2, id(defSym($2, 0, True)), $7); }
        | DEF IDENTIFIER AS FLOAT VAR '=' expr ';'       { $$ = opr(DEF, 2, id(defSym($2, 1, True)), $7); }
        | DEF IDENTIFIER AS STRING VAR '=' expr ';'      { $$ = opr(DEF, 2, id(defSym($2, 2, True)), $7); }
        | DEF IDENTIFIER AS INT CONST '=' expr ';'       { $$ = opr(DEF, 2, id(defSym($2, 0, False)), $7); }
        | DEF IDENTIFIER AS FLOAT CONST '=' expr ';'     { $$ = opr(DEF, 2, id(defSym($2, 1, False)), $7); }
        | DEF IDENTIFIER AS STRING CONST '=' expr ';'    { $$ = opr(DEF, 2, id(defSym($2, 2, False)), $7); }
        |  ';'                                           { $$ = opr(';', 2, NULL, NULL); }
        | PRINT expr ';'                                 { $$ = opr(PRINT, 1, $2); }
        | IDENTIFIER '=' expr ';'                        { $$ = opr('=', 2, id(getIndex($1)), $3); }
        | WHILE '(' logic_list ')' stmt                  { $$ = opr(WHILE, 2, $3, $5); }
        | FOR '(' stmt logic_list  ';' stmt ')' stmt     { $$ = opr(FOR, 4, $3, $4, $6, $8); }
        | REPEAT stmt UNTIL '(' logic_list ')' ';'       { $$ = opr(REPEAT, 2, $5, $2); }
        | SWITCH '(' expr ')' case_stmt                  { $$ = opr(SWITCH, 2, $3, $5); }
        | IF '(' logic_list ')' stmt %prec IFX           { $$ = opr(IF, 2, $3, $5); }
        | IF '(' logic_list ')' stmt ELSE stmt           { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                              { $$ = $2; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

defult_stmt: DEFAULT stmt                                { $$ = opr(DEFAULT, 1, $2) }
        ;

case_stmt:  CASE '(' expr ')' stmt                       { $$ = opr(CASE, 2, $3, $5); }
        |   '{' case_list '}'                            { $$ = $2; }
        |   '{' case_list defult_stmt '}'                { $$ = opr(';', 2, $2, $3) }
        ;

case_list: case_stmt                                     { $$ = $1 }
        |  case_list case_stmt                           { $$ = opr(';', 2, $1, $2) }
        ;


logic_expr:
          expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
        | '(' logic_list ')'    { $$ = $2 }
        ;

logic_list:
            logic_expr                  { $$ = $1 }
        |   logic_list '|' logic_expr   { $$ = opr('|', 2, $1, $3); }
        |   logic_list '&' logic_expr   { $$ = opr('&', 2, $1, $3); }
        ;
expr:
          INTNUM                { $$ = conInt($1); }
        | FLOATNUM              { $$ = conFloat($1); }
        | QUOTESTRING           { $$ = conString($1); }
        | IDENTIFIER            { $$ = id(getIndex($1)); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | '(' expr ')'          { $$ = $2; }
        ;

%%

nodeType* conFloat(double value){
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeFloatCon;
    p->con.fValue = value;

    return p;
} 

nodeType *conInt(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeIntCon;
    p->con.iValue = value;
    //printf("Constant integer = %d", p->con.iValue);
    return p;
}

nodeType* conString(char* value){
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeStringCon;
    p->con.sValue = value;

    return p;
}

char* truncStringAtSpace(char* varChar){
    char* endOfFirst = strchr(varChar, ' ');
    if(endOfFirst == NULL)
        return varChar;
    size_t lengthOfFirst = endOfFirst - varChar;
    char* temp = (char*)malloc((lengthOfFirst + 1) * sizeof(char));
    strncpy(temp, varChar, lengthOfFirst);
    temp[lengthOfFirst] = '\0';
    return temp;
}

int defSym(char* name, int type, bool isVar){
    symbolEntry *s = NULL;
    if(nextSymNum < MAXNUMOFSYMS)
        s = malloc(sizeof(symbolEntry));
    if(s == NULL)
        yyerror("out of memory");
    s->name = truncStringAtSpace(name);
    s->index = nextSymNum;
    s->type = type;
    s->isVar = isVar;
    s->isInitialized = True;
    sym[nextSymNum] = s;
    //printf("Defined Symbol %s of type %d at index %d", s->name, s->type, s->index);
    nextSymNum++;
    return s->index;
}

int getIndex(char* varName){
    char* temp = truncStringAtSpace(varName);
    int i = 0;
    while(i < nextSymNum){
        if(strcmp(sym[i]->name, temp) == 0){
            //printf("Got %s ", temp);
            //printf("Found %s ", sym[i]->name);
            return sym[i]->index;
        }
        i++;
    }
    //printf("Symbol %s not Found\n", varName);
    return -1;
}

nodeType *id(int index) {
    if(index == -1)
        return NULL;
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = index;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}

void freeNode(nodeType *p) {
    int i;

    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}

void yyerror(char *s) {
    fprintf(stdout, "%s\n", s);
}

int main(void) {
    yyparse();
    return 0;
}