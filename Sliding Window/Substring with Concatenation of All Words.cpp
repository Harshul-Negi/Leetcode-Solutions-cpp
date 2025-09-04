/**
# Title: 30. Substring with Concatenation of All Words
# Difficulty: Hard
# Tags: Sliding Window, Hash Map, String

# Problem:
# You are given a string s and a list of words, all of the same length.
# Return all starting indices of substring(s) in s that is a concatenation 
# of each word in words exactly once and without any intervening characters.

# Example:
# Input: s = "barfoothefoobarman", words = ["foo","bar"]
# Output: [0,9]

# Constraints:
# - 1 <= s.length <= 10^4
# - words[i].length >= 1
# - Sum of lengths of words[i] does not exceed 10^4
# - Words may repeat

# Approach:
# - Use a sliding window with step size equal to word length.
# - Maintain two hash maps:
#   (1) `og` → original word frequency
#   (2) `window` → current window word frequency
# - Expand right pointer in steps of word length.
# - If a word exceeds its allowed count, shrink from the left.
# - If window contains all words, record starting index.
# - Reset window when encountering invalid word.
**/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty() || s.empty()) return ans;
        
        unordered_map<string, int> og;
        for (string &w : words) og[w]++;
        
        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        
        // Loop over all possible offsets
        for (int i = 0; i < wordLen; i++) {
            int left = i;
            int count = 0;
            unordered_map<string, int> window;
            
            for (int right = i; right + wordLen <= s.size(); right += wordLen) {
                string word = s.substr(right, wordLen);
                
                if (og.find(word) != og.end()) {
                    window[word]++;
                    count++;
                    
                    // Shrink window if word occurs too many times
                    while (window[word] > og[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    
                    // Valid window found
                    if (count == wordCount) {
                        ans.push_back(left);
                        
                        // Slide one step ahead
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    // Reset window if word not in dict
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        
        return ans;
    }
};
