/*
Problem: Two Sum
---------------
Given an array of integers nums and an integer target, return indices of the two numbers 
such that they add up to target. You may assume that each input would have exactly one solution, 
and you may not use the same element twice.

Example:
--------
Input: nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
Explanation: nums[0] + nums[1] = 2 + 7 = 9

Approach:
---------
1. Store each element along with its original index in a vector of pairs.
2. Sort the vector based on values.
3. Use two pointers:
   - Left starts at 0, right starts at n-1.
   - If sum < target, move left pointer up.
   - If sum > target, move right pointer down.
   - If sum == target, return the original indices.

Time Complexity: O(n log n)  // Sorting step dominates
Space Complexity: O(n)       // For storing value-index pairs
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    vector<pair<int,int>> arr; // {value, original_index}
    for (int i = 0; i < nums.size(); i++) {
        arr.push_back({nums[i], i});
    }

    sort(arr.begin(), arr.end()); // Sort by value

    int left = 0, right = nums.size() - 1;

    while (left < right) {
        int sum = arr[left].first + arr[right].first;
        if (sum == target) {
            return {arr[left].second, arr[right].second};
        }
        else if (sum < target) {
            left++;
        }
        else {
            right--;
        }
    }
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
