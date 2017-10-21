//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/21.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
//  A Tree
//  Version: 1.0
//  Updated: 2017/10/21
//

#include "P-3.h"

#define MAXWORD 100

int main(){
    struct tree *root;
    
    int i;
    char word[MAXWORD];
    root = NULL;
    while ((i = readWord(word, MAXWORD)) != EOF) {
        root = addTree(root, word);
    }
    printTree(root);
    
    return 0;
}
