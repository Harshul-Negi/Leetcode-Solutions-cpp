/*
Problem: 238. Product of Array Except Self

Problem Statement:
Given an integer array nums, return an array answer such that answer[i] is equal to the 
product of all the elements of nums except nums[i].

The algorithm must run in O(n) time and without using the division operation.

Approach:
We use prefix and suffix products:
- Create an output array where each element initially stores the product of all elements 
  to its left (prefix).
- Then, traverse from the right, multiplying each position by the product of all elements 
  to its right (suffix).
This ensures each answer[i] = product of nums[0..i-1] * product of nums[i+1..n-1].

Time Complexity: O(n) — Two passes through the array.
Space Complexity: O(1) — Output array not counted as extra space.
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n, 1);

        // Prefix product
        int prefix = 1;
        for (int i = 0; i < n; i++) {
            answer[i] = prefix;
            prefix *= nums[i];
        }

        // Suffix product
        int suffix = 1;
        for (int i = n - 1; i >= 0; i--) {
            answer[i] *= suffix;
            suffix *= nums[i];
        }

        return answer;
    }
};
