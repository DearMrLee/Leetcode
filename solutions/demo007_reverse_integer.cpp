#include <iostream>
#include <climits>

using std::cout;
using std::endl;

using namespace std;


class Solution{
    public:
        int Reverse(int x){
            bool neg = x<0?false:true;
            int num = 0;
            while(x){
                if(!neg && num < INT_MIN/10 || neg && num > INT_MAX/10){
                    num = 0;
                    break;
                }
                num = num*10 + x%10;
                x /= 10;
            }
            return num;
        }
};


int main(int argc, char* argv[]){
    //int x = atoi(argv[1]);
    //cout<<x<<endl;
    
    int x = INT_MAX;
    //int x = 746384741;
    cout<<"x: "<<x<<endl;

    Solution s;
    int res = s.Reverse(x);
    cout<<res<<endl;

    return 0;
}
