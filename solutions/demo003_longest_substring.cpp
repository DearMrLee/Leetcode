#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::vector;

class Solution{
    public:
        int LengthofLongestSubstring(string s){
            vector<int> v(128, -1); //注意，string有可能是大写、小写字母
            std::cout<<v.size()<<std::endl;
            

            int curLen = 0;
            int maxLen = 0;
            for(int i=0;i<s.length();i++){
                int preIndex = v[s[i]];
                v[s[i]] = i;
                if(preIndex < 0 || i-preIndex > curLen){
                    ++curLen;
                }else{
                    if(curLen > maxLen){
                        maxLen = curLen;
                    }
                    curLen = i-preIndex;
                }
            }
            if(curLen > maxLen){
                maxLen = curLen;
            }
            return maxLen;
        }

};

int main(int argc, char *argv[]){
    
    Solution s;
    
    std::cout<<s.LengthofLongestSubstring(argv[1])<<std::endl;

    return 0;
}
