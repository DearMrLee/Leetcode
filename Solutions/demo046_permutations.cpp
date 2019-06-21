#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::swap;

/*
 * 全排列问题
 * 参考：https://blog.csdn.net/qq_32805671/article/details/81280530
 */

class Solution{
    public:
        vector<vector<int>> Permute(vector<int> &nums){
            //方法2：DFS。不改变nums
            vector<vector<int>> res;
            vector<int> flag(nums.size(), 0);  //0表示未被访问过，1表示访问过
            vector<int> temp;
            DFS(nums, flag, temp, res);
            return res;


            //方法1：递归。交换元素位置的思想，会改变nums
            /*
            vector<vector<int>> res;
            Permute(nums, 0, res);
            return res;
            */
        }
        //交换元素位置
        void Permute(vector<int> &nums, int step, vector<vector<int>> &res){
            if(step == nums.size()){
                res.push_back(nums);
                //for(auto num: nums){
                //    cout<<num<<", ";
                //}
                //cout<<endl;
                return;
            }
            for(int i=step;i<nums.size();++i){
                swap(nums[i], nums[step]);
                Permute(nums, step+1, res);
                swap(nums[i], nums[step]);
            }
        }
        //深度优先遍历
        void DFS(vector<int> &nums, vector<int> &flag, vector<int> &temp, vector<vector<int>> &res){
            if(temp.size() == nums.size()){
                res.push_back(temp);
                for(auto num: temp){
                    cout<<num<<", ";
                }
                cout<<endl;
                return;
            }
            for(int i=0;i<nums.size();++i){
                if(flag[i] == 1){  //表示访问过此位置元素
                    continue;
                }
                temp.push_back(nums[i]);
                flag[i] = 1;
                DFS(nums, flag, temp, res);
                flag[i] = 0;
                temp.pop_back();  //删除最后一个元素。注意，temp的大小也会-1
            }
        }

};


int main(){
    
    vector<int> nums = {1,2,3};

    Solution s;
    s.Permute(nums);
    
    return 0;
}
