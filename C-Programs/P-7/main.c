//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 07/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "misc_shared.h"

int main() {
    char c;
    int lines = 0;
    char left_ops[] = {
        '[', '(', '{',
    };
    char right_ops[] = {
        ']', ')', '}',
    };
    Stack P = CreatStack(MAxElements);
    // legal -> [()] illeagal -> [(])
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            lines ++;
        }
        if (InIt(c, left_ops, sizeof(left_ops)/sizeof(left_ops[0]))) {
            Push(c, P);
        } else if (InIt(c, right_ops, sizeof(right_ops)/sizeof(right_ops[0]))) {
            if (Matchup(c) != TopAndPop(P)) {
                printf("Error Not match!\n");
                exit(1);
            }
        }
    }
    printf("Congratulations.\n");
}
