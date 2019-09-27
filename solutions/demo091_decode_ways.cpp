#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::vector;


class Solution {
    public:
        int numDecodings(string s){
            //方法2：借助数组
            //分析过程见https://blog.csdn.net/racaljk/article/details/79337727
            if(s.empty()){
                return 0;
            }
            vector<int> v(s.size()+1, 0); //v[i]表示长度为i的时候最多的解码结果
            v[0] = 1;
            v[1] = s[0]=='0'?0:1;
            for(int i=2;i<=s.size();++i){
                if(s[i-1] != '0'){
                    v[i] += v[i-1];
                }
                int num = stoi(s.substr(i-2, 2));
                if(num>=10 && num <=26){
                    v[i] += v[i-2];
                }
            }
            return v[s.size()];
            
            //方法1：递归
            /*
            if(s.empty()){
                return 0;
            }
            int index = 0;
            return numDecodings(s, index);
            */
        }

        int numDecodings(string &s, int index){
            if(index >= s.length()){
                return 1;
            }
            if(s[index] == '0'){
                return 0;
            }
            if(index+1 >= s.length()){
                return 1;
            }
            if(s[index]=='1' && s[index+1]!='0' || s[index]=='2' && s[index+1]<='6'){
                return numDecodings(s, index+1) + numDecodings(s, index+2);
            }else if((s[index]=='1' || s[index]=='2') && s[index+1]=='0'){
                return numDecodings(s, index+2);
            }else{
                return numDecodings(s, index+1);
            }
        }
};


int main(int argc, char *argv[]){
    if(argc < 2){
        cerr<<"Error: missing Parameters."<<endl;
        exit(1);
    }
    string str = argv[1]; //char*可以直接转为string
    Solution s;
    cout<<s.numDecodings(str)<<endl;

    return 0;
}
