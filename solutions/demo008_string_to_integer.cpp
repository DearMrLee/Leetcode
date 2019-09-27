#include <iostream>
#include <string>
#include <climits>

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Solution{
    public:
        int MyAtoi(string str){
            int pos = 0;
            while(pos < str.length() && str[pos] == ' '){  //过滤空格
                ++pos;
            }
            if(pos >= str.length()){
                return 0;
            }
            long n_flag = 1;  //负数标志
            if(str[pos] == '+'){
                ++pos;
            }else if(str[pos] == '-'){
                n_flag = -1;
                ++pos;
            }
            long res = 0;
            while(pos < str.length() && str[pos] >= '0' && str[pos] <= '9'){
                res = res*10 + (str[pos]-'0');
                ++pos;
                long temp = res * n_flag; 
                if(temp > INT_MAX){
                    return INT_MAX;
                }else if(temp < INT_MIN){
                    return INT_MIN;
                }
            }
            res *= n_flag;
            return (int)res;
        }
};

int main(){
    cout<<"MAX: "<<INT_MAX<<endl;
    cout<<"MIN: "<<INT_MIN<<endl;

    Solution s;
    //cout<<s.MyAtoi("    -2121648sdad")<<endl;
    //cout<<s.MyAtoi("-2147483648")<<endl;
    cout<<s.MyAtoi("2147483648")<<endl;

    return 0;
}
