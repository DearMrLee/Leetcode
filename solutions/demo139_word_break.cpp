#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_set;
using std::set;


class Solution {
    public:
        bool wordBreak(string s, vector<string> &wordDict){
            vector<int> res(s.length()+1, 0);
            res[0]= 1;
            set<string> mapping;
            for(auto &str:wordDict){
                mapping.insert(str);
            }
            for(int i=0;i<res.size();++i){
                for(int j=0;j<i;++j){
                    if(res[j] == 1){
                        string str_temp = s.substr(j, i-j);
                        if(mapping.find(str_temp) != mapping.end()){
                            res[i] = 1;
                            break;
                        }
                    }
                }
            }
            return res[res.size()-1];
        }
};

int main(){
    
    string str = "cars";
    vector<string> wordDict = {"car", "ca", "rs"};

    Solution s;
    cout<<s.wordBreak(str, wordDict)<<endl;

    return 0;
}
