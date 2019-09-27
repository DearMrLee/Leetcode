#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::to_string;


class Solution{
    public:
        string countAndSay(int n){
            if(n == 1){
                return "1";
            }
            string str = countAndSay(n-1);
            string res;
            for(int i=0;i<str.length();){
                int count = 1;
                char c = str[i++];
                while(i < str.length() && str[i] == c){
                    ++count;
                    ++i;
                }
                res.append(to_string(count));
                res.push_back(c);
            }
            return res;
        }

};


int main(int argc, char *argv[]){
    if(argc < 2){
        cerr<<"Error: missing parameters."<<endl;
        exit(1);
    }

    Solution s;
    cout<<s.countAndSay(atoi(argv[1]))<<endl;

    return 0;
}
