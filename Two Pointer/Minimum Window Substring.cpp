/*
📝 LeetCode 76. Minimum Window Substring

📌 Problem Statement:
Given two strings `s` and `t`, return the minimum window substring of `s` 
such that every character in `t` (including duplicates) is included in the window. 
If no such substring exists, return "".

💡 Approach:
- Use Sliding Window + Hashmaps.
- Count frequency of characters in `t` using `need`.
- Expand right pointer `r` while tracking characters in `window`.
- When all needed characters are satisfied, try shrinking from the left `l`.
- Keep track of the smallest valid window.
- Return result if found, else "".

⏱️ Complexity:
- Time: O(|s| + |t|)
- Space: O(|alphabet|)

✅ Example:
Input:  s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        
        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;
        
        int have = 0, needCount = need.size();
        int l = 0, start = -1;
        int minlen = INT_MAX;
        
        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;
            
            if (need.find(c) != need.end() && window[c] == need[c]) {
                have++;
            }
            
            while (have == needCount) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }
                
                char leftChar = s[l];
                window[leftChar]--;
                if (need.find(leftChar) != need.end() && window[leftChar] < need[leftChar]) {
                    have--;
                }
                l++;
            }
        }
        
        return start == -1 ? "" : s.substr(start, minlen);
    }
};
