#include <iostream>
#include "ListNode.h"

class Solution{
    public:
        ListNode* MergeTwoLists(ListNode *l1, ListNode *l2){
            //方法2
            ListNode *head = new ListNode(-1);
            ListNode *temp = head;
            while(l1 != nullptr || l2 != nullptr){
                if(l1 == nullptr){
                    temp->next = l2;
                    temp = temp->next;
                    l2 = l2->next;
                    continue;
                }
                if(l2 == nullptr){
                    temp->next = l1;
                    temp = temp->next;
                    l1 = l1->next;
                    continue;
                }
                if(l1->val <= l2->val){
                    temp->next = l1;
                    temp = temp->next;
                    l1 = l1->next;
                }else{
                    temp->next = l2;
                    temp = temp->next;
                    l2 = l2->next;
                }
            }
            return head->next;

            //方法1，空间复杂度较高
            /*
            ListNode *head = new ListNode(-1);
            ListNode *temp = head;
            while(l1 != nullptr || l2 != nullptr){
                if(l1 == nullptr){
                    temp->next = new ListNode(l2->val);
                    temp = temp->next;
                    l2 = l2->next;
                    continue;
                }
                if(l2 == nullptr){
                    temp->next = new ListNode(l1->val);
                    temp = temp->next;
                    l1 = l1->next;
                    continue;
                }
                if(l1->val <= l2->val){
                    temp->next = new ListNode(l1->val);
                    temp = temp->next;
                    l1 = l1->next;
                }else{
                    temp->next = new ListNode(l2->val);
                    temp = temp->next;
                    l2 = l2->next;
                }
            }
            return head->next;
            */
        }
};

int main(){
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    
    Solution s;
    ListNode *res = s.MergeTwoLists(head1, head2);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;

    return 0;
}
