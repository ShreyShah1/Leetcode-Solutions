/*AUTHOR: Shrey Shah
  Language: Cpp
  LeetCode Question No: 209
  Given an array of n positive integers and a positive integer s, find the minimal length of a  subarray of which the sum ≥ s. If there isn't one, return 0 instead.

  For example, given the array [2,3,1,2,4,3] and s = 7,
  the subarray [4,3] has the minimal length under the problem constraint.

*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int length = nums.size();
        int minLength = INT_MAX;
        int start = 0;
        int curSum = 0;
        for (int end = 0 ; end < length ; end++) {
            curSum += nums[end];
            // Move the start till the sum becomes less.
            while (curSum >= s) {
                // Save the minimum length.
		if (end - start + 1 < minLength) {
                    minLength = end - start + 1;
                }
                curSum -= nums[start++];
            }
        }
	// Handling edge case if you don't find any solution.
        return (minLength == INT_MAX) ? 0 : minLength;
    }
};
