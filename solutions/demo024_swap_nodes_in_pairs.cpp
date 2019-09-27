#include <iostream>
#include "ListNode.h"

class Solution{
    public:
        ListNode* SwapPairs(ListNode *head){
            //方法2：直接交换
            ListNode *preNode = nullptr;
            ListNode *node = head;
            ListNode *nextNode;
            while(node != nullptr){
                nextNode = node->next;
                if(nextNode != nullptr){
                    node->next = nextNode->next;
                    if(preNode == nullptr){
                        preNode = nextNode;
                        head = preNode;
                    }else{
                        preNode->next = nextNode;
                    }
                    nextNode->next = node;
                    preNode = node;
                    node = node->next;
                }else{
                    break;
                }
            }
            return head;
            
            //方法1：分割为奇数链表和偶数链表，然后再合并
            /*
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            ListNode *head2 = head->next;

            ListNode *node1 = head;
            ListNode *node2 = head2;
            
            int pos = 1;
            ListNode *temp = head2->next;
            while(node1 != nullptr && node2 != nullptr){
                if(pos & 0x1 == 1){
                    node1->next = temp;
                    node1 = node1->next;
                }else{
                    node2->next = temp;
                    node2 = node2->next;
                }
                if(temp == nullptr){
                    break;
                }
                temp = temp->next;
                ++pos;
            }
            node1 = head;
            node2 = head2;
            while(node1 != nullptr && node2 != nullptr){
                ListNode *temp = node2->next;
                node2->next = node1;
                node2 = temp;
                if(node2 == nullptr){
                    break;
                }
                temp = node1->next;
                node1->next = node2;
                node1 = temp;
            }
            return head2;
            */
        }
};

int main(){
    ListNode *head = new ListNode(1);
    //head->next = new ListNode(2);
    //head->next->next = new ListNode(3);
    //head->next->next->next = new ListNode(4);
    //head->next->next->next->next = new ListNode(5);
    
    Solution s;
    ListNode *res = s.SwapPairs(head);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;

    return 0;
}
