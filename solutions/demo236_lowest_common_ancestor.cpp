#include <iostream>
#include <stack>
#include <vector>

#include "TreeNode.h"

using std::endl;
using std::cout;
using std::stack;
using std::vector;


class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q){
            //方法1：
            if(root == nullptr || root == p || root == q){
                return root;
            }
            TreeNode *left = lowestCommonAncestor(root->left, p, q);
            TreeNode *right = lowestCommonAncestor(root->right, p, q);
            if(left != nullptr && right != nullptr){
                return root;
            }else if(left == nullptr){
                return right;
            }else{
                return left;
            }
            
            //方法2：使用数组记录到p和到q的路径上的点，然后寻找两个数组的最后一个相同的元素
            /*
            vector<TreeNode*> v1;
            vector<TreeNode*> v2;
            GetPath(root, p, v1);
            GetPath(root, q, v2);
            //PrintVector(v1);
            //PrintVector(v2);
            if(v1.empty() || v2.empty()){
                return nullptr;
            }
            //注意：数组是从树的叶节点到根节点记录路径的
            int i=v1.size()-1;
            int j=v2.size()-1;
            while(i>=0 && j>=0){
                if(v1[i] == v2[j]){
                    --i;
                    --j;
                }else{
                    break;
                }
            }
            return v1[i+1]; 
            */

        }
        //记录从根节点到node节点所经过的路径上的节点
        //注意：从下向上记录节点
        bool GetPath(TreeNode *root, TreeNode *node, vector<TreeNode*> &v){
            if(root == nullptr || node == nullptr){
                return false;
            }
            if(root == node){
                v.push_back(root);
                return true;
            }
            if(GetPath(root->left, node, v) || GetPath(root->right, node, v)){
                v.push_back(root);
                return true;
            }
            return false;
        }
        //打印vector元素
        inline void PrintVector(vector<TreeNode*> &v){
            for(auto node: v){
                cout<<node->val<<", ";
            }
            cout<<endl;
        }
};

int main(){
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    TreeNode *p = root->left->right->left = new TreeNode(7);
    TreeNode *q = root->left->right->right = new TreeNode(4);

    Solution s;
    TreeNode *res = s.lowestCommonAncestor(root, p, q);
    cout<<res->val<<endl;

    return 0;
}
