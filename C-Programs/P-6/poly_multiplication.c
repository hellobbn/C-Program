//
//  poly_multiplication.c
//  C-Programs
//
//  Created by clfbbn on 2017/11/6.
//  Copyright © 2017年 clfbbn. All rights reserved.
//

#include "main.h"
#include "shared_poly.h"

Polynomial findPoly(Polynomial p1, Polynomial target) {
    if (target == NULL) {
        return NULL;
    }
    while(target) {
        if (target->pow == p1->pow) {
            return target;
        }
        if (target->Next == NULL) {
            return NULL;
        }
        if ((target->Next->pow < p1->pow)) {
            return target;
        }
        target = target->Next;
    }
    return target;
}

Polynomial poly_multiplication(Polynomial p1, Polynomial p2) {
    p1 = p1->Next;
    p2 = p2->Next;
    if (p1 == NULL && p2 == NULL) {
        return NULL;
    }
    if (p1 == NULL || p2 == NULL) {
        Polynomial ret = malloc(sizeof(struct PolyNode));
        ret->coef = 0;
        ret->pow = 0;
        ret->Next = NULL;
        return ret;
    }

    Polynomial head, rear;
    Polynomial current, p2_temp;
    Polynomial temp, save;
    rear = (Polynomial)malloc(sizeof(struct PolyNode));
    current = (Polynomial)malloc(sizeof(struct PolyNode));
    rear->Next = NULL;
    head = rear;
    for (; p1; p1 = p1->Next) {
        for (p2_temp = p2; p2_temp; p2_temp = p2_temp->Next) {
            current->coef = p1->coef * p2_temp->coef;
            current->pow = p1->pow + p2_temp->pow;
            //  A. search for the result in current line
            if((temp = findPoly(current, head->Next)) != NULL) {
                //  B. If there is, add it
                if (temp->pow == current->pow) {
                    temp->coef += current->coef;
                } else {
                //  C. If there isn't and it is in the poly, add it
                    save = temp->Next;
                    temp->Next = malloc(sizeof(struct PolyNode));
                    temp->Next->coef = current->coef;
                    temp->Next->pow = current->pow;
                    temp->Next->Next = save;
                }
            } else {
            //  D. Add it to the end
                attach_poly(current->coef, current->pow, &rear);
            }
        }
    }
    temp = head;
    head = head->Next;
    free(temp);
    return head;
}


