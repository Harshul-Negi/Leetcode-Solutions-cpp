// Problem: 424. Longest Repeating Character Replacement
// Link: https://leetcode.com/problems/longest-repeating-character-replacement/
//
// Approach:
// - Sliding window + frequency map
// - Maintain count of chars in window using hash[26].
// - Track max frequency char in window (`maxfq`).
// - Window is valid if (window length - maxfq) <= k.
// - Otherwise, shrink from left.
//
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26, 0);
        int l = 0, maxfq = 0, maxlen = 0;

        for (int r = 0; r < s.size(); r++) {
            hash[s[r] - 'A']++;
            maxfq = max(maxfq, hash[s[r] - 'A']);

            int windowSize = r - l + 1;
            int changes = windowSize - maxfq;

            if (changes > k) {
                hash[s[l] - 'A']--;
                l++;
            } else {
                maxlen = max(maxlen, windowSize);
            }
        }
        return maxlen;
    }
};
