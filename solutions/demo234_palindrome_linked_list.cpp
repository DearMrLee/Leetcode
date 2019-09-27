#include <iostream>
#include <vector>
#include "ListNode.h"
#include <string>

using std::endl;
using std::cout;
using std::vector;
using std::string;
using std::to_string;

class Solution{
    public:
        bool IsPalindrome(ListNode *head){
            //方法1：借助向量
            vector<int> v;
            ListNode *temp = head;
            while(temp != nullptr){
                v.push_back(temp->val);
                temp = temp->next;
            }
            for(int i=0;i<v.size()/2;++i){
                if(v[i] != v[v.size()-1-i]){
                    return false;
                }
            }
            return true;

            //方法2：寻找链表的中间节点，然后翻转后半部分的节点，再去跟前半部分比较
        }

};


int main(){
    ListNode *head = new ListNode(-129);
    head->next = new ListNode(-129);
    //head->next->next = new ListNode(2);
    //head->next->next->next = new ListNode(1);

    Solution s;
    cout<<s.IsPalindrome(head)<<endl;
    
}
