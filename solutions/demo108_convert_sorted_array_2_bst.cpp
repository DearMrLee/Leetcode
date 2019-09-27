#include <iostream>
#include <vector>
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::vector;


class Solution{
    public:
        TreeNode* SortedArrayToBST(vector<int> &nums){
            if(nums.empty()){
                return nullptr;
            } 
            return SortedArrayToBST(nums, 0, nums.size()-1);
        }
        TreeNode* SortedArrayToBST(vector<int> &nums, int start, int end){
            if(start > end){
                return nullptr;
            }
            int mid = (start + end) >> 1;
            TreeNode *head = new TreeNode(nums[mid]);
            head->left = SortedArrayToBST(nums, start, mid-1);
            head->right = SortedArrayToBST(nums, mid+1, end);
            return head;
        }

};


int main(){

    vector<int> v = {-10, -3, 0, 5, 9};

    Solution s;
    TreeNode *head = s.SortedArrayToBST(v);

    return 0;

}
