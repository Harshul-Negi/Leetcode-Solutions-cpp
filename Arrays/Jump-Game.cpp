/*
Problem: 55. Jump Game

Problem Statement:
You are given an integer array `nums`. Each element `nums[i]` represents your maximum 
jump length from that position.  
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation:
- Jump 1 step from index 0 to index 1.
- Then jump 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation:
- No matter what, you will always land at index 3, where nums[3] = 0.
- This makes it impossible to reach the last index.

Approach (Greedy):
- Track the farthest index we can reach (`maxReach`).
- Iterate over the array:
  - If the current index > maxReach → return false (we got stuck).
  - Update `maxReach = max(maxReach, i + nums[i])`.
- If the loop finishes, return true because the last index is reachable.

Time Complexity: O(n)   — Single pass through the array
Space Complexity: O(1)  — Constant extra space
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > maxReach) return false; // Stuck, cannot proceed
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
