#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;


class Solution{
    public:

    vector<string> letterCombinations(string digits){
        vector<string> res;
        if(digits.length() == 0){
            return res;
        }
        get_combinations(digits, "", 0, res);
        return res;
    }
    
    private:
        void get_combinations(string digits, string temp, int index, vector<string> &res){
            if(index == digits.length()){
                res.push_back(temp);
                return;
            }
            for(int i=0;i<mapping[digits[index]-'0'].length();++i){
                get_combinations(digits, temp+mapping[digits[index]-'0'][i], index+1, res);
            }
        }

    vector<string> mapping = {"","","abc","def","ghi","jkl","mno",
        "pqrs","tuv","wxyz"};

};

int main(){
    
    string digits;
    cin>>digits;
    Solution s;
    vector<string> res = s.letterCombinations(digits);
    for(auto &str:res){
        cout<<str<<",";
    }
    cout<<endl;

    return 0;
}
