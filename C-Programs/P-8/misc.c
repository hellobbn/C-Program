//
//  misc.c
//  C-Programs
//
//  Created by clfbbn on 09/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include <stdio.h>
#include "main.h"

int c_getch( char* arr ) {
    char c;
    int i = 0;
    while ((c = getchar()) != ' ') {
        if (c == EOF) {
            return EOF;
        }
        *(arr + (i++)) = c;             // save the number or op
    }
    if (is_digit(arr[0])) {
        return NUMBER;
    } else if( is_op(arr[0])) {
        return OP;
    } else {
        return EOF;
    }
}

int is_digit( char x ) {
    if (x >= '0' && x <= '9') {
        return 1;
    }
    return 0;
}

int is_op( char x ) {
    if (x == '*' || x == '+' || x == '-' || x == '/') {
        return 1;
    }
    return 0;
}
