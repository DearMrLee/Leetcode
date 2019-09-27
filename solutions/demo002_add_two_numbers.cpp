#include <iostream>
#include "ListNode.h"

class Solution{
    public:
        ListNode* AddTwoNumbers(ListNode *l1, ListNode *l2){
            if(l1 == nullptr){
                return l2;
            }
            if(l2 == nullptr){
                return l1;
            }
            ListNode *head = new ListNode(-1); //链表头
            ListNode *curNode = head;
            int carry = 0; //进位标志
            int a,b;
            while(l1 != nullptr || l2 != nullptr){
                if(l1 == nullptr){
                    a = 0;
                }else{
                    a = l1->val;
                    l1 = l1->next;
                }
                if(l2 == nullptr){
                    b = 0;
                }else{
                    b = l2->val;
                    l2= l2->next;
                }
                curNode->next = new ListNode((a+b+carry)%10);
                curNode = curNode->next;
                carry = (a+b+carry) / 10;
            }
            if(carry > 0){
                curNode->next = new ListNode(1);
            }
            return head->next;
        }
};

int main(){
    ListNode *head1 = new ListNode(9);
    head1->next = new ListNode(9);
    //head1->next->next = new ListNode(9);
    
    ListNode *head2 = new ListNode(5);
    head2->next = new ListNode(6);
    head2->next->next = new ListNode(4);

    Solution s;
    ListNode *sumNode = s.AddTwoNumbers(head1, head2);
    while(sumNode != nullptr){
        std::cout<<sumNode->val<<"->";
        sumNode = sumNode->next;
    }
    std::cout<<std::endl;
    return 0;
}
