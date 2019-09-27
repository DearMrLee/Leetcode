#include<iostream>
#include "ListNode.h"


class Solution{
public:
    ListNode* DeleteDuplicates(ListNode *head){
        ListNode *curNode = head;
        ListNode *nextNode = nullptr;
        while(curNode != nullptr){
            nextNode = curNode->next;
            while(nextNode != nullptr && nextNode->val == curNode->val){
                nextNode = nextNode->next;
            }
            curNode->next = nextNode;
            curNode = nextNode;
        }
        return head;
    }
};


int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(3);
    head->next->next->next->next->next = new ListNode(4);

    Solution s;
    ListNode *res = s.DeleteDuplicates(head);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;

    return 0;
}
