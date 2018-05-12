#ifndef DEFINITIONS_SEEN
#define DEFINITIONS_SEEN

#define MAXNUMOFSYMS 100


typedef enum { typeIntCon, typeFloatCon, typeStringCon, typeId, typeOpr } nodeEnum;
typedef enum { True, False } bool;


extern int nextSymNum;
int yylineno;
extern bool hasNoErrors;

/* constants */
typedef struct {
    union{
        int iValue;                  /* integar value of constant */
        double fValue;               /* double value of constant */
        char* sValue;               /* string value of constant */
    };
} conNodeType;

/* identifiers */
typedef struct {
    int i;                      /* subscript to sym array */
} idNodeType;

/* operators */
typedef struct {
    int oper;                   /* operator */
    int nops;                   /* number of operands */
    int nodeLevel;              /* 0 if the highest level of variables in the node is int
                                   1 if the highest level of variables in the node is float
                                   2 if it is a string or not an arithmetic operation*/
    struct nodeTypeTag *op[1];  /* operands, extended at runtime */
} oprNodeType;

typedef struct nodeTypeTag {
    nodeEnum type;              /* type of node */
    union {
        conNodeType con;        /* constants */
        idNodeType id;          /* identifiers */
        oprNodeType opr;        /* operators */
    };
} nodeType;

typedef struct{
    char* name;
    int index;
    int type; // 0 int, 1 float, 2 string
    bool isVar; // false const, true variable
    bool isInitialized; // false const, true variable
    bool isUsed;
}symbolEntry;

extern symbolEntry* sym[MAXNUMOFSYMS];

#endif