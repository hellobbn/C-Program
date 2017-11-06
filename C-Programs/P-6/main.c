//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
#include "main.h"
Polynomial read_poly(void);
Polynomial add_poly(Polynomial inP1, Polynomial inP2);
void printPoly(Polynomial P);
int main() {
    Polynomial p1, p2, p_add_fro;
    p1 = read_poly();
    p2 = read_poly();
    p_add_fro = add_poly(p1, p2);
    printPoly(p_add_fro);
}
