/**
 * 参考：https://www.cnblogs.com/grandyang/p/4325648.html
 * 解决方法：
 * 1. 中间的数小于最右边的数，则右半边严格升序
 * 2. 中间的数大于最右边的数，则左半边严格升序
 * 3. 通过1、2判断目标数在哪部分然后二分查找即可
 */


#include <iostream>
#include <vector>

using std::vector;
using std::endl;
using std::cout;

class Solution{
    
public:

    int search(vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size()-1;
        int mid;
        while(start <= end){
            mid = start + ((end -start) >> 2);
            if (nums[mid] == target){
                return mid;
            }
            if (nums[mid] < nums[end]) {
                if(target > nums[mid] && target <= nums[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }else{
                if(target >= nums[start] && target < nums[mid]){
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
                
            }
        }
        return -1;
    }

};

int main(){

    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0; //todo 做成命令行参数形式

    Solution s;
    int res = s.search(nums, target);
    cout << res << endl;

    return 0;
}
