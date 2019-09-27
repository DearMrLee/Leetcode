#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;


class Solution{
    public:
        int CountPrimes(int n){
            vector<int> v(n,0);  //记录1-n之间某个数是否是质数
            for(int i=2;i*i<n;++i){
                if(v[i] == 0){
                    for(int j=2;i*j<n;++j){
                        v[i*j] = 1;
                    }
                }
            }
            int count = 0;  //质数的个数
            for(int i=2;i<n;++i){
                if(v[i] == 0){
                    ++count;
                }
            }
            return count;


            /*
            if(n <= 2){
                return 0;
            }else if(n < 4){
                return 1;
            }
            vector<int> v;
            v.push_back(2);
            int j;
            for(int i=3;i<n;i++){
                for(j=0;j<v.size();++j){
                    if(i % v[j] == 0){
                        break;       
                    }
                }
                if(j == v.size()){
                    v.push_back(i); 
                }
            }
            return v.size();
            */
        }
};

int main(int argc, char *argv[]){
    if(argc <= 1){
        cout<<"Error: no arguments!"<<endl;
        exit(1);
    }

    Solution s;
    cout<<s.CountPrimes(atoi(argv[1]))<<endl;
    return 0;
}
