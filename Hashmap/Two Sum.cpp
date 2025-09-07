/*
# Problem: 1. Two Sum
# Link: https://leetcode.com/problems/two-sum/

## Approach:
- Use a hash map to store numbers and their indices as we iterate.
- For each number, check if (target - current) exists in the map.
- If it does, return the indices of the two numbers.
- This avoids the O(N^2) brute force.

## Complexity:
- Time: O(N), since we traverse the array once.
- Space: O(N), for the hash map.

## Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]  (since nums[0] + nums[1] = 9)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // number -> index
        
        for (int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if (mp.find(need) != mp.end()) {
                return {mp[need], i};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};
