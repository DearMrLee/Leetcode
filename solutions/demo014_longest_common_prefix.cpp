#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


class Solution{
    public:
        string LongestCommonPrefix(vector<string> &strs){
            if(strs.empty()){
                return "";
            }
            string s_res;
            //遍历找最短的字符串
            string s_MinLen = strs[0];
            for(int i=1;i<strs.size();++i){
                if(strs[i].length() < s_MinLen.length()){
                    s_MinLen = strs[i];
                }
            }
            //从最短的字符串开始逐个字符比较
            for(int i=0;i<s_MinLen.length();++i){
                for(int j=0;j<strs.size();++j){
                    if((strs[j])[i] != s_MinLen[i]){
                        return s_MinLen.substr(0, i);
                    }
                }
            }
            return s_MinLen;
        }
};


int main(){

    vector<string> strs = {"flower", "flow", "flowight", ""};

    Solution s;
    cout<<s.LongestCommonPrefix(strs)<<endl;


    return 0;
}
