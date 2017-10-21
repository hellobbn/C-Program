//
//  judge.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/21.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include <stdio.h>
#include "P-3.h"
int isword(char c) {
    return (c >= 'A' && c <= 'z') ? 1 : 0;
}
int readWord(char *s, int maxChar) {
    char c;
    int i = 0;
    while ((c = getchar()) == ' ') ;
    if (isword(c)) {
        *(s + i++) = c;
    }
    while (((c = getchar()) != EOF)&& isword(c)) {
        *(s + i++) = c;
    }
    *(s + i) = '\0';
    return i > 0 ? i : EOF;
}
