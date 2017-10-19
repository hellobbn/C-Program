//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/19.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
//  Calculator
/* To calculate (1-2) * (4 + 5) */
/* input ' 1 2 - 4 5 + * ' */

#include <stdlib.h>
#include "main.h"
#define MAXOP 100


int getop(char[]);
void push(double);
double pop(void);
int main() {
    int type;
    double op2;
    char s[MAXOP];
    
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("Devided by zero error.\n");
                    return 1;
                }
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error Unknown command input.\n");
                break;
        }
    }
    return 0;
}
