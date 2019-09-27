#ifndef _NODE_
#define _NODE_


/**
 * 树节点定义。
 * 树的每个节点含有一个指向其右边节点的指针
 */

class Node{
    public:
        int val;
        Node *left;
        Node *right;
        Node *next;

        Node(){
        }

        Node(int _val, Node *_left, Node *_right, Node *_next){
            val = _val;
            left = _left;
            right = _right;
            next = _next;
        }

};


#endif
