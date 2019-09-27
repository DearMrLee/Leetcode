#include <iostream>
#include <map>
#include "ListNode.h"

using std::cout;
using std::endl;
using std::multimap;
using std::make_pair;

class Solution {
    public:
        ListNode* sortList(ListNode *head){
            //方法2：归并的思想
            if(head == nullptr || head->next == nullptr){
                return head;
            }
            ListNode *slow = head;
            ListNode *fast = head;
            if(fast->next && fast->next->next){
                slow = slow->next;
                fast = fast->next->next;
            }
            fast = slow->next;
            slow->next = nullptr;
            //归
            ListNode *l1 = sortList(head);
            ListNode *l2 = sortList(fast);
            //并
            return mergeList(l1, l2);
            

            //方法1：借助multimap
            /*
            multimap<int, ListNode*> mm;
            ListNode *temp = head;
            while(temp){
                mm.insert(make_pair(temp->val, temp));
                temp = temp->next;
            }
            head = new ListNode(-1);
            temp = head;
            for(multimap<int, ListNode*>::iterator it=mm.begin();it!=mm.end();it++){
                temp->next = it->second;
                temp = temp->next;
            }
            temp->next = nullptr;
            return head->next;
            */
        }
        //合并两个有序链表
        ListNode* mergeList(ListNode *l1, ListNode *l2){
            if(l1 == nullptr){
                return l2;
            }
            if(l2 == nullptr){
                return l1;
            }
            ListNode *head = new ListNode(-1);
            ListNode *temp = head;
            while(l1 && l2){
                if(l1->val < l2->val){
                    temp->next = l1;
                    l1 = l1->next;
                }else{
                    temp->next = l2;
                    l2 = l2->next;
                }
                temp = temp->next;
            }
            temp->next = l1 ? l1 : l2;
            return head->next;
        }

};


int main(){
    
    ListNode *head = new ListNode(-1);
    head->next = new ListNode(5);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(0);

    Solution s;
    ListNode *res = s.sortList(head);
    while(res != nullptr){
        cout<<res->val<<",";
        res = res->next;
    }
    cout<<endl;


    return 0;
}
