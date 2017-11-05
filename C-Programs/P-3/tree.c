//
//  tree.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/21.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include "P-3.h"
#include <string.h>

struct tree* addTree(struct tree* in, char* s) {
    int cond;
    
    if (in == NULL) {
        in = alloc_for_tree(in);
        in->word = cuscalloc(s);
        in->count = 1;
        in->left = NULL;
        in->right = NULL;
    } else if((cond = strcmp(in->word, s)) == 0) {
        in->count += 1;
    } else if(cond > 0) {
        //  in->word is larger, set s to left
        in->left = addTree(in->left, s);
    } else {
        in->right = addTree(in->right, s);
    }
    
    return in;
}

void printTree(struct tree* in) {
    while (in != NULL) {
        printTree(in->left);
        printf("%4d   %s\n", in->count, in->word);
        printTree(in->right);
        return;
    }
}
