#include <stdio.h>
#include "definitions.h"
#include "yacc.tab.h"
#include <string.h>

static int lbl;


int exMain(nodeType *p){
    if(hasNoErrors == False)
        return 0;
    if (!p->opr.op[1]) return 0;
    int i;

    char mainFun[5];
    strcpy(mainFun, "main");
    int mainIndex = 0;
    for (i = 0; i < p->opr.nops; ++i)
        if(strcmp(getIdName(p->opr.op[i]->opr.op[0]), mainFun) == 0)
            mainIndex = i;
    // Execute Main
    printf("_start\t\t\t;tell the linker where to start\n");
    ex(p->opr.op[mainIndex]->opr.op[1]); //p->opr.op[mainIndex]->opr.op[0] is the functions name
    printf("\t\texit\n\n\n");
    // Execute other functions
    for (i = 0; i < p->opr.nops; ++i)
    {
        if(i != mainIndex){
            printf("%s:\t\t\t;Body of function %s\n", getIdName(p->opr.op[i]->opr.op[0]), getIdName(p->opr.op[i]->opr.op[0]));
            ex(p->opr.op[i]->opr.op[1]); //p->opr.op[mainIndex]->opr.op[0] is the functions name
            printf("\tret\n\n");
        }
    }
    // Print the variables
    fprintf(stderr, "%d\n", p->opr.nops);
    printf("section .data:\n");
    for (i = 0; i < nextSymNum; i++)
    {
        if (sym[i]->type == 0){ // int
            printf("\t%s\tDD\n", sym[i]->name);
        }else if (sym[i]->type == 1){ // float
            printf("\t%s\tDQ\n", sym[i]->name);
        }else if(sym[i]->type == 2){ // String
            printf("\t%s\tTimes 100 DB\n", sym[i]->name);
        }
    }
    return 0;
}

