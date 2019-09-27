#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
        int SingleNumber(vector<int> &nums){
            for(int i=1;i<nums.size();i++){
                nums[0] ^= nums[i];
            }
            return nums[0];
        }
};


int main(){

    vector<int> nums = {2,2,1,1,4};

    Solution s;
    cout<<s.SingleNumber(nums)<<endl;

    return 0;
}
