#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_set;


class Solution {
    public:
        bool wordBreak(string s, vector<string> &wordDict){
            unordered_set<string> words;
            for(auto &word: wordDict){
                words.insert(word);
            }
            
            return true;
        }
};

int main(){
    
    string str = "cars";
    vector<string> wordDict = {"car", "ca", "rs"};

    Solution s;
    cout<<s.wordBreak(str, wordDict)<<endl;

    return 0;
}
