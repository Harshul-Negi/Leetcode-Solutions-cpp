/*
# Problem: 49. Group Anagrams
# Link: https://leetcode.com/problems/group-anagrams/

## Approach:
- Use a hash map where the key is the **sorted version** of the string.
- All anagrams will share the same sorted key.
- Group words together based on this key.

## Complexity:
- Time: O(N * K log K), where N = number of strings, K = average string length (sorting each string).
- Space: O(N * K), for storing grouped anagrams.

## Example:
Input: ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // sorted version as key
            mp[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto &p : mp) {
            ans.push_back(p.second);
        }
        
        return ans;
    }
};
