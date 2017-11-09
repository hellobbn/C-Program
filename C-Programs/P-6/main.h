//
//  main.h
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#ifndef main_h
#define main_h

#include <stdio.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
    int coef;
    int pow;
    Polynomial Next;
};
Polynomial add_poly(Polynomial inP1, Polynomial inP2);
Polynomial poly_multiplication(Polynomial p1, Polynomial p2);
#endif /* main_h */
