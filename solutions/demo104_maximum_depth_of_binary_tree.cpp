#include <iostream>
#include "TreeNode.h"

using namespace std;


class Solution{
    public:
        int MaxDepth(TreeNode *root){
            if(nullptr == root){
                return 0;
            }
            return 1+max(MaxDepth(root->left), MaxDepth(root->right));
        }
};



int main(){

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    //root->right = new TreeNode(2);
    //root->right->left = new TreeNode(4);
    //root->right->right = new TreeNode(3);

    Solution s;
    cout<<s.MaxDepth(root)<<endl;



    return 0;
}

