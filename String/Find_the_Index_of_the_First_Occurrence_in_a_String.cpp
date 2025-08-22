/*
Problem: 28. Find the Index of the First Occurrence in a String

Problem Statement:
Given two strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`.
If `needle` is not part of `haystack`, return -1.

Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6. The first occurrence is at index 0.

Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode".

Constraints:
- 1 <= haystack.length, needle.length <= 10^4
- haystack and needle consist of only lowercase English characters.

Approach:
- Use the sliding window technique:
  - For each index `i` in haystack, check if the substring starting at `i` matches `needle`.
- If a match is found, return `i`.
- If the loop finishes without finding a match, return -1.

Time Complexity: O((n-m+1) * m)  [n = length of haystack, m = length of needle]
Space Complexity: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
        return -1;
    }
};
