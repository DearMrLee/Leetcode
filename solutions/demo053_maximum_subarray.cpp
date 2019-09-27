#include <iostream>
#include <vector>
#include <climits>

using std::cout;
using std::endl;
using std::vector;


class Solution{
    public:
        int maxSubArray(vector<int> &nums){
            int maxSum = INT_MIN;
            int curSum = 0;
            for(int i=0;i<nums.size();++i){
                if(curSum <= 0){
                    curSum = nums[i];
                }else{
                    curSum += nums[i];
                }
                if(curSum > maxSum){
                    maxSum = curSum;
                }
            }
            return maxSum;
        }
};

int main(){

    vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
    Solution s;
    cout<<s.maxSubArray(v)<<endl;

    return 0;
}
