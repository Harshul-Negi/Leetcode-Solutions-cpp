// Problem: 151. Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
//
// Problem Statement:
// Given an input string s, reverse the order of the words. 
// A word is defined as a sequence of non-space characters. 
// The words in s will be separated by at least one space.
// The returned string should not contain leading or trailing spaces, 
// and words should be separated by a single space.
//
// Example:
// Input: "   the   sky is   blue  "
// Output: "blue is sky the"
//
// Approach:
// 1. Reverse the entire string.
// 2. Iterate through the string, skipping extra spaces and extracting words.
// 3. Copy words in place while reversing each word back to its correct orientation.
// 4. Insert a single space after each word.
// 5. At the end, remove the trailing space using resize().
//
// Time Complexity: O(n)
// - O(n) to reverse the entire string.
// - O(n) to iterate and reverse each word.
// Space Complexity: O(1) (in-place manipulation)

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());   // Step 1: Reverse entire string
        int n = s.size();
        int left = 0, right = 0, i = 0;

        while (i < n) {
            while (i < n && s[i] == ' ')  // Skip spaces
                i++;
            if (i == n) break;

            // Copy current word
            while (i < n && s[i] != ' ') {
                s[right++] = s[i++];
            }

            // Reverse current word to correct orientation
            reverse(s.begin() + left, s.begin() + right);

            // Add single space
            s[right++] = ' ';

            // Update left pointer
            left = right;
            i++;
        }

        // Remove trailing space
        s.resize(right - 1);

        return s;
    }
};
