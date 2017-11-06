//
//  print_poly.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
#include "main.h"
void printPoly(Polynomial P) {
    while (P) {
        printf("%d %d ", P->coef, P->pow);
        P = P->Next;
    }
}
