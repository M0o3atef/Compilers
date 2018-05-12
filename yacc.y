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
int defSym(char* name, int type, bool isVar, bool isInitialized);
int getIndex(char* varName);
nodeType *id(int index);
void freeNode(nodeType *p);
//extern int ex(nodeType *p);
extern int exMain(nodeType *p);
extern FILE *yyin;
int yylex(void);

void yyerror(char *s);
symbolEntry* sym[MAXNUMOFSYMS];                    /* symbol table */
int nextSymNum = 0;
int yydebug=1;
bool hasNoErrors = True;
%}

%error-verbose

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
%token WHILE FOR REPEAT UNTIL SWITCH CASE DEFAULT IF PRINT DEF AS VAR CONST INT FLOAT STRING FUN
%nonassoc IFX
%nonassoc ELSE

%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%left '&' '|'

%type <nPtr> stmt expr stmt_list case_stmt case_list defult_stmt logic_list logic_expr err_stmt function

%%

program:
        function                { exMain($1); freeNode($1); exit(0); }
        ;

function:
        function stmt         { $$ = opr(FUN, 2, $1, $2); }
        | function err_stmt            {};
        | ;

err_stmt:
      error ';'                                  { hasNoErrors = False; }
    | error '}'                                  { hasNoErrors = False; }
    | error ')'                                  { hasNoErrors = False; }
    | error REPEAT                               { hasNoErrors = False; }
    ;

stmt:
    DEF IDENTIFIER AS INT VAR '=' expr ';'       { $$ = opr(DEF, 2, id(defSym($2, 0, True, True)), $7); }
    | DEF IDENTIFIER AS FLOAT VAR '=' expr ';'   { $$ = opr(DEF, 2, id(defSym($2, 1, True, True)), $7); }
    | DEF IDENTIFIER AS STRING VAR '=' expr ';'  { $$ = opr(DEF, 2, id(defSym($2, 2, True, True)), $7); }
    | DEF IDENTIFIER AS INT VAR ';'              { $$ = opr(DEF, 1, id(defSym($2, 0, True, False))); }
    | DEF IDENTIFIER AS FLOAT VAR ';'            { $$ = opr(DEF, 1, id(defSym($2, 1, True, False))); }
    | DEF IDENTIFIER AS STRING VAR ';'           { $$ = opr(DEF, 1, id(defSym($2, 2, True, False))); }
    | DEF IDENTIFIER AS INT CONST '=' expr ';'   { $$ = opr(DEF, 2, id(defSym($2, 0, False, True)), $7); }
    | DEF IDENTIFIER AS FLOAT CONST '=' expr ';' { $$ = opr(DEF, 2, id(defSym($2, 1, False, True)), $7); }
    | DEF IDENTIFIER AS STRING CONST '=' expr ';'{ $$ = opr(DEF, 2, id(defSym($2, 2, False, True)), $7); }
    |  ';'                                       { $$ = opr(';', 2, NULL, NULL); }
    | PRINT expr ';'                             { $$ = opr(PRINT, 1, $2); }
    | IDENTIFIER '=' expr ';'                    { $$ = opr('=', 2, id(getIndex($1)), $3); }
    | WHILE '(' logic_list ')' stmt              { $$ = opr(WHILE, 2, $3, $5); }
    | FOR '(' stmt logic_list  ';' stmt ')' stmt { $$ = opr(FOR, 4, $3, $4, $6, $8); }
    | REPEAT stmt UNTIL '(' logic_list ')' ';'   { $$ = opr(REPEAT, 2, $5, $2); }
    | SWITCH '(' expr ')' case_stmt              { $$ = opr(SWITCH, 2, $3, $5); }
    | IF '(' logic_list ')' stmt %prec IFX       { $$ = opr(IF, 2, $3, $5); }
    | IF '(' logic_list ')' stmt ELSE stmt       { $$ = opr(IF, 3, $3, $5, $7); }
    | '{' stmt_list '}'                          { $$ = $2; }
    ;

stmt_list:
    stmt                    { $$ = $1; }
    | stmt_list stmt        { $$ = opr(';', 2, $1, $2); }
    ;

defult_stmt: 
    DEFAULT stmt                                     { $$ = opr(DEFAULT, 1, $2) }
    ;

