#include <iostream>
#include "Node_list.h"

using std::cout;
using std::endl;


class Solution {
    public:
        Node* copyRandomList(Node *head){
            if(head == nullptr){
                return nullptr;
            }
            //1.复制head中每个元素放在对应元素的后边
            Node *temp = head;
            Node *nextNode = nullptr;
            while(temp != nullptr){
                nextNode = temp->next;
                Node *node = new Node(temp->val, nullptr, nullptr);
                node->next = temp->next;
                temp->next = node;
                temp = nextNode;
            }
            //2.设置野指针的指向
            temp = head;
            while(temp != nullptr){
                if(temp->random != nullptr){
                    temp->next->random = temp->random->next;
                }
                temp = temp->next->next;
            }
            //3.拆分链表
            temp = head;
            Node *copy_head = temp->next; //拷贝链表的头
            temp->next = copy_head->next;
            temp = temp->next;
            Node *node = copy_head;
            while(temp != nullptr){
                node->next = temp->next;
                node = node->next;
                temp->next = node->next;
                temp = temp->next;
            } 
            return copy_head;
        }
        //打印链表元素
        void PrintList(Node *head){
            Node *temp = head;
            while(temp != nullptr){
                cout<<temp->val<<", ";
                temp = temp->next;
            }
            cout<<endl;
        }
};


int main(){
    
    Node *node4 = new Node(5, nullptr, nullptr);
    Node *node3 = new Node(4, node4, nullptr);
    Node *node2 = new Node(3, node3, node4);
    Node *node1 = new Node(2, node2, node3);
    Node *head = new Node(1, node1, node4);
    
    Solution s;
    Node *res = s.copyRandomList(head);

    return 0;
}
