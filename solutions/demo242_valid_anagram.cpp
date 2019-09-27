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
        bool IsAnagram(string s, string t){
            if(s.length() != t.length()){
                return false;
            }
            vector<int> v(26, 0); //26个小写字母
            for(auto c: s){
                v[c-'a'] += 1;
            }
            for(auto c: t){
                v[c-'a'] -= 1;
            }
            for(auto num: v){
                if(num != 0){
                    return false;
                }
            }
            return true;
        }

};

int main(){
    
    Solution s;
    cout<<s.IsAnagram("anaasam", "nagaram")<<endl;

    return 0;
}
