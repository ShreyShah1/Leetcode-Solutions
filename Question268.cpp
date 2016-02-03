/**
 * AUTHOR: Shrey Shah
 * Language: Cpp
 * LeetCode Question No: 268

 * Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

 * For example,
 * Given nums = [0, 1, 3] return 2.

 * Note:
 * Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        // Put the number's in the array to their corresponding indices.
        // For Example: n = 3 and array is 2 0 1.
        // Rearrange it to 0 1 2.
        for (int i = 0 ; i < n ; i++) {
            while (!(nums[i] == i || nums[i] >= n)) {
                // Swap index i with index nums[i].
                int temp = nums[i];
                nums[i] = nums[nums[i]];
                nums[temp] = temp;
            }
        }
        // Now find the index which is mismatched with its value.
        for (int i = 0 ; i < n ; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        //Edge case.
        return n;
    }
};
