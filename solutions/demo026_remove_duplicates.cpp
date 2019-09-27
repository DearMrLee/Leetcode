#include <iostream>
#include <vector>


using std::cout;
using std::endl;
using std::vector;


class Solution{
    public:
        int removeDuplicates(vector<int> &nums){
            //方法2:
            if(nums.empty()){
                return 0;
            }
            int pos = 0;
            for(int i=0;i<nums.size();++i){
                if(nums[pos] != nums[i]){
                    nums[++pos] = nums[i];
                }
            }
            ++pos;
            return pos;
            
            //方法1：
            /*
            int pos = 0;
            for(int i=0;i<nums.size();){
                nums[pos++] = nums[i];
                int temp = nums[i++];
                while(i < nums.size() && temp == nums[i]){
                    ++i;
                }
            }
            return pos;
            */
        }
};

int main(){
    
    Solution s;
    vector<int> v = {1,1,2,2,2,3,3,5,6,6};
    cout<<s.removeDuplicates(v)<<endl;
    for(auto num: v){
        cout<<num<<", ";
    }
    cout<<endl;

    return 0;
}
