#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution{
    public:
        int MissingNumber(vector<int> &nums){
            //方法2：O(1)的空间复杂度
            if(nums.empty()){
                return -1;
            }
            int sum = (nums.size()*(nums.size()+1)) >> 1; //计算和
            for(auto num: nums){
                sum -= num;
            }
            return sum;
            
            //方法1：O(n)的空间复杂度
            /*
            if(nums.empty()){
                return -1;
            }
            vector<int> v(nums.size()+1, 0);
            for(auto num: nums){
                v[num] = 1;
            }
            for(int i=0;i<v.size();i++){
                if(v[i] == 0){
                    return i;
                }
            }
            return -1;
            */
        }
};

int main(){
    vector<int> nums = {9,6,4,3,2,5,7,0,1};

    Solution s;
    cout<<s.MissingNumber(nums)<<endl;

    return 0;
}
