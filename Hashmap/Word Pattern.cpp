// ----------------------------------------------------------
// LeetCode 290. Word Pattern
// 
// Problem:
// Given a pattern and a string s, find if s follows the same pattern.
// One-to-one mapping required between characters in pattern and words in s.
//
// Example:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true
//
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false
// ----------------------------------------------------------

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word = "";
        
        // manual splitting 
        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word.push_back(s[i]);
            }
        }

        if (words.size() != pattern.size()) return false;

        map<char, string> p2w;
        map<string, char> w2p;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            if (p2w.count(c) && p2w[c] != w) return false;
            if (w2p.count(w) && w2p[w] != c) return false;

            p2w[c] = w;
            w2p[w] = c;
        }

        return true;
    }
};
