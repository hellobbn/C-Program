//
//  stack.h
//  C-Programs
//
//  Created by clfbbn on 07/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#include "../P-8/main.h"
#ifdef P_8
#define ElementType pTreeNode
#endif


#define MAxElements 50
#ifndef stack_h
#define stack_h
struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty( Stack S );
int IsFull( Stack S );
Stack CreatStack( int MaxElements );
void DisposeStack( Stack S );
void MakeEmpty( Stack S );
void Push( ElementType X, Stack S );
ElementType Top( Stack S );
ElementType TopAndPop( Stack S );

#endif /* stack_h */

struct StackRecord {
    int Capacity;
    int TopOfStack;
    ElementType* Array;
};
