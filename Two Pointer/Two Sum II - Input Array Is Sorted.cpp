/*
Problem: 167. Two Sum II - Input Array Is Sorted

Approach:
- Use two pointers since the array is sorted.
- Start with left=0, right=n-1.
- If sum < target, increase left (need bigger number).
- If sum > target, decrease right (need smaller number).
- If sum == target, return the indices (1-based).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return {left + 1, right + 1}; // 1-indexed
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        return {}; // should never reach here
    }
};
