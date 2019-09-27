#include <iostream>
#include <string>
#include <unordered_map>
using std::string;
using std::unordered_map;


class Solution{
    public:
        int RomanToInt(string s){
            /*
             * 方法2
             */
            unordered_map<char,int> um = {
                {'I',1}, {'V',5}, {'X',10}, 
                {'L',50}, {'C',100}, 
                {'D',500}, {'M',1000}
            };
            int num = 0;
            for(int i=0;i<s.length();i++){
                if(i+1 < s.length() && um[s[i]] < um[s[i+1]]){
                    num -= um[s[i]];
                }else{
                    num += um[s[i]];
                }
            }
            return num;

            /* 
             * 方法1：自己写的
            if(s.length() == 0){
                return 0;
            }
            unordered_map<char,int> um;
            um['I'] = 1;
            um['V'] = 5;
            um['X'] = 10;
            um['L'] = 50;
            um['C'] = 100;
            um['D'] = 500;
            um['M'] = 1000;
            
            int num = 0;  //记录结果
            int pos = 0;  //索引
            int step = 0;  //罗马字符表示的数字
            while(pos < s.length()){
                char c = s[pos];
                if(c == 'I'){
                    step = 1;
                    ++pos;
                    if(pos < s.length()){
                        if(s[pos] == 'V'){
                            step = 4;
                            ++pos;
                        }else if(s[pos] == 'X'){
                            step = 9;
                            ++pos;
                        }
                    }
                }else if(c == 'X'){
                    step = 10;
                    ++pos;
                    if(pos < s.length()){
                        if(s[pos] == 'L'){
                            step = 40;
                            ++pos;
                        }else if(s[pos] == 'C'){
                            step = 90;
                            ++pos;
                        }
                    }
                }else if(c == 'C'){
                    step = 100;
                    ++pos;
                    if(pos < s.length()){
                        if(s[pos] == 'D'){
                            step = 400;
                            ++pos;
                        }else if(s[pos] == 'M'){
                            step = 900;
                            ++pos;
                        }
                    }
                }else{
                    step = um[c];
                    ++pos;
                }
                num += step;
            }
            return num;
            */
        } 
};

int main(){
    Solution s;
    while(true){
        std::cout<<"Input a roman string:";
        string str;
        std::cin>>str;
        std::cout<<s.RomanToInt(str)<<std::endl;
    }
    return 0;
}
