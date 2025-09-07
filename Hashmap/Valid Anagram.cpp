/*
📘 Problem: Valid Anagram (LeetCode 242)

📝 Description:
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

🔹 Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

🔹 Example 2:
Input: s = "rat", t = "car"
Output: false

🔒 Constraints:
- 1 <= s.length, t.length <= 5 * 10^4
- s and t consist of lowercase English letters.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        // Count frequency for s
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Subtract frequency for t
        for (char c : t) {
            freq[c - 'a']--;
            if (freq[c - 'a'] < 0) return false; // Early exit
        }

        return true;
    }
};
