//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 09/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//
//  Needed files: All files in P-8 and ../P-7/stack-operations.c
//  Version: Not avaliable
//

#include "main.h"
//  Postfix expression like -> a b + c d e + * *
int main() {
    union thing c;         // Used for save op and number
    char x[MAXOPS];
    int saver;
    Stack S = CreatStack(MAXOPS);
    while ((saver = c_getch(x)) != EOF) {
        pTreeNode node = MakeNode();
        
        switch (saver) {
            case NUMBER:
                //  Make a node of number
                node->things->number = (int)atof(x);
                Push(node, S);
                break;
            case OP:
                //  Make a head of two ops -- We need a stack;
                break;
            default:
                break;
        }
    }
    
}
