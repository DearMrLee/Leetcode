#include <iostream>
#include "ListNode.h"

using std::cout;
using std::endl;


class Solution {
    public:
        ListNode* GetIntersectionNode(ListNode *headA, ListNode *headB){
            ListNode *aNode = headA;
            ListNode *bNode = headB;
            while(aNode != nullptr && bNode != nullptr){
                if(aNode == bNode){
                    ListNode *temp = new ListNode(aNode->val);
                    return temp;
                }
                aNode = aNode->next;
                bNode = bNode->next;
                if(aNode == nullptr && bNode == nullptr){
                    return nullptr;
                }
                if(aNode == nullptr){
                    aNode = headB;
                }
                if(bNode == nullptr){
                    bNode = headA;
                }
            }
            return nullptr;
        }

};

int main(){
    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    ListNode *node = headA->next->next = new ListNode(8);
    node->next = new ListNode(4);
    node->next->next = new ListNode(5);

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(0);
    headB->next->next->next = node;

    Solution s;

    ListNode *res = s.GetIntersectionNode(headA, headB);
    cout<<res->val<<endl;

    return 0;
}
