/*
58. Length of Last Word
------------------------
Problem:
Given a string `s` consisting of words and spaces, return the length of the last word in the string.
A word is defined as a maximal substring consisting of non-space characters only.

Approach:
- Traverse the string from the end.
- Skip trailing spaces.
- Count the characters until another space or start of the string is reached.
- Return the count.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int i = n - 1;
        
        // Step 1: Skip trailing spaces
        while (i >= 0 && s[i] == ' ') i--;
        
        // Step 2: Count characters of last word
        int length = 0;
        while (i >= 0 && s[i] != ' ') {
            length++;
            i--;
        }
        
        return length;
    }
};
