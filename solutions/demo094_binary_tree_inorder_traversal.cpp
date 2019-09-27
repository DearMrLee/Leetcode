#include <iostream>
#include "TreeNode.h"
#include <vector>
#include <stack>

using std::vector;
using std::stack;
using std::cout;
using std::endl;

class Solution{
    public:
        vector<int> InorderTraversal(TreeNode *root){
            vector<int> vInorder;
            if(root == nullptr){
                return vInorder;
            }
            stack<TreeNode*> sRootNode;
            sRootNode.push(root);
            while(!sRootNode.empty()){
                TreeNode *node = sRootNode.top();
                if(node->left != nullptr){
                    sRootNode.push(node->left);
                    node->left = nullptr;
                }else{
                    vInorder.push_back(node->val);
                    sRootNode.pop();
                    if(node->right != nullptr){
                        sRootNode.push(node->right);
                    }
                }
            }
            return vInorder;
        }
};

int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    //root->right = new TreeNode(3);
    //root->left->left = new TreeNode(4);
    //root->left->right = new TreeNode(5);
    //root->right->right = new TreeNode(6);

    Solution s;
    vector<int> vInorder = s.InorderTraversal(root);
    for(int i=0;i<vInorder.size();i++){
        cout<<vInorder[i]<<", ";
    }
    cout<<endl;


    

    return 0;
}
