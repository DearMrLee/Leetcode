#include <iostream>
#include "ListNode.h"

using std::cout;
using std::endl;


class Solution{
    public:
    ListNode* detectCycle(ListNode *head){
        //方法2:代码精简版
        if(!head || !head->next){
            return nullptr;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && slow){
            slow = slow->next;
            fast = fast->next ? fast->next->next:nullptr;
            if(fast == slow){
                break;
            }
        }
        if(fast != slow){
            return nullptr;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;

        //方法1：代码不够精简
        /*
        if(head == nullptr || head->next == nullptr){
            return nullptr;
        }
        ListNode *fast = head->next->next;
        ListNode *slow = head;
        //1.判断是否有环
        while(fast && fast->next && slow!=fast){
            fast = fast->next->next;
            slow = slow->next;
        }
        if(fast == nullptr || fast->next == nullptr){
            return nullptr;
        }
        //2.此时有环，计算环的长度
        int cycle_len = 0;
        do{
            ++cycle_len;
            fast = fast->next;
        }while(fast != slow);
        //3.寻找环的入口
        slow = head;
        fast = head;
        while(cycle_len > 0){
            fast = fast->next;
            --cycle_len;
        }
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        */
    }
};

int main(){
    
    ListNode *head = new ListNode(3);
    ListNode *node1 = head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = node1;

    Solution s;
    ListNode *res = s.detectCycle(head);
    if(res){
        cout<<res->val<<endl;
    }else{
        cout<<"NULL"<<endl;
    }

    return 0;
}
