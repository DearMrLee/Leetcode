#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::unordered_set;


class Solution{
    public:
        bool ContainsDuplicate(vector<int> &nums){
            unordered_set<int> us;
            for(auto num: nums){
                if(us.find(num) != us.end()){
                    return true;
                }else{
                    us.insert(num);
                }
            }
            return false;
        }

};


int main(){
    vector<int> v = {1,2,3,1};

    Solution s;
    cout<<s.ContainsDuplicate(v)<<endl;
}
