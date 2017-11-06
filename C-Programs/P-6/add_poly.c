//
//  add_poly.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include "main.h"
#include <stdlib.h>
int compare_poly(Polynomial p1, Polynomial p2);
Polynomial add_poly(Polynomial inP1, Polynomial inP2) {
    Polynomial front, end, temp;
    end = malloc(sizeof(struct PolyNode));
    front = end;
    while (inP1 && inP2) {
        switch (compare_poly(inP1, inP2)) {
            case 1:
                attach_poly(inP1->coef, inP1->pow, &end);
                inP1 = inP1->Next;
                break;
            case -1:
                attach_poly(inP2->coef, inP2->pow, &end);
                inP2 = inP2->Next;
                break;
            case 0:
                attach_poly(inP1->coef + inP2->coef, inP1->pow, &end);
                inP2 = inP2->Next;
                inP1 = inP1->Next;
                break;
        }
    }
    for (; inP1; inP1 = inP1->Next) attach_poly(inP1->coef, inP1->pow, &end);
    for (; inP2; inP2 = inP2->Next) attach_poly(inP2->coef, inP2->pow, &end);
    
    temp = front;
    front = front->Next;
    free(temp);
    return front;
}
int compare_poly(Polynomial p1, Polynomial p2) {
    if (p1->pow > p2->pow) {
        return 1;
    } else if (p1->pow < p2->pow) {
        return -1;
    } else {
        return 0;
    }
}
