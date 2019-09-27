#include <iostream>
#include "ListNode.h"


class Solution{
    public:
        ListNode* Partition(ListNode *head, int x){
            ListNode *smallerNode = new ListNode(-1);
            ListNode *biggerNode = new ListNode(-1);

            ListNode *s = smallerNode;
            ListNode *b = biggerNode;
            while(head != nullptr){
                if(head->val < x){
                    s->next = new ListNode(head->val);
                    s = s->next;
                }else{
                    b->next = new ListNode(head->val);
                    b = b->next;
                }
                head = head->next;
            }
            s->next = biggerNode->next;
            return smallerNode->next;
        }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    int x = 3;
    
    ListNode *temp = head;
    while(nullptr != temp){
        std::cout<<temp->val<<", ";
        temp = temp->next;
    }
    std::cout<<std::endl;

    Solution s;
    ListNode *res = s.Partition(head, x);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;

    return 0;
}
