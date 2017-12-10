//
//  main.h
//  C-Programs
//
//  Created by clfbbn on 09/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//


#ifndef main_h
#define main_h

#define ElementType pTreeNode
#define MAXOPS 100
#define NUMBER 1
#define OP 2
#define P_8 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

int c_getch( char* arr );
int is_digit( char x );
int is_op( char x );
pTreeNode make_tree(pTreeNode left, pTreeNode right, pTreeNode assester);
#endif /* main_h */
