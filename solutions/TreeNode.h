#ifndef _TREENODE_H_
#define _TREENODE_H_

#include <iostream>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(nullptr), right(nullptr){
    }
};

#endif
