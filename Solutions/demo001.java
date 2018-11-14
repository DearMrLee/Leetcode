package demo001;

import java.util.Arrays;

public class Solution {

	/**
     * Give an array, return indices of the two numbers such that 
     * they add up to a specific target.
     * @param nums array of integers
     * @param target sum of two integers
     * @return array of indices
     */
    public int[] twoSum(int[] nums, int target){
        if(nums==null) {
            return null;
        }
        for(int i = 0; i<nums.length;i++) {
            for(int j=i+1;j<nums.length;j++) {
                if(nums[i]+nums[j] == target) {
                    return new int[] {i,j};
                }
            }
        }
        return null;
    }
    
    /**
     * main
     * @param args
     */
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {2,7,11,15};
        int target = 26;
        System.out.println(Arrays.toString(solution.twoSum(nums, target)));
    }
}
