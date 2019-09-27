#include <iostream>
#include <string>
#include <vector>
#include <climits>

using std::string;
using std::cout;
using std::endl;
using std::vector;


class Solution{
    public:
        string LongestPalindromicSubstring(string s){
            //方法2：使用Manacher算法。时间复杂度O(n)
            string res = "";
            res.push_back('^'); //开头标志
            for(int i=0;i<s.length();++i){
                res.push_back('#');
                res.push_back(s[i]);
            }
            res.push_back('#');
            res.push_back('$'); //结尾标志
            cout<<res<<endl;

            vector<int> v(res.length(), 0); //存储以i为中心的回文字符串的半径
            int mx = 0; //回文字符串的最右边界
            int id = 0; //最右回文字符串的中心
            int max_len = 0; //最长回文字符串的长度
            for(int i=1;i<res.length();++i){
                if(mx > i){
                    v[i] = std::min(mx-i, v[id*2-i]);
                }else{ //从头开始匹配
                    v[i] = 1;
                }
                while(res[i-v[i]] == res[i+v[i]]){
                    ++v[i];
                }
                if(mx < v[i]+i){ //新回文串的右边界大于mx，则更新右边界mx和中心id
                    mx = v[i] + i;
                    id = i;
                }
                max_len = std::max(max_len, v[i]-1);  //最长回文字符串的长度，如果要求计算最长回文字符串的长度，则返回max_len即可
            }
            int center = -1;  //最长回文串的索引
            int maxLen = -1;  //最长回文串的长度
            for(int i=0;i<v.size();i++){
                if(v[i] > maxLen){
                    maxLen = v[i];
                    center = i;
                }
            }
            maxLen -= 1; //-1才是最长回文串的长度
            int pos = (center-maxLen)/2; //计算最长回文串在原始串中的开始索引
            string ss = s.substr(pos, maxLen);
            return ss;

            /**
             * 方法1：动态规划。O(n^2)时间复杂度
             * p(i,j) = p(i+1, j-1) && s[i] == s[j]
             */
            /*
            //标志（i, j）是否是回文串，是则1，否则0
            vector<vector<int>> vv(s.length(), vector<int>(s.length(), 0));
            string res = "";
            for(int i=s.length()-1;i>=0;--i){
                for(int j=i;j<s.length();j++){
                    if(s[i] == s[j] && (j-i<2 || vv[i+1][j-1])){
                        vv[i][j] = 1;
                    }else{
                        vv[i][j] = 0;
                    }
                    if(vv[i][j] && j-i+1 > res.length()){
                        res = s.substr(i, j-i+1);
                    }
                }
            }
            return res;
            */
        }

};

int main(int argc, char *argv[]){
    
    if(argc < 2){
        cout<<"Please input arguments and run again!"<<endl;
        return 0;
    }
    
    string str = argv[1];

    Solution s;
    string palin = s.LongestPalindromicSubstring(str);
    cout<<palin<<endl;

    return 0;
}
