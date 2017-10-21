//
//  stack.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/21.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include "P-3.h"

char* cuscalloc(char* s) {
    char *p = NULL;
    
    p = malloc(strlen(s) + 1);
    if (p != NULL) {
        strcpy(p, s);
    }
    return p;
}

struct tree* alloc_for_tree(struct tree* in) {
    return (struct tree*)malloc(sizeof(struct tree));
}
