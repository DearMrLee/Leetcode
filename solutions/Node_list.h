#ifndef _NODE_LIST_H_
#define _NODE_LIST_H_

/*
 * 链表节点定义
 */
class Node{
    public:
        int val;
        Node *next;
        Node *random;

        Node() = default;

        Node(int _val, Node *_next, Node *_random){
            val = _val;
            next = _next;
            random = _random;
        }
};


#endif
