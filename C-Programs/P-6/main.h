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
void attach_poly(int coefficient, int power, Polynomial* prear);

#endif /* main_h */