int ex(nodeType *p) {
    int lbl1, lbl2, lbl3;

    if (!p) return 0;
    switch(p->type) {
    case typeStringCon:
        printf("\t\tpushS\t\"%s\\0\"\n", p->con.sValue); 
        //printf("String Constant (%s)\n", p->con.sValue);
        break;
    case typeIntCon:
        printf("\t\tpushD\t%d\n", p->con.iValue);
        //printf("Int Constant (%d)\n", p->con.iValue);
        break;
    case typeFloatCon:
        printf("\t\tpushQ\t%f\n", p->con.fValue);
        //printf("Float Constant (%f)\n", p->con.fValue);
        break;
    case typeId:
        if(getIdType(p) == 0)
            printf("\t\tpushD\t%s\n", sym[p->id.i]->name);
        else if(getIdType(p) == 1)
            printf("\t\tpushQ\t%s\n", sym[p->id.i]->name);
        else
            printf("\t\tpushS\t%s\n", sym[p->id.i]->name);
        //printf("Variable (%s)\n", p->id.i + 'a');
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case BODY:
            ex(p->opr.op[0]);
            if(p->opr.nops == 2)
                ex(p->opr.op[1]);
            break;
        case WHILE:
            printf("\tL%03d:\n", lbl1 = lbl++);
            //printf("While Loop, Condition: \n");
            exCondition(p->opr.op[0], lbl2 = lbl++, lbl3 = lbl++); // Condition
            printf("\t\tjz\tL%03d\n", lbl2);
            //printf("\t\tWhile Loop, Block: \n");
            printf("\tL%03d:\n", lbl3);
            ex(p->opr.op[1]); // Body
            printf("\t\tjmp\tL%03d\n", lbl1);
            printf("\tL%03d:\n", lbl2);
            break;
        case FOR:
            ex(p->opr.op[0]); // Initial Statements
            printf("\tL%03d:\n", lbl1 = lbl++);
            exCondition(p->opr.op[1], lbl2 = lbl++, lbl3 = lbl++); // Condition
            printf("\t\tjz\tL%03d\n", lbl2);
            printf("\tL%03d:\n", lbl3);
            ex(p->opr.op[3]); // Body
            ex(p->opr.op[2]); // After-Body Statements
            printf("\t\tjmp\tL%03d\n", lbl1);
            printf("\tL%03d:\n", lbl2);
            break;
        case REPEAT:
            printf("\tL%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[1]); // Body
            exCondition(p->opr.op[0], lbl2 = lbl++, lbl1); // Condition
            printf("\t\tjz\tL%03d\n", lbl2);
            printf("\t\tjmp\tL%03d\n", lbl1);
            printf("\tL%03d:\n", lbl2);
            break;
        case IF:
            if (p->opr.nops > 2) {
                /* if else */
                exCondition(p->opr.op[0], lbl1 = lbl++, lbl3 = lbl++); // Condition
                printf("\t\tjz\tL%03d\n", lbl1);
                printf("\tL%03d:\n", lbl3);
                ex(p->opr.op[1]); // True Body
                printf("\t\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("\tL%03d:\n", lbl1);
                ex(p->opr.op[2]); // False Body
                printf("\tL%03d:\n", lbl2);
            } else {
                /* if */
                exCondition(p->opr.op[0], lbl1 = lbl++, lbl3 = lbl++); // Condition
                printf("\t\tjz\tL%03d\n", lbl1);
                printf("\tL%03d:\n", lbl3);
                ex(p->opr.op[1]); // True Body
                printf("\tL%03d:\n", lbl1);
            }
            break;
        case SWITCH:
            exCase(p->opr.op[1], p->opr.op[0], lbl2 = lbl++);
            printf("\tL%03d:\n", lbl2);
            break;
        case PRINT:
            ex(p->opr.op[0]);
            if(getNodeLevel(p->opr.op[0]) == 0)
                printf("\t\tprintD\n");
            else if(getNodeLevel(p->opr.op[0]) == 1)
                printf("\t\tprintQ\n");
            else
                printf("\t\tprintS\n");

            break;
        case '=':
            //if conversion is needed it is down conversion
            ex(p->opr.op[1]);
            if(getNodeLevel(p->opr.op[0]) < getNodeLevel(p->opr.op[1]))
                printf("\t\tconvQD\n"); //convert from Quadrable to Double
            if(getIdType(p->opr.op[0]) == 0)
                printf("\t\tpopD\t%s\n", getIdName(p->opr.op[0]));
            else if(getIdType(p->opr.op[0]) == 1)
                printf("\t\tpopQ\t%s\n", getIdName(p->opr.op[0]));
            else
                printf("\t\tpopS\t%s\n", getIdName(p->opr.op[0]));
            break;
        case DEF:
            if(p->opr.nops == 2){
                ex(p->opr.op[1]);
                if(getNodeLevel(p->opr.op[0]) < getNodeLevel(p->opr.op[1]))
                    printf("\t\tconvQD\n"); //convert from Quadrable to Double
                else if(getNodeLevel(p->opr.op[0]) > getNodeLevel(p->opr.op[1]))
                    printf("\t\tconvDQ\n"); //convert from Quadrable to Double
                if(getIdType(p->opr.op[0]) == 0)
                    printf("\t\tpopD\t%s\n", getIdName(p->opr.op[0]));
                else if(getIdType(p->opr.op[0]) == 1)
                    printf("\t\tpopQ\t%s\n", getIdName(p->opr.op[0]));
                else
                    printf("\t\tpopS\t%s\n", getIdName(p->opr.op[0]));
            }
            break;
        case CALL:
            printf("\t\tCall %s\n", getIdName(p->opr.op[0]));
            break;
        default:
            // if conversion is needed, then it is an up conversion
            ex(p->opr.op[0]);
            if(p->opr.op[0] != NULL && p->opr.op[1] != NULL &&
               getNodeLevel(p->opr.op[0]) < getNodeLevel(p->opr.op[1]))
                printf("\t\tconvDQ\n"); //convert from Double to Quad
            ex(p->opr.op[1]);
            if(p->opr.op[0] != NULL && p->opr.op[1] != NULL &&
               getNodeLevel(p->opr.op[0]) > getNodeLevel(p->opr.op[1]))
                printf("\t\tconvDQ\n"); //convert from Double to Quad
            switch(p->opr.oper) {
            case '+':
                if(getNodeLevel(p) == 0)
                    printf("\t\taddD\n");
                else
                    printf("\t\taddQ\n");
                break;
            case '-':
                if(getNodeLevel(p) == 0)
                    printf("\t\tsubD\n");
                else
                    printf("\t\tsubQ\n");
                break;
            case '*':
                if(getNodeLevel(p) == 0)
                    printf("\t\tmulD\n");
                else
                    printf("\t\tmulQ\n");
                break;
            case '/':
                if(getNodeLevel(p) == 0)
                    printf("\t\tdivD\n");
                else
                    printf("\t\tdivQ\n");
                break;
            }
        }
    }
    return 0;
}

int exCase(nodeType *p, nodeType* switchExpr, int switchLblNum){
    int lbl1;
    switch(p->opr.oper){
        case CASE:
            //case stmt
            ex(switchExpr);
            if(getNodeLevel(switchExpr) < getNodeLevel(p->opr.op[0]))
                printf("\t\tconvDQ\n"); //convert from Double to Quad
            ex(p->opr.op[0]);
            if(getNodeLevel(switchExpr) > getNodeLevel(p->opr.op[0]))
                printf("\t\tconvDQ\n"); //convert from Double to Quad
            if(getNodeLevel(switchExpr) == 1 || getNodeLevel(p->opr.op[0]) == 1)
                printf("\t\tcompQEQ\n");
            else
                printf("\t\tcompDEQ\n");
            printf("\t\tjz\tL%03d\n", lbl1 = lbl++);
            ex(p->opr.op[1]);
            printf("\t\tjmp\tL%03d\n", switchLblNum);
            printf("\tL%03d:\n", lbl1);
            break;
        case DEFAULT:
            ex(p->opr.op[0]);
            break;
        default:
            exCase(p->opr.op[0], switchExpr, switchLblNum);
            exCase(p->opr.op[1], switchExpr, switchLblNum);
    }
    return 0;
}

int exCondition(nodeType *p, int jmpToIfFalse, int jmpToIfTrue){
    int lbl1;
    switch(p->opr.oper){
        case '&':
            lbl1 = lbl++;
            // If First Child is AND and it it False, then jmp to jmpToIfFalse as I'm False also,
            // Else if First Child is OR and it is True, then jmp to lbl1 (Second Condition)
            exCondition(p->opr.op[0], jmpToIfFalse, lbl1); // First Condition
            printf("\t\tjz\tL%03d\n", jmpToIfFalse); // All cases make L equal to lbl
            printf("\tL%03d:\n", lbl1);
            // If Second Child is AND and it it False, then jmp to jmpToIfFalse as I'm False also
            // Else if Second Child is OR and it is True, then jmp to jmpToIfTrue as I'm True also.
            exCondition(p->opr.op[1], jmpToIfFalse, jmpToIfTrue); // Second Condition
            break;
        case '|':
            lbl1 = lbl++;
            // If First Child is AND and it it False, then jmp to lbl1 (Second Condition),
            // Else if First Child is OR and it is True, then jmp to jmpToIfTrue as I'm True also
            exCondition(p->opr.op[0], lbl1, jmpToIfTrue); // First Condition
            printf("\t\tjnz\tL%03d\n", jmpToIfTrue); // All cases make L equal to lbl+1
            printf("\tL%03d:\n", lbl1);
            // If Second Child is AND and it it False, then jmp to jmpToIfFalse as I'm False also
            // Else if Second Child is OR and it is True, then jmp to jmpToIfTrue as I'm True also.
            exCondition(p->opr.op[1], jmpToIfFalse, jmpToIfTrue); // Second Condition
            break;
        default:
            // if conversion is needed, then it is an up conversion
            ex(p->opr.op[0]);
            if(p->opr.op[0] != NULL && p->opr.op[1] != NULL &&
               getNodeLevel(p->opr.op[0]) < getNodeLevel(p->opr.op[1]))
                printf("\t\tconvDQ\n"); //convert from Double to Quad
            ex(p->opr.op[1]);
            if(p->opr.op[0] != NULL && p->opr.op[1] != NULL &&
               getNodeLevel(p->opr.op[0]) > getNodeLevel(p->opr.op[1]))
                printf("\t\tconvDQ\n"); //convert from Double to Quad
            switch(p->opr.oper) {
            case '<':
                if(getNodeLevel(p) == 0)
                    printf("\t\tcompDLT\n");
                else
                    printf("\t\tcompQLT\n");
                break;
            case '>':
                if(getNodeLevel(p) == 0)
                    printf("\t\tcompDGT\n");
                else
                    printf("\t\tcompQGT\n");
                break;
            case GE:
                if(getNodeLevel(p) == 0)
                    printf("\t\tcompDGE\n");
                else
                    printf("\t\tcompQGE\n");
                break;
            case LE:
                if(getNodeLevel(p) == 0)
                    printf("\t\tcompDLE\n");
                else
                    printf("\t\tcompQLE\n");
                break;
            case NE:
                if(getNodeLevel(p) == 0)
                    printf("\t\tcompDNE\n");
                else
                    printf("\t\tcompQNE\n");
                break;
            case EQ:
                if(getNodeLevel(p) == 0)
                    printf("\t\tcompDEQ\n");
                else
                    printf("\t\tcompQEQ\n");
                break;
            }
    }
    return 0;
}
