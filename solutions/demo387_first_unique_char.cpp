#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

class Solution{
    public:
        int firstUniqChar(string s){
            //方法2
            vector<int> v(26, 0);
            for(auto c: s){
                v[c-'a']++;
            }
            for(int i=0;i<s.length();i++){
                if(v[s[i]-'a'] == 1){
                    return i;
                }
            }
            return -1;

            //方法1：借助unordered_map
            /*
            int pos = -1;
            unordered_map<char, int> um;
            for(int i=0;i<s.length();++i){
                if(um.find(s[i]) == um.end()){
                    um[s[i]] = 0;
                }else{
                    um[s[i]] = 1;
                }
            }
            for(int i=0;i<s.length();++i){
                if(um[s[i]] == 0){
                    pos = i;
                    break;
                }
            }
            return pos;
            */
        }
};

int main(int argc, char *argv[]){
     
    if(argc <= 1){
        cout<<"Error: no arguments.\n";
        exit(1);
    }

    Solution s;
    cout<<s.firstUniqChar(argv[1])<<endl;

    return 0;
}
