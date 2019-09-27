#include <iostream>
#include <vector>
#include "TreeNode.h"

using namespace std;

class Solution{
    public:
        TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
            if(preorder.empty()){
                return nullptr;
            } 
            return buildTree(preorder, 0, inorder, 0, inorder.size()-1);
        }
        //递归构建二叉树
        //preorder:前序遍历
        //pos:当前根节点位置
        //inorder:中序遍历
        //start:中序遍历开始位置
        //end:中序遍历结束位置
        TreeNode* buildTree(vector<int> &preorder, int pos, vector<int> &inorder, int start, int end){
            if(start > end){
                return nullptr;
            }
            TreeNode *root = new TreeNode(preorder[pos]);
            int mid = start;
            for(;mid<=end;++mid){
                if(inorder[mid] == preorder[pos]){
                    break;
                }
            }
            root->left = buildTree(preorder, pos+1, inorder, start, mid-1);
            root->right = buildTree(preorder, mid-start+1+pos, inorder, mid+1, end);
            return root;
        }
};

int main(){
    
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};

    Solution s;
    TreeNode *root = s.buildTree(preorder, inorder);

    return 0;
}
