#include <iostream>
#include <string>
#include <climits>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::to_string;

class Solution{
    public:
        bool isPowerOfThree(int n){
            //方法2：不循环且不递归
            //用整数范围内3的幂次方的最大值（1162261467）对n进行取余
            if(n > 0){
                return 1162261467 % n == 0;
            }
            return false;
            
            //方法1：循环
            /*
            if(n <= 0){
                return false;
            }
            while(n%3 == 0){
                n /= 3;
            }
            return n == 1;
            */
        }

};


int main(int argc, char *argv[]){
    //int num = 1;
    //while(num < INT_MAX/3){
    //    num *= 3;
    //    cout << num <<endl;
    //}

    if(argc < 2){
        cout<<"Error: missing parameter."<<endl;
        exit(1);
    }
    Solution s;
    cout<<s.isPowerOfThree(atoi(argv[1]))<<endl;

}
