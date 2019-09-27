#include <iostream>
#include <queue>
#include "TreeNode.h"

using namespace std;



class Solution{
    public:
        bool IsSymmetric(TreeNode *root){
            //方法1：递归
            /*
            return IsSymmetric(root, root);
            */

            //方法2：循环
            if(nullptr == root || nullptr == root->left && nullptr == root->right){
                return true;
            }
            queue<TreeNode*> q1; //存储左子树
            q1.push(root->left);
            queue<TreeNode*> q2; //存储右子树
            q2.push(root->right);
            
            TreeNode *node1;
            TreeNode *node2;
            while(!q1.empty() && !q2.empty()){
                node1 = q1.front();
                node2 = q2.front();
                q1.pop();
                q2.pop();
                if(nullptr == node1 || nullptr == node2){
                    if(nullptr == node1 && nullptr == node2){
                        continue;
                    }else{
                        return false;
                    }
                }
                if(node1->val != node2->val){
                    return false;
                }
                //左子树从左到右入队
                q1.push(node1->left);
                q1.push(node1->right);
                //右子树从右到左入队
                q2.push(node2->right);
                q2.push(node2->left);
            }
            if(!q1.empty() || !q2.empty()){
                return false;
            }
            return true;
        }
        bool IsSymmetric(TreeNode *node1, TreeNode *node2){
            if(nullptr == node1 || nullptr == node2){
                if(nullptr == node1 && nullptr == node2){
                    return true;
                }else{
                    return false;
                }
            }
            if(node1->val != node2->val){
                return false;
            }else{
                return IsSymmetric(node1->left, node2->right) && IsSymmetric(node1->right, node2->left);
            }
        }
};


int main(){
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    Solution s;
    cout<<s.IsSymmetric(root)<<endl;
    
}
