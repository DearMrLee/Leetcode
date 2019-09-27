#include <iostream>

using std::cout;
using std::endl;
using std::cin;


class Solution{
    public:
        int hammingWeight(uint32_t n){
            //方法2
            int num = 0;
            while(n != 0){
                ++num;
                n &= (n-1);
            }
            return num;

            //方法1
            /*
            int num = 0;
            while(n != 0){
                num += n & 0x1;
                n = n >> 1;
            }
            return num;
            */
        }
};

int main(){
    
    Solution s;
    uint32_t n = 15;
    cout<<s.hammingWeight(n)<<endl;

    return 0;
}
