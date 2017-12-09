//
//  stack_operation.c
//  C-Programs
//
//  Created by clfbbn on 07/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//


#include "stack.h"

#include <stdio.h>
#include <stdlib.h>


Stack CreatStack( int MaxElements ) {
    Stack P = malloc(sizeof(struct StackRecord));
    P->Array = malloc(sizeof(ElementType) * MaxElements);
    P->Capacity = MaxElements;
    MakeEmpty( P );
    
    return P;
}

void MakeEmpty( Stack S ) {
    S->TopOfStack = -1;
}

void Push( ElementType X, Stack S ) {
    if ((++ S->TopOfStack) == S->Capacity) {
        printf("Error Stack full\n");
        exit(1);
    }
    S->Array[S->TopOfStack] = X;
}

ElementType TopAndPop( Stack S ) {
    return S->Array[S->TopOfStack --];
}
