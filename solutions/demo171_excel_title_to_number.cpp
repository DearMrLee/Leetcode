#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using std::cout;
using std::endl;
using std::string;
using std::pow;


class Solution{
    public:
        int TitleToNumber(string s){
            int num = 0;
            int step = 0;
            for(auto c: s){
                num = num*26 + (c-64);
                ++step;
            }
            return num;
        }
};

int main(){
    
    //cout<<(int)'A'<<endl; //65
    
    Solution s;
    cout<<s.TitleToNumber("AAA")<<endl;
    cout<<s.TitleToNumber("Z")<<endl;
    cout<<s.TitleToNumber("AB")<<endl;
    cout<<s.TitleToNumber("ZY")<<endl;

    return 0;
}
