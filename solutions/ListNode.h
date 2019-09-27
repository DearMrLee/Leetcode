#ifndef _LISTNODE_H_
#define _LISTNODE_H_

#include <iostream>

/*
 * 定义单链表
 */

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr){
    }
};

#endif
