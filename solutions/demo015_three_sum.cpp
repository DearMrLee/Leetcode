#include <iostream>
#include <vector>
#include <algorithm>

using std::endl;
using std::cout;
using std::vector;
using std::sort;

class Solution{
    public:
        vector<vector<int>> threeSum(vector<int> &nums){
            vector<vector<int>> res;
            if(nums.empty()){
                return res;
            }
            //升序排序
            sort(nums.begin(), nums.end());
            for(int pos=0;pos<nums.size();++pos){
                int temp = -nums[pos];
                int i = pos+1;
                int j = nums.size()-1;
                while(i < j){
                    if(temp > nums[i] + nums[j]){
                        ++i;
                    }else if(temp < nums[i] + nums[j]){
                        --j;
                    }else{
                        vector<int> v = {nums[pos], nums[i], nums[j]};
                        res.push_back(v);
                        //去重
                        while(i < j && nums[i] == v[1]){
                            ++i;
                        }
                        while(i < j && nums[j] == v[2]){
                            --j;
                        }
                    }
                }
                //去重
                while(pos+1 < nums.size() && nums[pos+1] == nums[pos]){
                    ++pos;
                }
            }
            return res;
        }
};


int main(){
    vector<int> v = {-1, 0, 1,2,-1,-4};

    Solution s;
    vector<vector<int>> res = s.threeSum(v);

    for(auto v: res){
        for(auto n: v){
            cout<<n<<", ";
        }
        cout<<endl;
    }

    return 0;
}
