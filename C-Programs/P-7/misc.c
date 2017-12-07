//
//  misc.c
//  C-Programs
//
//  Created by clfbbn on 07/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include <stdio.h>
#include "stack.h"

int InIt( char x, char* arr, int n) {
    for (int i = 0; i < n; ++ i) {
        if (x == arr[i]) {
            return 1 ;
        }
    }
    return 0;
}

ElementType Matchup(char c) {
    switch (c) {
        case ']':
            return '[';
            break;
        case ')':
            return '(';
            break;
        default:
            break;
    }
    return '{';
}
