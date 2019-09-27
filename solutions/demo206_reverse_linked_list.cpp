#include <iostream>
#include "ListNode.h"

using std::cout;
using std::cin;
using std::endl;

class Solution{
    public:
        ListNode* ReverseList(ListNode *head){
            ListNode *preNode = nullptr;
            ListNode *nextNode = nullptr;
            while(head != nullptr){
                nextNode = head->next;
                head->next = preNode;
                preNode = head;
                head = nextNode;
            }
            return preNode;
        }
};


int main(){

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *res = s.ReverseList(head);

    ListNode *temp = res;
    while(nullptr != temp){
        cout<<temp->val<<", ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}
