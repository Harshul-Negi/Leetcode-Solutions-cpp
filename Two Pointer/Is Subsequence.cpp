/*
🔹 LeetCode 392. Is Subsequence

📝 Problem:
Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
A subsequence is a string that can be derived from another string by deleting some (or none) characters 
without changing the order of the remaining characters.

Example:
Input: s = "abc", t = "ahbgdc"
Output: true

------------------------------------------------------

💡 Approach (Greedy - Two Pointers):
1. Use two pointers (i for s, j for t).
2. Move through t with j:
   - If characters match (s[i] == t[j]), move i forward.
   - Always move j forward.
3. At the end, if i == s.size(), then all characters of s were found in order.

------------------------------------------------------

⏱ Complexity:
- Time:  O(|t|)   → we scan t once
- Space: O(1)     → only pointers used

✅ This is the optimal solution for a single query.
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};