case_stmt:  
    CASE '(' expr ')' stmt                           { $$ = opr(CASE, 2, $3, $5); }
    |   '{' case_list '}'                            { $$ = $2; }
    |   '{' case_list defult_stmt '}'                { $$ = opr(';', 2, $2, $3) }
    ;

case_list: 
    case_stmt                                        { $$ = $1 }
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

int defSym(char* name, int type, bool isVar, bool isInitialized){
    name = truncStringAtSpace(name);
    if(getIndex(name) != -1){
        printf("line %d: Multiple Definition of variable %s\n", yylineno+1, name);
        hasNoErrors = False;
        return -1;
    }
    symbolEntry *s = NULL;
    if(nextSymNum < MAXNUMOFSYMS)
        s = malloc(sizeof(symbolEntry));
    if(s == NULL)
        yyerror("out of memory");
    s->name = name;
    s->index = nextSymNum;
    s->type = type;
    s->isVar = isVar;
    s->isInitialized = isInitialized;
    s->isUsed = False;
    sym[nextSymNum] = s;
    //fprintf(stderr, "Defined Symbol %s of type %d at index %d", s->name, s->type, s->index);
    nextSymNum++;
    return s->index;
}

int getIndex(char* varName){
    // getIndex is used to use the variable, so if it's called then "isUsed" can be used as True
    char* temp = truncStringAtSpace(varName);
    int i = 0;
    while(i < nextSymNum){
        if(strcmp(sym[i]->name, temp) == 0){
            sym[i]->isUsed = True;
            //fprintf(stderr, "Symbol %s Found at index %d\n", varName, i);
            return sym[i]->index; 
        }
        i++;
    }
    //fprintf(stderr, "Symbol %s not Found\n", varName);
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

int getIdType(nodeType* p){
    return sym[p->id.i]->type;
}

bool isIdVar(nodeType* p){
   return sym[p->id.i]->isVar; 
}

bool isIdInitialized(nodeType* p){
   return sym[p->id.i]->isInitialized; 
}

char* getIdName(nodeType* p){
   return sym[p->id.i]->name; 
}


void checkImproperUsage(int oper, int nops, nodeType *p){
    //LHS and RHS of binary arithmetic and logical operators can't be strings and must be initialized
    if(oper == '*' || oper == '/' || oper == '+' || oper == '-' ||
    oper == '<' || oper == '>' || oper == GE || oper == LE || oper == EQ || oper == NE ||
    oper == '&' || oper == '|'){
        if((p->opr.op[0]->type == typeStringCon) || (p->opr.op[1]->type == typeStringCon) ||
        (p->opr.op[0]->type == typeId && getIdType(p->opr.op[0]) == 2) ||
        (p->opr.op[1]->type == typeId && getIdType(p->opr.op[1]) == 2)){
            if(oper == LE || oper == EQ || oper == NE || oper == GE){
                char* op = ">=";
                if(oper == LE)
                    op = "<=";
                else if(oper == EQ)
                    op = "==";
                else if(oper == NE)
                    op = "!=";
                printf("line %d: Operator '%s' can't have string on any of its sides\n", yylineno+1, op);
            }else
                printf("line %d: Operator '%c' can't have string on any of its sides\n", yylineno+1, oper);
            hasNoErrors = False;
        }else if((p->opr.op[0]->type == typeId && isIdInitialized(p->opr.op[0]) == False) ||
        (p->opr.op[1]->type == typeId && isIdInitialized(p->opr.op[1]) == False)){
            if(oper == LE || oper == EQ || oper == NE || oper == GE){
                char* op = ">=";
                if(oper == LE)
                    op = "<=";
                else if(oper == EQ)
                    op = "==";
                else if(oper == NE)
                    op = "!=";
                printf("line %d: Operator '%s' both sides must be initialized\n", yylineno+1, op);
            }else
                printf("line %d: Operator '%c' both sides must be initialized\n", yylineno+1, oper);
            hasNoErrors = False;
        }
    }else if(oper == '='){
        //Constant variables, constant numbers (1, 5.32) and qouteStrings can't be used on LHS
        if((p->opr.op[0]->type == typeId && isIdVar(p->opr.op[0]) == False) ||
        p->opr.op[0]->type == typeStringCon || p->opr.op[0]->type == typeIntCon ||
        p->opr.op[0]->type == typeFloatCon){
            printf("line %d: LHS of '=' must be a variable\n", yylineno+1);
            hasNoErrors = False;
        }else{
            if(getIdType(p->opr.op[0]) == 2){
                // Check if LHS (which is for sure a variable) is string then RHS is also a string
                if(p->opr.op[1]->type != typeStringCon &&
                (p->opr.op[1]->type != typeId || getIdType(p->opr.op[1]) != 2)){
                    printf("line %d: LHS is string, but RHS is not a string\n", yylineno+1);
                    hasNoErrors = False;
                }
            }else if(p->opr.op[1]->type == typeStringCon ||
                (p->opr.op[1]->type == typeId && getIdType(p->opr.op[1]) == 2)){
                // Check if LHS (which is for sure a variable) is not string then RHS can't be a string
                    printf("line %d: LHS is not string, but RHS is a string\n", yylineno+1);
                    hasNoErrors = False;
                }
        }
        // RHS must be initialized
        if(p->opr.op[1]->type == typeId && isIdInitialized(p->opr.op[1]) == False){
            printf("line %d: RHS of operator '=' must be initialized\n", yylineno+1);
            hasNoErrors = False;
        }
    }else if(oper == PRINT){
        // Argument must be initialized if Variable
        if(p->opr.op[0]->type == typeId && isIdInitialized(p->opr.op[0]) == False){
            printf("line %d: Argument of operator 'PRINT' must be initialized\n", yylineno+1);
            hasNoErrors = False;
        }
    }
}

bool checkIfAllDefined(int oper, int nops, nodeType* p){
    bool Ok = True;
    int i;
    if(oper != FUN){
        for (i = 0; i < nops; i++){
            if(p->opr.op[i] == NULL){
                if(oper == LE || oper == EQ || oper == NE || oper == GE || oper == PRINT){
                    char* op = ">=";
                    if(oper == LE)
                        op = "<=";
                    else if(oper == EQ)
                        op = "==";
                    else if(oper == NE)
                        op = "!=";
                    else if(oper == PRINT)
                        op = "Print";
                    printf("line %d: Operator '%s' has undefined variable on one/both of its sides\n", yylineno+1, op);
                }else if(oper == '*' || oper == '/' || oper == '+' || oper == '-' || oper == '<' || oper == '>' || oper == '&' || oper == '|' || oper == '=' || oper == PRINT)
                    printf("line %d: Operator '%c' has undefined variable on one/both of its sides\n", yylineno+1, oper);
                hasNoErrors = False;
                Ok = False;
            }
        }
    }
    return Ok;
}

int getNodeLevel(nodeType* p){
    if(p->type == typeIntCon ||
     (p->type == typeId && getIdType(p) == 0) ||
     (p->type == typeOpr && p->opr.nodeLevel == 0))
        return 0;

    if(p->type == typeFloatCon ||
     (p->type == typeId && getIdType(p) == 1) ||
     (p->type == typeOpr && p->opr.nodeLevel == 1))
        return 1;

    return 2;
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
    p->opr.nodeLevel = 2; // initially

    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    if(checkIfAllDefined(oper, nops, p) == True){
        checkImproperUsage(oper, nops, p);
        if(oper == '*' || oper == '/' || oper == '+' || oper == '-' ||
            oper == '>' || oper == '<' || oper == GE || oper == LE || oper == EQ || oper == NE){
            p->opr.nodeLevel = 0;
            if(getNodeLevel(p->opr.op[0]) == 1 || getNodeLevel(p->opr.op[1]) == 1)
                p->opr.nodeLevel = 1;
        }
        else if(oper == '='){
            // LHS is now initialized
            if(p->opr.op[0]->type == typeId)
                sym[p->opr.op[0]->id.i]->isInitialized = True;
        }
    }
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
    printf("line %d: %s\n", yylineno+1, s);
}

int main(void) {
    // open a file handle to a particular file:
    /*yyin = fopen("input.txt", "r");
    // make sure it is valid:
    if (!yyin) {
        fprintf(stderr, "I can't open input.txt!\n");
        return -1;
    }*/
    
    // parse through the input until there is no more:
    yyparse();
    return 0;
}