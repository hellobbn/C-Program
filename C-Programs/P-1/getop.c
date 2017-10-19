//
//  getop.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/19.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
#include <stdio.h>
#include <ctype.h>
#include "main.h"

int c_getch(void);
void c_ungetch(int);

int getop(char s[]) {
    int i, c;
    
    while ((s[0] = c = c_getch()) == ' ' || c == '\t') ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = c_getch())) ;
    }
    if (c == '.') {
        while (isdigit(s[++i] = c = c_getch())) ;
    }
    s[i] = '\0';
    if (c != EOF) {
        c_ungetch(c);
    }
    return NUMBER;
}
