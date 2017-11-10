//
//  print_poly.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
#include "main.h"
void printPoly(Polynomial P) {
    int cnt = 1;
    while (P) {
        
        if (P->coef == 0) {
            if (P->Next == NULL && cnt == 1) {
                printf("0 0");
                return;
            } else {
                P = P->Next;
                continue;
            }
        }
        if (cnt == 1) {
            printf("%d %d", P->coef, P->pow);
            cnt = 0;
        } else {
            printf(" %d %d", P->coef, P->pow);
        }

        P = P->Next;
    }
}
