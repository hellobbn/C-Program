//
//  getch_ungetch.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/19.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include "main.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int c_getch(void) {
    return bufp > 0 ? buf[--bufp] : getchar();
}

void c_ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("%s: Too many characters.\n", __func__);
    } else {
        buf[bufp++] = c;
    }
}
