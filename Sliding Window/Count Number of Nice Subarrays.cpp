// Problem: 1248. Count Number of Nice Subarrays
// Link: https://leetcode.com/problems/count-number-of-nice-subarrays/
//
// Approach:
// - A "nice subarray" has exactly k odd numbers.
// - Trick: count subarrays with at most k odd numbers, call it `solve(nums, k)`.
// - Then, result = solve(nums, k) - solve(nums, k-1).
//
// How `solve(nums, k)` works:
// - Use sliding window.
// - Expand right pointer `r`, count odds.
// - Shrink from left `l` if odds exceed k.
// - For each window, add `(r - l + 1)` valid subarrays ending at `r`.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int solve(vector<int>& nums, int k) {
        if (k < 0) return 0;

        int l = 0, odd = 0, count1 = 0;
        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0) odd++;

            while (odd > k) {
                if (nums[l++] % 2 != 0) odd--;
            }

            count1 += (r - l + 1); 
        }
        return count1;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k - 1);
    }
};
