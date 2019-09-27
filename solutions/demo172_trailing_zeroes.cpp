#include <iostream>
#include <climits>

using std::cout;
using std::endl;
using std::cerr;

class Solution{
    public:
        int trailingZeroes(int n){
            //方法2：
            int count = 0;
            while(n >= 5){
                count += n/5;
                n /= 5;
            }
            return count;

            //方法1：不够精简
            //就是计算从1至n每个整数含5的总个数
            //计算公式：
            //n/5+n/25+n/125+n/625+...
            /*
            if(n < 0){
                n *= -1;
            }
            int count = 0;
            for(int i=5;i<=n;i*=5){
                if(n>=i){
                    count += n/i;
                }
                if(i > INT_MAX/5){
                    break;
                }
            }
            return count;
            */
        }
};


int main(int argc, char* argv[]){
    if(argc < 2){
        cerr<<"Error: missing parameter."<<endl;
        exit(1);
    }

    Solution s;
    cout<<s.trailingZeroes(atoi(argv[1]))<<endl;

    return 0;
}
