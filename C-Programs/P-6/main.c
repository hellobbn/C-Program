//
//  main.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//
#include "main.h"
Polynomial read_poly(void);
void printPoly(Polynomial P);
int main() {
    Polynomial p1, p2, p_add_fro, p_mul_fro;
    p1 = read_poly();
    p2 = read_poly();
    p_add_fro = add_poly(p1, p2);
    p_mul_fro = poly_multiplication(p1, p2);
    printPoly(p_mul_fro);
    printf("\n");
    printPoly(p_add_fro);
    printf("\n");
    return 0;
}
