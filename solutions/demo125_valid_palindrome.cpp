#include <iostream>
#include <string>
#include <locale>

using std::endl;
using std::cout;
using std::string;
using std::isalnum;
using std::tolower;


class Solution{
    public:
        bool IsPalindrome(string s){
            //方法2：
            /*
            int pos = 0;
            //先转小写
            for(auto c:s){
                if(c>='0' && c<='9' || c>='a' && c<='z'){
                    s[pos++] = c;
                }else if(c>='A' && c<='Z'){
                    s[pos++] = c-'A'+'a';
                }
            }
            //pos是s有效字符的长度
            for(int i=0;i<pos/2;++i){
                if(s[i] != s[pos-i-1]){
                    return false;
                }
            }
            return true;
            */
            
            //方法1：
            //在判断两个字符是否相同的时候不能直接+32或-32来判断两个大小写字母是否是相同的，
            //因为字母和数字是有交集的，例如 '0' + 32 = 'P'，但"0P"不是回文串
            
            int start = 0, end = s.length()-1;
            while(start < end){
                while(start < end && !isalnum(s[start])){
                    ++start;
                }
                while(start < end && !isalnum(s[end])){
                    --end;
                }
                if(start >= end){
                    break;
                }
                if(tolower(s[start]) != tolower(s[end])){
                    return false;
                }
                ++start;
                --end;
            }
            return true;
            
        }
        bool IsAlphanumeric(char c){
            if(c>='a' && c<='z' || c>='A' && c<='Z' || c>='0' && c<='9'){
                return true;
            }
            return false;
        }
};


int main(){
    Solution s;
    cout<<s.IsPalindrome("A man, a plan, a canal: Panama")<<endl;
    cout<<s.IsPalindrome("            ")<<endl;
    cout<<s.IsPalindrome("aaabbbaaa")<<endl;
    cout<<s.IsPalindrome("OP")<<endl;
    cout<<s.IsPalindrome("0P")<<endl;
    return 0;
}
