#include <iostream>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::cerr;


class Solution{
    public:
        int strStr(string haystack, string needle){
            if(haystack.empty() || needle.empty()){
                if(needle.empty()){
                    return 0;
                }else{
                    return -1;
                }
            }
            if(haystack.length() < needle.length()){
                return -1;
            }
            //至此，两个字符串都不为空，且前者长度>后者
            int i=0, j=0;
            int pos = i;
            while(i + needle.length() <= haystack.length()){
                if(haystack[i] != needle[j]){
                    j = 0;
                    ++i;
                    continue;
                }
                int temp = i;
                while(temp<haystack.length() && j<needle.length() && haystack[temp] == needle[j]){
                    ++temp;
                    ++j;
                }
                if(j == needle.length()){
                    return i; 
                }else{
                    j = 0;
                    ++i;
                }
            }
            return -1;
        }

};


int main(int argc, char *argv[]){
    if(argc < 3){
        cerr<<"Error: missing parameter."<<endl;
        exit(1);
    }
    
    Solution s;
    cout<<s.strStr(argv[1], argv[2])<<endl;


    return 0;
}
