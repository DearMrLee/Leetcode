#include <iostream>
#include "ListNode.h"

class Solution{
    public:
        ListNode* ReverseBetween(ListNode *head, int m, int n){
            if(nullptr == head){
                return head;
            }
            ListNode *res = new ListNode(-1);
            res->next = head;
            
            ListNode *tou = res;
            int pos = 1;
            while(pos < m){
                tou = head;
                head = head->next;
                ++pos;
            }
            ListNode *tail = head;
            ListNode *preNode = head;
            ListNode *nextNode = nullptr;

            head = head->next;
            ++pos;
            while(pos <= n){
                nextNode = head->next;
                head->next = preNode;
                preNode = head;
                head = nextNode;
                ++pos;
            }
            tou->next = preNode;
            tail->next = head;
            
            return res->next;

        }
};


int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    
    int m = 3;
    int n = 4;

    Solution s;
    ListNode *res = s.ReverseBetween(head, m, n);
    while(nullptr != res){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;

    return 0;
}
