// Problem: 992. Subarrays with K Different Integers
// Link: https://leetcode.com/problems/subarrays-with-k-different-integers/
//
// Approach:
// - Count subarrays with exactly k distinct elements.
// - Trick: exactly(k) = atMost(k) - atMost(k-1).
// - Use sliding window + hashmap (frequency count).
//
// Steps:
// 1. Expand window with right pointer `r`, add nums[r] into freq.
// 2. While distinct > k, shrink from left pointer `l`.
// 3. Add `(r - l + 1)` subarrays ending at `r`.
// 4. Return atMost(k) - atMost(k-1).
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int l = 0, count = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (freq[nums[r]] == 0) k--;   // new distinct
            freq[nums[r]]++;

            while (k < 0) {
                freq[nums[l]]--;
                if (freq[nums[l]] == 0) k++;
                l++;
            }
            count += (r - l + 1);
        }
        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};
