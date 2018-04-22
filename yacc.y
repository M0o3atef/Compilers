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

%}

%union {
    double fValue;              /* Floating deciamal value */
    int iValue;                 /* integer value */
    char* sValue;              /* String value */
    char* varName;             /* variable Name */
    nodeType *nPtr;             /* node pointer */
};

%token DEF
%token AS
%token VAR
%token CONST
%token INT
%token FLOAT
%token STRING
%token <iValue> INTNUM
%token <fValue> FLOATNUM
%token <sValue> QUOTESTRING
%token <varName> IDENTIFIER
%token WHILE IF PRINT
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type <nPtr> stmt expr stmt_list

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt         { ex($2); freeNode($2); }
        | /* NULL */
        ;

stmt:   DEF IDENTIFIER AS INT VAR '=' expr ';'           { $$ = opr(DEF, 2, id(defSym($2, 0, True)), $7); }
        | DEF IDENTIFIER AS FLOAT VAR '=' expr ';'       { $$ = opr(DEF, 2, id(defSym($2, 1, True)), $7); }
        | DEF IDENTIFIER AS STRING VAR '=' expr ';'      { $$ = opr(DEF, 2, id(defSym($2, 2, True)), $7); }
        | DEF IDENTIFIER AS INT CONST '=' expr ';'       { $$ = opr(DEF, 2, id(defSym($2, 0, False)), $7); }
        | DEF IDENTIFIER AS FLOAT CONST '=' expr ';'     { $$ = opr(DEF, 2, id(defSym($2, 1, False)), $7); }
        | DEF IDENTIFIER AS STRING CONST '=' expr ';'    { $$ = opr(DEF, 2, id(defSym($2, 2, False)), $7); }
        |  ';'                                           { $$ = opr(';', 2, NULL, NULL); }
        | expr ';'                                       { $$ = $1; }
        | PRINT expr ';'                                 { $$ = opr(PRINT, 1, $2); }
        | IDENTIFIER '=' expr ';'                        { $$ = opr('=', 2, id(getIndex($1)), $3); }
        | WHILE '(' expr ')' stmt                        { $$ = opr(WHILE, 2, $3, $5); }
        | IF '(' expr ')' stmt %prec IFX                 { $$ = opr(IF, 2, $3, $5); }
        | IF '(' expr ')' stmt ELSE stmt                 { $$ = opr(IF, 3, $3, $5, $7); }
        | '{' stmt_list '}'                              { $$ = $2; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
        ;

expr:
          INTNUM               { $$ = conInt($1); }
        | FLOATNUM                { $$ = conFloat($1); }
        | QUOTESTRING                { $$ = conString($1); }
        | IDENTIFIER              { $$ = id(getIndex($1)); }
        | '-' expr %prec UMINUS { $$ = opr(UMINUS, 1, $2); }
        | expr '+' expr         { $$ = opr('+', 2, $1, $3); }
        | expr '-' expr         { $$ = opr('-', 2, $1, $3); }
        | expr '*' expr         { $$ = opr('*', 2, $1, $3); }
        | expr '/' expr         { $$ = opr('/', 2, $1, $3); }
        | expr '<' expr         { $$ = opr('<', 2, $1, $3); }
        | expr '>' expr         { $$ = opr('>', 2, $1, $3); }
        | expr GE expr          { $$ = opr(GE, 2, $1, $3); }
        | expr LE expr          { $$ = opr(LE, 2, $1, $3); }
        | expr NE expr          { $$ = opr(NE, 2, $1, $3); }
        | expr EQ expr          { $$ = opr(EQ, 2, $1, $3); }
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
    printf("Constant integer = %d", p->con.iValue);
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

int defSym(char* name, int type, bool isVar){
    symbolEntry *s = NULL;
    if(nextSymNum < MAXNUMOFSYMS)
        s = malloc(sizeof(symbolEntry));
    if(s == NULL)
        yyerror("out of memory");
    char* endOfFirst = strchr(name, ' ');
    size_t lengthOfFirst = endOfFirst - name;
    s->name = (char*)malloc((lengthOfFirst + 1) * sizeof(char));
    strncpy(s->name, name, lengthOfFirst);
    s->name[lengthOfFirst] = '\0';
    s->index = nextSymNum;
    s->type = type;
    s->isVar = isVar;
    sym[nextSymNum] = s;
    //printf("Defined Symbol %s of type %d at index %d", s->name, s->type, s->index);
    nextSymNum++;
    return s->index;
}

int getIndex(char* varName){
    int i = 0;
    while(i < nextSymNum){
        if(strcmp(sym[i]->name, varName) == 0){
            printf("Got %s ", varName);
            printf("Found %s ", sym[i]->name);
            return sym[i]->index;
        }
    }
    return -1;
}

nodeType *id(int index) {
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