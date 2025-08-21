/*
Problem: 6. Zigzag Conversion

Problem Statement:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
(you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Given a string `s` and an integer `numRows`, return the string written in a zigzag pattern.

Example:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Constraints:
- 1 <= s.length <= 1000
- s consists of English letters (lower-case and upper-case), ',' and '.'.
- 1 <= numRows <= 1000

Approach:
- If numRows == 1, simply return the original string because zigzag = straight line.
- Create a vector of strings, each representing a row.
- Traverse the input string and simulate writing characters in a zigzag manner:
  - Use a `currRow` pointer to track which row we’re filling.
  - Use a direction flag (`goingDown`) to decide whether to move down or up in rows.
- Finally, concatenate all rows to form the result.

Time Complexity: O(n)  [we iterate through the string once]
Space Complexity: O(n) [we store characters in row buckets before combining]
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size()) return s;

        vector<string> rows(min(numRows, int(s.size())));
        int currRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1) goingDown = !goingDown;
            currRow += goingDown ? 1 : -1;
        }

        string result;
        for (string& row : rows) {
            result += row;
        }
        return result;
    }
};
