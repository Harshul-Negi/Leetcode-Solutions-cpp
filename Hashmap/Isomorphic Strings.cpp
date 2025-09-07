// ----------------------------------------------------------
// LeetCode 205. Isomorphic Strings
//
// Problem:
// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced 
// to get t. A character must map to exactly one other character, and no two 
// characters may map to the same character.
//
// Example 1:
// Input: s = "egg", t = "add"
// Output: true
//
// Example 2:
// Input: s = "foo", t = "bar"
// Output: false
//
// Example 3:
// Input: s = "paper", t = "title"
// Output: true
//
// Constraints:
// - 1 <= s.length, t.length <= 5 * 10^4
// - s and t consist of any valid ASCII characters
// ----------------------------------------------------------

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];

            if (s2t.count(a) && s2t[a] != b) return false;
            if (t2s.count(b) && t2s[b] != a) return false;

            s2t[a] = b;
            t2s[b] = a;
        }

        return true;
    }
};
