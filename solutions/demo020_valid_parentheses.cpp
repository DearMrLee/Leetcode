#include <iostream>
#include <string>
#include <stack>
using namespace std;


class Solution{
    public:
        bool IsValid(string s){
            stack<char> sta;
            for(int i=0;i<s.length();i++){
                if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                    char c;
                    if(s[i] == '('){
                        c = ')';
                    }else if(s[i] == '['){
                        c = ']';
                    }else{
                        c = '}';
                    }
                    sta.push(c);
                }else{
                    if(sta.empty()){  //只有右括号没有左括号
                        return false;
                    }
                    if(sta.top() == s[i]){
                        sta.pop();
                    }else{
                        return false;
                    }
                }
            }
            //如果只有左括号没有右括号，也返回false
            return sta.empty();
        }
};


int main(){
    
    Solution s;
    if(s.IsValid("({[(]})")){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    cout<<s.IsValid("()")<<endl;

    return 0;
}
