#include <iostream>
#include <set>
#include <queue>
#include <stack>
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::multiset;
using std::queue;
using std::stack;


class Solution {
    public:
        int _k;
        int ans;
        int cur;

        int kthSmallest(TreeNode *root, int k){
            //方法3：循环，采用栈
            stack<TreeNode*> s;
            int ans;
            int count = 0;
            TreeNode *temp = root;
            while(!s.empty() || temp){
                while(temp){
                    s.push(temp);
                    temp = temp->left;
                }
                temp = s.top();
                s.pop();
                ++count;
                if(count == k){
                    ans = temp->val;
                    break;
                }
                temp = temp->right;
            }
            return ans;

            //方法2：递归的思想，中序遍历
            /*
            _k = k;
            cur = 0;
            inorder(root);
            return ans;
            */

            //方法1：遍历树，保存所有节点的值，然后取倒数第k个
            /*
            multiset<int> ms;
            queue<TreeNode*> q;
            q.push(root);
            while(!q.empty()){
                int num = q.size();
                while(num > 0){
                    TreeNode *temp = q.front();
                    if(temp->left){
                        q.push(temp->left);
                    }
                    if(temp->right){
                        q.push(temp->right);
                    }
                    ms.insert(temp->val);
                    q.pop();
                    --num;
                }
            }
            int res = -1;
            for(multiset<int>::iterator it=ms.begin();k>0;++it,--k){
                res = *it;
            }
            return res;
            */
        }
        void inorder(TreeNode *root){
            if(root == nullptr){
                return;
            }
            inorder(root->left);
            ++cur;
            if(cur == _k){
                ans = root->val;
                return;
            }
            inorder(root->right);
        }

};

int main(){
    
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(1);

    Solution s;
    int k = 4;
    cout<<s.kthSmallest(root, k)<<endl;

    return 0;
}
