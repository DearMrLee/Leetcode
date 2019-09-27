#include <iostream>
#include "TreeNode.h"
#include <climits>

using std::cout;
using std::endl;


class Solution{
    public:
        bool isValidBST(TreeNode *root){
            return isValidBST(root, LONG_MIN, LONG_MAX);
        }
        bool isValidBST(TreeNode *root, long min_num, long max_num){
            if(!root){
                return true;
            }
            if(root->val > min_num && root->val < max_num){
                return isValidBST(root->left, min_num, root->val) && isValidBST(root->right, root->val, max_num);
            }else{
                return false;
            }
        }
        
};

int main(){

    return 0;
}
