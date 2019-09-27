#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
        void ReverseString(vector<char> &s){
            int start = 0;
            int end = s.size()-1;
            char c;
            while(start < end){
                c = s[start];
                s[start] = s[end];
                s[end] = c;
                ++start;
                --end;
            }
        }
};



int main(){
    
    vector<char> v = {'h', 'e', 'l', 'l', '0', '!'};

    Solution s;
    s.ReverseString(v);

    for(auto c:v){
        cout<<c<<", ";
    }
    cout<<endl;

    return 0;
}
