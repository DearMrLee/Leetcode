#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution{
    public:
        void MoveZeroes(vector<int> &nums){
            int pos = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] == 0){
                    continue;
                }else{
                    nums[pos++] = nums[i];
                }
            }
            for(;pos<nums.size();++pos){
                nums[pos] = 0;
            }
        }
};


int main(){
    //vector<int> nums = {0,1,0,3,3,12,2};
    vector<int> nums = {3,3,12,2,0,0,1};

    Solution s;
    s.MoveZeroes(nums);

    for(auto num:nums){
        cout<<num<<", ";
    }
    cout<<endl;
    
    return 0;
}
