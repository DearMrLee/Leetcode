#include <iostream>
#include "ListNode.h"


class Solution{
    public:
        ListNode* DeleteDuplicates(ListNode *head){
            //方法2：
            ListNode *res = new ListNode(-1);
            res->next = head;
            
            ListNode *preNode = res;
            ListNode *curNode = head;
            while(curNode != nullptr){
                while(nullptr != curNode->next && curNode->val == curNode->next->val){
                    curNode = curNode->next;
                }
                if(preNode->next == curNode){ //说明没有重复的
                    preNode = curNode;
                }else{
                    preNode->next = curNode->next;
                }
                curNode = curNode->next;
            }
            return res->next;


            /*方法1：自己写
            ListNode *newHead = nullptr;
            ListNode *preNode = nullptr;
            ListNode *curNode = head;
            ListNode *nextNode = nullptr;
            while(curNode != nullptr){
                nextNode = curNode->next;
                if(nextNode != nullptr && nextNode->val == curNode->val){
                    nextNode = nextNode->next;
                    while(nextNode != nullptr && nextNode->val == curNode->val){
                        nextNode = nextNode->next;
                    }
                    curNode = nextNode;
                    if(preNode != nullptr){
                        preNode->next = curNode;
                    }
                }else{
                    if(newHead == nullptr){
                        newHead = curNode;
                    }
                    preNode = curNode;
                    curNode = nextNode;
                }
            }
            return newHead;
            */
        }
};


int main(){

    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next->next = new ListNode(5);

    Solution s;
    ListNode *res = s.DeleteDuplicates(head);
    while(res != nullptr){
        std::cout<<res->val<<", ";
        res = res->next;
    }
    std::cout<<std::endl;


    return 0;
}
