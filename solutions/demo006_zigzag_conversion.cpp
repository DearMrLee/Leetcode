#include <iostream>
#include <vector>
#include <string>
using std::endl;
using std::cout;
using std::cin;
using std::vector;
using std::string;


class Solution{
    public:
        string convert(string s, int numRows){
            //方法2：
            if(s.length() == 0 || numRows<=0){
                return "";
            }
            if (numRows == 1){
                return s;
            }
            string res("");
            int step = 2*numRows-2;
            int len = s.length();
            for (int i=0;i<numRows;++i){
                for (int j=i;j<len;j+=step){
                    res += s[j];
                    if(i!=0 && i!=numRows-1){
                        int temp = step-i*2+j;
                        if(temp < len){
                            res += s[temp];
                        }
                    }
                }
            }
            return res;

            //方法1：出现Runtime Error
            /*
            vector<string> strs(numRows, "");
            int i = 0;
            bool down = true;
            for (auto c: s){
                if (down){ //向下
                    strs[i].push_back(c);
                    if (i == numRows-1){
                        down = false;
                        --i;
                    }else{
                        ++i;
                    }
                }else{ //向上
                    strs[i].push_back(c);
                    if (i == 0){
                        down = true;
                        ++i;
                    }else{
                        --i;
                    }
                }
            }
            string res("");
            for (auto s: strs){
                //cout<<s<<endl;
                res += s;
            }
            return res;
            */
        }
};


int main(){
    Solution solution;
    string s = "PAYPALISHIRING";
    int numRows = 4;
    string res = solution.convert(s, numRows);
    cout<<res<<endl;


    return 0;
}
