//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 09/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//
//  Needed files: All files in P-8 and ../P-7/stack-operations.c
//  Version: 0.1 Aplha
//

#include "main.h"
#define P_8 1
//  Postfix expression like -> a b + c d e + * *
int main() {
    char x[MAXOPS];
    int saver;
    Stack S = CreatStack(MAXOPS);
    while ((saver = c_getch(x)) != EOF) {
        pTreeNode node = MakeNode();
        node->left = NULL;
        node->Right = NULL;
        switch (saver) {
            case NUMBER:
                //  Make a node of number
                node->things->number = (int)atof(x);
                Push(node, S);
                break;
            case OP:
                //  Make a head of two ops -- We need a stack;
                node->things->op = x[0];
                Push(make_tree(TopAndPop(S), TopAndPop(S), node), S);
                break;
            default:
                break;
        }
    }
    
}
