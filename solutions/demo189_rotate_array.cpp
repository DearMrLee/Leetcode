#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Solution{
    public:
        void Rotate(vector<int> &nums, int k){
            //方法2：原地翻转
            if(nums.empty()){
                return;
            }
            k %= nums.size();
            //1.翻转左边部分
            Reverse(nums, 0, nums.size()-k-1);
            //2.翻转右边部分
            Reverse(nums, nums.size()-k, nums.size()-1);
            //3.整个翻转
            Reverse(nums, 0, nums.size()-1);


            //方法1：借助数组
            /*
            if(nums.empty()){
                return;
            }
            k %= nums.size();
            vector<int> temp(nums.size(), 0);
            //先使用temp存储转换后的数组
            for(int i=0;i<nums.size();++i){
                temp[(i+k)%nums.size()] = nums[i];
            }
            //再将temp赋给nums
            for(int i=0;i<nums.size();++i){
                nums[i] = temp[i];
            }
            */
        }
        void Reverse(vector<int> &nums, int start, int end){
            while(start < end){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                ++start;
                --end;
            }
        }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    for(auto num: nums){
        cout<<num<<", ";
    }
    cout<<endl;

    Solution s;
    s.Rotate(nums, 3);

    for(auto num: nums){
        cout<<num<<", ";
    }
    cout<<endl;

    return 0;
}
