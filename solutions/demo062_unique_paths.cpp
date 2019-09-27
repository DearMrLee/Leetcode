#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::cerr;
using std::vector;

class Solution{
    public:
        int uniquePaths(int m, int n){
            if(m<1 || n<1){
                return 0;
            }
            vector<vector<int>> vv(n, vector<int>(m, 1)); //创建一个n行m列的二维数组
            //print2DArray(vv);
            for(int i=1;i<n;++i){
                for(int j=1;j<m;++j){
                    vv[i][j] = vv[i][j-1] + vv[i-1][j];
                }
            }
            //print2DArray(vv);

            return vv[n-1][m-1];
        }
        void print2DArray(vector<vector<int>> &vv){
            for(int i=0;i<vv.size();++i){
                for(int j=0;j<vv[0].size();++j){
                    cout<<vv[i][j]<<",";
                }
                cout<<endl;
            }
        }
};


int main(int argc, char* argv[]){
    if(argc < 3){
        cerr<<"Parameter error."<<endl;
        exit(1);
    }
    Solution s;
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    cout<<s.uniquePaths(m, n)<<endl;

    return 0;
}
