/*
🚀 LeetCode 42. Trapping Rain Water
Problem Statement:
Given n non-negative integers representing an elevation map where the width of each bar is 1,
compute how much water it can trap after raining.

Example:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6

*** Approach (Two Pointers - Optimal):  min(Lmax, rmax) - height [i] for each i ;
- Use two pointers (`left` and `right`) starting from both ends.
- Maintain `lmax` and `rmax` as the maximum height seen so far from left and right.
- At each step, move the pointer with smaller max because trapped water depends on the smaller side.
- Accumulate trapped water as (lmax - height[left]) or (rmax - height[right]).

Time Complexity: O(n)  -> single pass through array
Space Complexity: O(1) -> only a few variables
*/

class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0;
        int right = h.size() - 1;
        int lmax = 0, rmax = 0, water = 0;

        while (left < right) {
            lmax = max(lmax, h[left]);
            rmax = max(rmax, h[right]);

            if (lmax < rmax) {
                water += lmax - h[left++];
            } else {
                water += rmax - h[right--];
            }
        }
        return water;
    }
};
