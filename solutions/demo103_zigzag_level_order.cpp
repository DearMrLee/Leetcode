#include <iostream>
#include <vector>
#include <stack>
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::vector;
using std::stack;


class Solution{
    public:
        vector<vector<int>> zigzagLevelOrder(TreeNode *root){
            vector<vector<int>> res;
            if(root == nullptr){
                return res;
            }
            stack<TreeNode*> s1; //保存从左到右的元素
            stack<TreeNode*> s2; //保存从右到左的元素
            s1.push(root);
            vector<int> v;
            int i = 1; //行数
            while(!s1.empty() || !s2.empty()){
                TreeNode *temp = nullptr;
                //从左到右
                while(!s1.empty()){
                    temp = s1.top();
                    s1.pop();
                    v.push_back(temp->val);
                    if(temp->left != nullptr){
                        s2.push(temp->left);
                    }
                    if(temp->right != nullptr){
                        s2.push(temp->right);
                    }
                }
                if(!v.empty()){
                    res.push_back(v);
                    v.clear();
                }
                //从右到左
                while(!s2.empty()){
                    temp = s2.top();
                    s2.pop();
                    v.push_back(temp->val);
                    if(temp->right != nullptr){
                        s1.push(temp->right);
                    }
                    if(temp->left != nullptr){
                        s1.push(temp->left);
                    }
                }
                if(!v.empty()){
                    res.push_back(v);
                    v.clear();
                }
            }
            return res;
        }
};

int main(){
    
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;
    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for(auto v:res){
        for(auto n:v){
            cout<<n<<", ";
        }
        cout<<endl;
    }

    return 0;
}
