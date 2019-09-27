#include <iostream>
#include <climits>

using std::cout;
using std::endl;

class Solution{
    public:
        int GetSum(int a, int b){
            while(b != 0){
                auto c = ((unsigned int)a & b) << 1; //保护位运算（因为有溢出的可能）
                a = a ^ b;
                b = c;
            } 
            return a;
        }

};


int main(){

    Solution s;
    cout<<s.GetSum(1, 2)<<endl;
    cout<<s.GetSum(18, 13)<<endl;
    cout<<s.GetSum(-2, -10)<<endl;
    cout<<s.GetSum(-1, 1)<<endl;
    cout<<s.GetSum(INT_MAX, INT_MAX)<<endl;
    cout<<s.GetSum(INT_MAX, 0)<<endl;
    cout<<s.GetSum(INT_MAX, 1)<<endl;
    cout<<s.GetSum(INT_MAX, 2)<<endl;
    cout<<s.GetSum(INT_MIN, INT_MIN)<<endl;

    return 0;
}
