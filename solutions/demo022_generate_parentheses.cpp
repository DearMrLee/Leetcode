#include <iostream>
#include <vector>
#include <stack>
#include <string>

using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::stack;
using std::string;


class Solution{
    public:
        vector<string> generateParenthesis(int n){
            vector<string> v;
            if(n <= 0){
                return v;
            }
            LEN = n*2;
            string str = "";
            generate(n, str, v);
            vector<string> res;
            for (auto &ss: v){
                if(kuohaopipei(ss)){
                    res.push_back(ss);
                }
            }
            return res;
        }

    private:
        int LEN;
        void generate(int n, string str, vector<string> &v){
            if (str.length() == LEN){
                v.push_back(str);
                return;
            }
            if (n > 0){
                generate(n-1, str+'(', v);
            }
            generate(n, str+')', v);
        }
        bool kuohaopipei(string &str){
            stack<char> s;
            for (auto &c: str){
                if (c == '('){
                    s.push(')');
                }else{
                    if(s.empty()){
                        return false;
                    }
                    s.pop();
                }
            }
            return true;
        }
};


int main(){
    
    Solution s;
    int n = 3;
    vector<string> res = s.generateParenthesis(n);
    for (auto &str:res){
        cout<<str<<endl;
    }

    return 0;
}
