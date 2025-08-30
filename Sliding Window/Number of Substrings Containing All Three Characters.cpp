// Problem: 1358. Number of Substrings Containing All Three Characters
// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
//
// Approach:
// - Use a vector<int> last(3, -1) to store the last seen index of 'a', 'b', 'c'.
//   -> last[0] -> 'a', last[1] -> 'b', last[2] -> 'c'
// - At each step, update last[s[i]-'a'] with current index.
// - The number of valid substrings ending at i = (min(last[0], last[1], last[2]) + 1).
//
// Time Complexity: O(n)
// Space Complexity: O(1) (since vector size = 3, constant)

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3, -1); // last seen positions of 'a','b','c'
        int count = 0;

        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;  // update last seen for current char

            int minLast = min({last[0], last[1], last[2]});
            if (minLast != -1) {
                count += (minLast + 1);
            }
        }
        return count;
    }
};
