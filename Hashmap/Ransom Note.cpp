// Problem: 383. Ransom Note
// Link: https://leetcode.com/problems/ransom-note/
//
// Approach:
// - Count the frequency of each character in `magazine`.
// - For each character in `ransomNote`, check if it is available in magazine.
// - If magazine runs out of a character, return false.
// - Otherwise return true.
//
// Time Complexity: O(n + m)  [n = ransomNote length, m = magazine length]
// Space Complexity: O(1)     [only 26 lowercase letters]

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freq(26, 0);

        for (char c : magazine) {
            freq[c - 'a']++;
        }

        for (char c : ransomNote) {
            if (--freq[c - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};
