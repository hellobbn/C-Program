//
//  tree.c
//  C-Programs
//
//  Created by clfbbn on 09/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "main.h"

pTreeNode MakeNode(void) {
    pTreeNode T;
    T = malloc(sizeof(struct TreeNode));
    T->things = malloc(sizeof(union thing));
    return T;
}

pTreeNode make_tree(pTreeNode left, pTreeNode right, pTreeNode assester) {
    assester->left = left;
    assester->Right = right;
    return assester;
}
