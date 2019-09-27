#include <iostream>
#include <stack>
#include <deque>

#include "Node.h"

using std::cout;
using std::endl;
using std::cin;
using std::stack;
using std::deque;


class Solution {
    public:
        Node* connect(Node *root){
            if(root == nullptr){
                return root;
            }             
            Node *node = root;
            deque<Node*> s;
            s.push_back(node);
            while(!s.empty()){
                int n = s.size();
                Node *rightNode = nullptr;
                while(n > 0){
                    Node *temp = s.front();
                    //cout<<temp->val<<", ";
                    s.pop_front();
                    if(temp->left != nullptr){
                        //因为root是满二叉树，所以如果有孩子一定是俩
                        s.push_back(temp->right); 
                        s.push_back(temp->left);
                    }
                    temp->next = rightNode;
                    rightNode = temp;
                    --n;
                }
                //cout<<endl;
            }
            return root;
        }
};


int main(){
    Node *root = new Node(1, nullptr, nullptr, nullptr);
    root->left = new Node(2, nullptr, nullptr, nullptr);
    root->right = new Node(3, nullptr, nullptr, nullptr); 
    root->left->left = new Node(4, nullptr, nullptr, nullptr);
    root->left->right = new Node(5, nullptr, nullptr, nullptr); 
    root->right->left = new Node(6, nullptr, nullptr, nullptr);
    root->right->right = new Node(7, nullptr, nullptr, nullptr); 


    Solution s;
    root = s.connect(root);

    return 0;
}
