#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution{
    public:
    vector<int> plusOne(vector<int> &digits){
        //方法2：倒序相加
        int temp = 1;
        for(int i=digits.size()-1;i>=0;--i){
            temp += digits[i];
            digits[i] = temp%10;
            if(temp >= 10){
                temp = 1;
            }else{
                temp = 0;
            }
        }
        if(temp == 1){
            digits.insert(digits.begin(), 1);
        }
        return digits;

        //方法1：转化为整数再加1再存到数组中。不可行，可能会超出整数范围
    }

};

int main(){
    vector<int> v = {9,9,9,9,9};
    Solution s;
    vector<int> res = s.plusOne(v);
    for(auto n:res){
        cout<<n<<", ";
    }
    cout<<endl;

    return 0;
}
