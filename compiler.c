#include <stdio.h>
#include "definitions.h"
#include "yacc.tab.h"

static int lbl;

int ex(nodeType *p) {
    int lbl1, lbl2;

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
            ex(p->opr.op[0]);
            printf("\tjz\tL%03d\n", lbl2 = lbl++);
            //printf("\tWhile Loop, Block: \n");
            ex(p->opr.op[1]);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case FOR:
            ex(p->opr.op[0]);
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[1]);
            printf("\tjz\tL%03d\n", lbl2 = lbl++);
            ex(p->opr.op[3]);
            ex(p->opr.op[2]);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case REPEAT:
            printf("L%03d:\n", lbl1 = lbl++);
            ex(p->opr.op[1]); //execute block
            ex(p->opr.op[0]); //execute logic
            printf("\tjz\tL%03d\n", lbl2 = lbl++);
            printf("\tjmp\tL%03d\n", lbl1);
            printf("L%03d:\n", lbl2);
            break;
        case IF:
            ex(p->opr.op[0]);
            if (p->opr.nops > 2) {
                /* if else */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
                printf("\tjmp\tL%03d\n", lbl2 = lbl++);
                printf("L%03d:\n", lbl1);
                ex(p->opr.op[2]);
                printf("L%03d:\n", lbl2);
            } else {
                /* if */
                printf("\tjz\tL%03d\n", lbl1 = lbl++);
                ex(p->opr.op[1]);
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
            ex(p->opr.op[1]);
            printf("\tpop\t%s\n", sym[p->opr.op[0]->id.i]->name);
            break;
        default:
            ex(p->opr.op[0]);
            ex(p->opr.op[1]);
            switch(p->opr.oper) {
            case '+':   printf("\tadd\n"); break;
            case '-':   printf("\tsub\n"); break; 
            case '*':   printf("\tmul\n"); break;
            case '/':   printf("\tdiv\n"); break;
            case '<':   printf("\tcompLT\n"); break;
            case '>':   printf("\tcompGT\n"); break;
            case GE:    printf("\tcompGE\n"); break;
            case LE:    printf("\tcompLE\n"); break;
            case NE:    printf("\tcompNE\n"); break;
            case EQ:    printf("\tcompEQ\n"); break;
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
}
