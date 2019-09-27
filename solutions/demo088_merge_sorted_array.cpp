#include <iostream>
#include <vector>

using namespace std;


class Solution{
    public:
        void merge(vector<int> &nums1, int m, vector<int> &nums2, int n){
            while(m>0 && n>0){
                if(nums1[m-1] > nums2[n-1]){
                    nums1[m+n-1] = nums1[m-1];
                    --m;
                }else{
                    nums1[m+n-1] = nums2[n-1];
                    --n;
                }
            }
            while(n > 0){
                nums1[n-1] = nums2[n-1];
                --n;
            }
        }

};

int main(){
    
    vector<int> nums1 = {1,2,3, 0,0,0};
    int m = 3;
    vector<int> nums2 = {2,5,6};
    int n = 3;

    Solution s;
    s.merge(nums1, m, nums2, n);

    for(auto num: nums1){
        cout<<num<<",";
    }
    cout<<endl;


    return 0;
}
