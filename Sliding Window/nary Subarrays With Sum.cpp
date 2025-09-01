// Problem: 930. Binary Subarrays With Sum
// Link: https://leetcode.com/problems/binary-subarrays-with-sum/
//
// Approach:  *************** I folowed two  pionter sliding widow approach on leetcode
// - We want to count subarrays whose sum == goal.
// - Use prefix sum + hashmap to store counts of prefix sums.
// - For each prefix sum `curr`, we check if `curr - goal` exists in hashmap.
// - Add its frequency to the result.
//
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case: sum == goal at start
        
        int currSum = 0, count = 0;

        for (int num : nums) {
            currSum += num;

            if (prefixCount.find(currSum - goal) != prefixCount.end()) {
                count += prefixCount[currSum - goal];
            }

            prefixCount[currSum]++;
        }

        return count;
    }
};
