#include <iostream>
#include <vector>
#include <deque>
#include "TreeNode.h"

using std::vector;
using std::deque;
using std::cout;
using std::endl;


class Solution{
    public:
        vector<vector<int>> levelOrder(TreeNode *root){
            vector<vector<int>> res;
            if(root == nullptr){
                return res;
            }
            deque<TreeNode*> d;
            d.push_back(root);
            vector<int> v;
            while(!d.empty()){
                v.clear();
                int num = d.size();
                for(int i=0;i<num;i++){
                    TreeNode *tempNode = d.front();
                    d.pop_front();
                    v.push_back(tempNode->val);
                    if(tempNode->left != nullptr){
                        d.push_back(tempNode->left);
                    }
                    if(tempNode->right != nullptr){
                        d.push_back(tempNode->right);
                    }
                }
                res.push_back(v);
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
    vector<vector<int>> res = s.levelOrder(root);
    for(auto v:res){
        for(auto n:v){
            cout<<n<<", ";
        }
        cout<<endl;
    }

    return 0;
}
