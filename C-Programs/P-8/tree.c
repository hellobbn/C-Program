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
    return malloc(sizeof(struct TreeNode));
}

