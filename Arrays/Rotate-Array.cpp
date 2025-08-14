/*
LeetCode Problem 189: Rotate Array

Problem:
Given an integer array nums, rotate the array to the right by k steps, 
where k is non-negative.

Example:
Input:  nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]

Approach:
1. Normalize k → k = k % n (handles cases where k > n).
2. Reverse the entire array.
3. Reverse the first k elements.
4. Reverse the remaining n-k elements.
This approach rotates in-place using the reversal algorithm.

Time Complexity:  O(n)  - Each reversal takes O(n)
Space Complexity: O(1)  - In-place modification
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = k % n; // Normalize k

        // Reverse helper lambda
        auto reverseArray = [&](int left, int right) {
            while (left < right) {
                swap(nums[left++], nums[right--]);
            }
        };

        // Step 1: Reverse entire array
        reverseArray(0, n - 1);
        // Step 2: Reverse first k elements
        reverseArray(0, k - 1);
        // Step 3: Reverse last n-k elements
        reverseArray(k, n - 1);
    }
};
