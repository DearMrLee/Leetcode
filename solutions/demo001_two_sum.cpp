#include <iostream>
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;

class Solution{
    public:
        vector<int> TwoSum(vector<int> &nums, int target){
            /*方法2*/
            unordered_map<int,int> um;
            int temp = 0;
            for(int i=0;i<nums.size();i++){
                temp = target - nums[i];
                if(um.find(temp) != um.end()){
                    return {um[temp], i};
                }else{
                    um[nums[i]] = i;
                }
            }
            return {};
            
            /*方法1：自己写
            vector<int> res;
            for(int i=0;i<nums.size();i++){
                int temp = target - nums[i];
                for(int j=i+1;j<nums.size();j++){
                    if(temp == nums[j]){
                        res.push_back(i);
                        res.push_back(j);
                        return res;
                    }
                }
            }
            return res;
            */
        }
};

int main(){
    
    vector<int> v = {7,2,11,15};
    int target = 22;
    Solution s;
    vector<int> res = s.TwoSum(v, target);
    for(int i=0;i<res.size();i++){
        std::cout<<res[i]<<",";
    }
    std::cout<<std::endl;

    return 0;
}
