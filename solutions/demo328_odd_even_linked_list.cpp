#include <iostream>
#include "ListNode.h"

using std::endl;
using std::cout;


class Solution{
    public:
        ListNode* oddEvenList(ListNode *head){
            if(head == nullptr){
                return head;
            }
            ListNode *head2 = head->next;
            ListNode *odd_list = head; //奇数节点
            ListNode *even_list = head2; //偶数节点
            while(even_list && even_list->next){
                odd_list->next = even_list->next;
                odd_list = odd_list->next;
                even_list->next = odd_list->next;
                even_list = even_list->next;
            }
            odd_list->next = head2;
            return head;
        }
};


int main(){
    
    ListNode *head = new ListNode(2);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(5);
    head->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(7);

    Solution s;
    ListNode *res = s.oddEvenList(head);
    while(res){
        cout<<res->val<<", ";
        res = res->next;
    }
    cout<<endl;
    

    return 0;
}
