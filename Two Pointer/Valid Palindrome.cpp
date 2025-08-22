/*
LeetCode 125. Valid Palindrome
---------------------------------
Approach:
- Use two pointers (one at the beginning, one at the end).
- Move inward, skipping non-alphanumeric characters using isalnum().
- Compare characters in lowercase.
- If mismatch -> not a palindrome.
- Otherwise, keep moving until pointers meet.

Important Points :- isalpha(c) → returns true if c is an alphabet (a–z, A–Z).
                    isdigit(c) → returns true if c is a digit (0–9).
                    isalnum(c) → returns true if c is alphanumeric (alphabet OR digit).
                    toupper(c) → converts a lowercase letter to uppercase.
                    tolower(c) → converts an uppercase letter to lowercase.

Time Complexity: O(n)  -> each character is processed at most once
Space Complexity: O(1) -> no extra storage used
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            // skip non-alphanumeric from left
            while (i < j && !isalnum((unsigned char)s[i])) i++;
            // skip non-alphanumeric from right
            while (i < j && !isalnum((unsigned char)s[j])) j--;

            // compare after lowering case
            if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
