/*
LeetCode 1004. Max Consecutive Ones III

Approach:
- Sliding window with two pointers
- Expand right pointer and count zeros
- If zero count > k, shrink from left until valid
- Track maximum window length

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, zeroCount = 0, maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;

            while (zeroCount > k) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
