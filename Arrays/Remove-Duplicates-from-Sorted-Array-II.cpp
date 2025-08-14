/*
LeetCode Problem 80: Remove Duplicates from Sorted Array II

Problem:
Given a sorted array nums, remove the duplicates in-place such that each unique 
element appears at most twice. The relative order of the elements should be kept 
the same.

Return the new length of the array after removing the excess duplicates.

Example:
Input:  nums = [0,0,1,1,1,1,2,3,3]
Output: 7
Explanation: Your function should modify nums in-place to [0,0,1,1,2,3,3] 
and return 7.

Approach:
1. Since the array is sorted, duplicates are adjacent.
2. Use a two-pointer approach:
   - `i` (write index) starts from 2 (allowing the first two elements).
   - `j` iterates from index 2 onwards.
   - For each nums[j], compare it with nums[i-2]. 
     If they are different, copy nums[j] to nums[i] and increment i.
3. This ensures that each element appears at most twice.

Time Complexity:  O(n)  - Single pass through the array
Space Complexity: O(1)  - In-place modification
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n; // If array size is 2 or less, no need to modify

        int i = 2; // write index
        for (int j = 2; j < n; j++) {
            // Only write nums[j] if it is not equal to the element at i-2
            if (nums[j] != nums[i - 2]) {
                nums[i++] = nums[j];
            }
        }
        return i; // New length of the modified array
    }
};
