//
//  read_poly.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include "main.h"
#include "shared_poly.h"


Polynomial read_poly(void) {
    Polynomial front, end;
    int pow, coef, num;
    end = malloc(sizeof(struct PolyNode));
    front = end;
    end->Next = NULL;
    scanf("%d", &num);                      //  num saved
    for (int i = 0; i < num; ++i) {
        scanf("%d%d", &coef, &pow);
        attach_poly(coef, pow, &end);
    }
//    temp = front;
//    front = front->Next;
//    free(temp);
    return front;
}

void attach_poly(int coefficient, int power, Polynomial* prear) {
    Polynomial P ;
    P = malloc(sizeof(struct PolyNode));
    P->coef = coefficient;
    P->pow = power;
    P->Next = NULL;
    (*prear)->Next = P;
    (*prear) = P;
}

