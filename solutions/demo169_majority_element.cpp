#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::sort;
using std::unordered_map;

class Solution{
    public:
        int MajorityElement(vector<int> &nums){
            //方法3
            int count = 0;
            int candidate = -1;
            for(auto num: nums){
                if(count == 0){
                    candidate = num;
                }
                count += (candidate == num)? 1 : -1;
            }
            return candidate;

            //方法2：使用哈希表
            /*
            unordered_map<int,int> um;
            for(auto num: nums){
                um[num] += 1;
            }
            int num = -1;
            int count = -1;
            unordered_map<int, int>::iterator it=um.begin();
            for(;it!=um.end();it++){
                if(it->second > count){
                    num = it->first;
                    count = it->second;
                }
            }
            return num;
            */

            
            //方法1：使用sort函数
            /*
            sort(nums.begin(), nums.end());
            return nums[nums.size()/2];
            */
        }

};


int main(){
    vector<int> nums = {1,2,3,4,1,1,1};

    Solution s;
    cout<<s.MajorityElement(nums)<<endl;


}
