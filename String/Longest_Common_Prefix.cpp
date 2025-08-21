/*
Problem: 14. Longest Common Prefix

Approach:
1. Sort the array of strings.
2. The answer is the common prefix of the first and last string.
3. Compare characters until mismatch or end of one string.

Time Complexity: O(N log N + M), where N = number of strings, M = length of shortest string
Space Complexity: O(1)
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        
        // Step 1: Sort the strings
        sort(strs.begin(), strs.end());
        
        // Step 2: Compare first and last
        string first = strs.front();
        string last = strs.back();
        string ans = "";
        
        for(int i = 0; i < min(first.size(), last.size()); i++) {
            if(first[i] == last[i])
                ans += first[i];
            else
                break;
        }
        
        return ans;
    }
};
