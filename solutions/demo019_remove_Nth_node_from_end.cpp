#include <iostream>
#include "ListNode.h"


class Solution{
    public:
        ListNode* RemoveNthFromEnd(ListNode *head, int n){
            if(head == nullptr){
                return head;
            }
            if(n == 0){
                return head;
            }
            ListNode *fast = head;
            ListNode *slow = head;
            ListNode *preNode = nullptr;
            for(int i=0;i<n;i++){
                fast = fast->next;
            }
            while(fast != nullptr){
                preNode = slow;
                fast = fast->next;
                slow = slow->next;
            }
            if(preNode == nullptr){
                head = head->next;  //关键点1
            }else{
                if(slow->next == nullptr){
                    preNode->next = nullptr; //关键点2
                }else{
                    //关键点3
                    slow->val = slow->next->val;
                    slow->next = slow->next->next;
                }
            }
            return head;
        }
};

int main(){
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);

    Solution s;
    int n = 2;
    ListNode *res = s.RemoveNthFromEnd(head, n);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;
    return 0;
}
