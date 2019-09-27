#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;


class Solution{
    public:
        uint32_t ReverseBits(uint32_t n){
            uint32_t res = 0;
            int i = 0;
            uint32_t temp;
            while(i < 32){
                res = res << 1;
                res += n & 1;
                n = n >> 1;
                ++i;
            }
            return res;

        }
};

int main(){

    uint32_t n = 0xffffabcd;
    bitset<32> bs(n);
    cout<<bs<<endl;
        
    Solution s;
    bs = s.ReverseBits(n);
    cout<<bs<<endl;

    return 0;
}
