//
//  P-3.h
//  C-Programs
//
//  Created by clfbbn on 2017/10/21.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#ifndef P_3_h
#define P_3_h
#include <stdio.h>

struct tree{
    char *word;
    int count;
    struct tree *left;
    struct tree *right;
};

int isword(char c);
char* cuscalloc(char* s);
int readWord(char *s, int maxChar);

struct tree* addTree(struct tree* in, char* s);
struct tree* alloc_for_tree(struct tree* in);
void printTree(struct tree* in);

#endif /* P_3_h */
