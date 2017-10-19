//
//  pop_push.c
//  C-Programs
//
//  Created by clfbbn on 2017/10/19.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include <stdio.h>

#define MAXVAL 100      //  MAxmium depth of val stack

int sp = 0;             //  Next free stack position
double vsl[MAXVAL];     //  Stack

void push(double f) {
    if (sp < MAXVAL) {
        vsl[sp++] = f;
    } else {
        printf("Error Stack Full");
    }
}

double pop(void) {
    if (sp > 0) {
        return vsl[--sp];
    } else {
        printf("Error stack Empty\n");
        return 0.0;
    }
}
