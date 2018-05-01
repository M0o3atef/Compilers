#include <stdio.h>
#include "definitions.h"
#include "yacc.tab.h"

static int lbl;

int exMain(nodeType *p){
    if (!p) return 0;
    int i;
    for (i = 0; i < nextSymNum; i++)
    {
        if (sym[i]->type == 0){ // int
            printf("%s\tDW\n", sym[i]->name);
        }else if (sym[i]->type == 0){ // float
            printf("%s\tDD\n", sym[i]->name);
        }else{ // String
            printf("%s\tDB\n", sym[i]->name);
        }
    }
    ex(p);
    return 0;
}

int ex(nodeType *p) {
    int lbl1, lbl2, lbl3;

    if (!p) return 0;
    switch(p->type) {
    case typeStringCon:       
        printf("\tpush\t\"%s\"\n", p->con.sValue); 
        //printf("String Constant (%s)\n", p->con.sValue);
        break;
    case typeIntCon:
        printf("\tpush\t%d\n", p->con.iValue);
        //printf("Int Constant (%d)\n", p->con.iValue);
        break;
    case typeFloatCon:
        printf("\tpush\t%f\n", p->con.fValue);
        //printf("Float Constant (%f)\n", p->con.fValue);
        break;
    case typeId:
        printf("\tpush\t%s\n", sym[p->id.i]->name);
        //printf("Variable (%s)\n", p->id.i + 'a');
        break;
    case typeOpr:
        switch(p->opr.oper) {
        case WHILE:
            printf("L%03d:\n", lbl1 = lbl++);
            //printf("While Loop, Condition: \n");
            exCondition(p->opr.op[0], lbl2 = lbl++, lbl3 = lbl++); // Condition
            printf("\tjz\tL%03d\n", lbl2);
            //printf("\tWhile Loop, Block: \n");
            printf("L%03d:\n", lbl3);
            ex(p->opr.op[1]); // Body
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case FOR:
            ex(p->opr.op[0]); // Initial Statements
            printf("L%03d:\n", lbl1 = lbl++);
            exCondition(p->opr.op[1], lbl2 = lbl++, lbl3 = lbl++); // Condition
            printf("\tjz\tL%03d\n", lbl2);
            printf("L%03d:\n", lbl3);
            ex(p->opr.op[3]); // Body
            ex(p->opr.op[2]); // After-Body Statements
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case REPEAT:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[1]); // Body
            exCondition(p->opr.op[0], lbl2 = lbl++, lbl1); // Condition
            printf("\tjz\tL%03d\n", lbl2);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            if (p->opr.nops > 2) {
                /* if else */
                exCondition(p->opr.op[0], lbl1 = lbl++, lbl3 = lbl++); // Condition
                printf("\tjz\tL%03d\n", lbl1);
                printf("L%03d:\n", lbl3);
                ex(p->opr.op[1]); // True Body
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]); // False Body
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
                exCondition(p->opr.op[0], lbl1 = lbl++, lbl3 = lbl++); // Condition
                printf("\tjz\tL%03d\n", lbl1);
                printf("L%03d:\n", lbl3);
                ex(p->opr.op[1]); // True Body
                printf("L%03d:\n", lbl1);
            }
            break;
        case SWITCH:
            exCase(p->opr.op[1], p->opr.op[0], lbl2 = lbl++);
            printf("L%03d:\n", lbl2);
            break;
        case PRINT:
            ex(p->opr.op[0]);
            printf("\tprint\n");
            break;
        case '=':
            ex(p->opr.op[1]);
            printf("\tpop\t%s\n", sym[p->opr.op[0]->id.i]->name);
            break;
        case DEF:
            if(p->opr.nops == 2){
                ex(p->opr.op[1]);
                printf("\tpop\t%s\n", sym[p->opr.op[0]->id.i]->name);
            }
            break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch(p->opr.oper) {
            case '+':   printf("\tadd\n"); break;
            case '-':   printf("\tsub\n"); break; 
            case '*':   printf("\tmul\n"); break;
            case '/':   printf("\tdiv\n"); break;
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
            ex(p->opr.op[0]);
            printf("\tcompEQ\n");
            printf("\tjz\tL%03d\n", lbl1 = lbl++);
            ex(p->opr.op[1]);
            printf("\tjmp\tL%03d\n", switchLblNum);
            printf("L%03d:\n", lbl1);
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
            printf("\tjz\tL%03d\n", jmpToIfFalse); // All cases make L equal to lbl
            printf("L%03d:\n", lbl1);
            // If Second Child is AND and it it False, then jmp to jmpToIfFalse as I'm False also
            // Else if Second Child is OR and it is True, then jmp to jmpToIfTrue as I'm True also.
            exCondition(p->opr.op[1], jmpToIfFalse, jmpToIfTrue); // Second Condition
            break;
        case '|':
            lbl1 = lbl++;
            // If First Child is AND and it it False, then jmp to lbl1 (Second Condition),
            // Else if First Child is OR and it is True, then jmp to jmpToIfTrue as I'm True also
            exCondition(p->opr.op[0], lbl1, jmpToIfTrue); // First Condition
            printf("\tjnz\tL%03d\n", jmpToIfTrue); // All cases make L equal to lbl+1
            printf("L%03d:\n", lbl1);
            // If Second Child is AND and it it False, then jmp to jmpToIfFalse as I'm False also
            // Else if Second Child is OR and it is True, then jmp to jmpToIfTrue as I'm True also.
            exCondition(p->opr.op[1], jmpToIfFalse, jmpToIfTrue); // Second Condition
            break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch(p->opr.oper) {
            case '<':   printf("\tcompLT\n"); break;
            case '>':   printf("\tcompGT\n"); break;
            case GE:    printf("\tcompGE\n"); break;
            case LE:    printf("\tcompLE\n"); break;
            case NE:    printf("\tcompNE\n"); break;
            case EQ:    printf("\tcompEQ\n"); break;
            }
    }
    return 0;
}
