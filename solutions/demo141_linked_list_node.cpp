#include <iostream>
#include "ListNode.h"

using std::cout;
using std::endl;

class Solution{
    public:
        bool HasCycle(ListNode *head){
            ListNode *fast = head;
            ListNode *slow = head;
            while(fast != nullptr && fast->next != nullptr){
                fast = fast->next->next;
                slow = slow->next;
                if(fast == slow){
                    return true;
                }
            }
            return false;
        }
};

int main(){
    
    Solution s;

    ListNode *head = new ListNode(2);
    head->next = new ListNode(2);
    ListNode *node = head->next = new ListNode(2);
    node->next = new ListNode(2);
    node->next->next = new ListNode(2);
    node->next->next->next = node;

    cout<<s.HasCycle(head)<<endl;
    return 0;
}
