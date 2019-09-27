#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution{
    public:
        vector<vector<int>> generate(int numRows){
            //方法2：循环
            vector<vector<int>> res(numRows);
            for(int i=0;i<numRows;++i){
                res[i].resize(i+1);
                res[i][0] = res[i][i] = 1;
                for(int j=1;j<res[i].size()-1;++j){
                    res[i][j] = res[i-1][j-1] + res[i-1][j];
                }
            }
            return res;
            
            //方法1：递归
            /*
            vector<vector<int>> res;
            generate(res, numRows);
            return res;
            */
        }
        void generate(vector<vector<int>> &res, int numRows){
            if(numRows == 0){
                return;
            }else if(numRows == 1){
                res.push_back({1});
                return;
            }
            generate(res, numRows-1);

            vector<int> v;
            v.push_back(1);
            vector<int> &temp = res[res.size()-1];
            for(int i=0;i<temp.size()-1;++i){
                v.push_back(temp[i]+temp[i+1]);
            }
            v.push_back(1);
            res.push_back(v);
        }
};


int main(int argc, char *argv[]){
    if(argc < 2){
        cout<<"Error: missing parameters."<<endl;
        exit(1);
    }

    Solution s;

    vector<vector<int>> res = s.generate(atoi(argv[1]));
    for(auto v:res){
        for(auto n:v){
            cout<<n<<",";
        }
        cout<<endl;
    }

    return 0;
}
