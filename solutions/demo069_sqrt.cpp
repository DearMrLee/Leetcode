#include <iostream>

using std::cout;
using std::endl;
using std::cerr;

class Solution{
    public:
        int MySqrt(int x){
            //方法2:
            if(x == 0){
                return x;
            }
            int i = 1;
            int j = x;
            while(i < j-1){
                int mid = ((j-i) >> 1) + i; //计算平均数
                if(x/mid < mid){
                    j = mid;
                }else{
                    i = mid;
                }
            }
            return i;


            //方法1：
            /*
            if(x == 0){
                return 0;
            }
            for(int i=2;i<=x/2;++i){
                if(x/i >= i && x/(i+1) < i+1){
                    return i;
                }
            }
            return 1;
            */
        }
};

int main(int argc, char *argv[]){

    if(argc < 2){
        cerr<<"Error: no arguments!"<<endl;
        exit(1);
    }

    Solution s;
    
    //cout<<s.MySqrt(0)<<endl;
    //cout<<s.MySqrt(1)<<endl;
    //cout<<s.MySqrt(2)<<endl;
    //cout<<s.MySqrt(3)<<endl;
    //cout<<s.MySqrt(4)<<endl;
    //cout<<s.MySqrt(99)<<endl;

    cout<<s.MySqrt(atoi(argv[1]))<<endl;

    return 0;
}
