/*
Problem: 45. Jump Game II

Problem Statement:
You are given a 0-indexed array nums of length n, where nums[i] represents 
the maximum jump length from that position.
Return the minimum number of jumps needed to reach the last index.

Example:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Approach:
We use a greedy strategy:
- Traverse the array while keeping track of the farthest index reachable (`maxReach`).
- Each time we reach the boundary of the current jump (`end`), we increase jump count 
  and update `end` to the farthest index we can reach.
- This ensures we always take the minimum jumps.

Time Complexity: O(n) — Single pass through the array
Space Complexity: O(1) — No extra space used
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, end = 0, maxReach = 0;

        for (int i = 0; i < n - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            if (i == end) {   // reached the end of current jump range
                jumps++;
                end = maxReach;
            }
        }
        return jumps;
    }
};
