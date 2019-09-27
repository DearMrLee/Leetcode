#include <iostream>
#include "ListNode.h"

using std::cout;
using std::cin;
using std::endl;


class Solution{
    public:
        void DeleteNode(ListNode *node){
            ListNode *nextNode = node->next;
            node->val = nextNode->val;
            node->next = nextNode->next;
            delete nextNode;
            nextNode = nullptr;
        }
};


int main(){
    
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    
    ListNode *node = new ListNode(4);
    
    head->next->next->next = node;
    head->next->next->next->next = new ListNode(5);

    ListNode *temp = head;
    while(temp != nullptr){
        cout<<temp->val<<", ";
        temp = temp->next;
    }
    cout<<endl;

    Solution s;
    s.DeleteNode(node);

    temp = head;
    while(temp != nullptr){
        cout<<temp->val<<", ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}
