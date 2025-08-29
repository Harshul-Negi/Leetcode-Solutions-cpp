/*
🎯 Problem: 209. Minimum Size Subarray Sum
📌 Link: https://leetcode.com/problems/minimum-size-subarray-sum/

----------------------------------
📝 Problem Statement (short):
Given an array of positive integers `nums` and an integer `target`, 
return the minimal length of a contiguous subarray of which the sum ≥ target. 
If no such subarray exists, return 0 instead.

----------------------------------
💡 Approach (Sliding Window / Two Pointers):
1. Use two pointers (left, right) to maintain a sliding window.
2. Expand right pointer → add elements to current sum.
3. While current sum ≥ target, shrink from left to minimize window.
4. Track minimum window length.

----------------------------------
⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0, ans = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // shrink from left while sum >= target
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
