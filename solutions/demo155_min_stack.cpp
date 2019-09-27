#include <iostream>
#include <stack>

using std::endl;
using std::cout;
using std::stack;
using std::cin;


class MinStack{
    public:
        MinStack(){

        }

        void push(int x){
            s.push(x);
            if(s_min.empty()){
                s_min.push(x);
            }else if(x <= s_min.top()){
                s_min.push(x);
            }else{
                s_min.push(s_min.top());
            }
        }

        void pop(){
            if(s.empty()){
                throw "Error: stack is empty!";
            }
            s.pop();
            s_min.pop();
        }

        int top(){
            if(s.empty()){
                throw "Error: stack is empty!";
            }
            return s.top();
        }

        int getMin(){
            if(s_min.empty()){
                throw "Error: stack is empty!";
            }
            return s_min.top();
        }

    private:
        stack<int> s;
        stack<int> s_min;

};


int main(){
    
    MinStack *obj = new MinStack();
    
    int action;
    cout<<"1-入栈\t2-出栈\t3-栈顶元素\t4-得到最小值\t0-退出"<<endl;
    while(true){
        cin>>action;
        switch(action){
            case 1:
                cout<<"请输入要入栈的元素的值:";
                int temp;
                cin>>temp;
                obj->push(temp);
                break;
            case 2:
                obj->pop();
                cout<<"出栈成功！"<<endl;
                break;
            case 3:
                cout<<"栈顶元素:"<<obj->top()<<endl;
                break;
            case 4:
                cout<<"最小值："<<obj->getMin()<<endl;
                break;
            case 0:
                return 0;
                break;
            default:
                cout<<"输入错误，请重新输入！"<<endl;
        }
    }

    return 0;
}
