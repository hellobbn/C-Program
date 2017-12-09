//
//  tree.h
//  C-Programs
//
//  Created by clfbbn on 09/12/2017.
//  Copyright © 2017 clfbbn. All rights reserved.
//

#ifndef tree_h
#define tree_h
typedef struct TreeNode* pTreeNode;
typedef union thing* pUnionThing;
pTreeNode MakeNode(void);
#endif /* tree_h */

union thing {
    int number;
    char op;
};

struct TreeNode {
    pUnionThing things;
    pTreeNode left;
    pTreeNode Right;
};
