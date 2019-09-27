#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

class Solution{
    public:
        int climbStairs(int n){
            //爬楼梯：该问题实际上是斐波那契数列
            
            //方法2：
            if(n <= 2){
                return n;
            }
            int a = 1;
            int b = 2;
            int i = 3;
            while(i <= n){
                b = a+b; //将a+b赋给a
                a = b-a; //将b赋给a，这种方法可以避免使用中间变量
                ++i;
            }
            return b;

            //方法1：递归。该方法超出时间限制
            /*
            if(n == 1){
                return 1;
            }else if(n == 2){
                return 2;
            }else{
                return climbStairs(n-1)+climbStairs(n-2);
            }
            */
        }
};


int main(int argc, char *argv[]){
    if(argc < 2){
        cerr<<"Error: missing parameters."<<endl;
        exit(1);
    }
    Solution s;
    cout<<s.climbStairs(atoi(argv[1]))<<endl;

    return 0;

}
