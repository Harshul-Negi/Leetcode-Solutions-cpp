/*
LeetCode 3. Longest Substring Without Repeating Characters

Approach:
- Sliding window + HashMap
- Expand right pointer while characters are unique.
- If duplicate found, move left pointer to just after last seen position.
- Keep track of max window length.

Time Complexity: O(n)
Space Complexity: O(1) for ASCII / O(k) for character set size
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(256, -1); // store last index of each char
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            if (lastIndex[s[right]] >= left) {
                // Move left pointer after the duplicate
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right; 
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
