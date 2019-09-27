#include <iostream>
#include "ListNode.h"


class Solution{
    public:
        ListNode* RotateRight(ListNode *head, int k){
            if(head == nullptr || k == 0){
                return head;
            }
            int length = 0; //链表长度
            ListNode *node = head;
            while(node != nullptr){
                ++length;
                node = node->next;
            }
            k = k % length;
            if(k == 0){
                return head;
            }
            ListNode *fast = head;
            //fast先走k步
            for(int i=1;i<k;i++){
                fast = fast->next;
            }
            node = head;
            ListNode *preNode = nullptr;
            while(fast->next != nullptr){
                preNode = node;
                node = node->next;
                fast = fast->next;
            }
            fast->next = head;
            if(preNode != nullptr){
                preNode->next = nullptr;
            }
            return node;
        }
};


int main(int argc, char *argv[]){
    if(argc == 1){
        std::cout<<"请输入命令行参数."<<std::endl;
        return 0;
    }

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution s;
    int k = atoi(argv[1]);
    ListNode *res = s.RotateRight(head, k);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;
    return 0;
}
