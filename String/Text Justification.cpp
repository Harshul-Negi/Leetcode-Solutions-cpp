/*
🔹 LeetCode 68. Text Justification

📝 Problem:
Given an array of words and a width maxWidth, format the text such that each line 
has exactly maxWidth characters and is fully (left and right) justified.

- You should pack as many words as fit into each line.
- Extra spaces should be distributed as evenly as possible.
- If the number of spaces on a line does not divide evenly, the left slots get more spaces.
- The last line should be left-justified, and no extra space is inserted between words.

Example:
Input: words = ["This","is","an","example","of","text","justification."], maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

------------------------------------------------------

💡 Approach (Greedy + String Construction):
1. Greedily fit as many words as possible into a line without exceeding maxWidth.
2. If the line is NOT the last line:
   - Distribute spaces evenly between words.
   - If spaces don’t divide evenly, assign more to the left slots.
3. If the line IS the last line:
   - Left justify → join words with a single space and pad trailing spaces.

------------------------------------------------------

⏱ Complexity:
- Time:  O(N)   → where N = total number of characters in words
- Space: O(1)   → output result only, no extra DS

✅ Optimal Greedy Solution
*/

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int j = i, lineLen = 0;

            // 1. Greedily take words for this line
            while (j < n && lineLen + words[j].size() + (j - i) <= maxWidth) {
                lineLen += words[j].size();
                j++;
            }

            int spaces = maxWidth - lineLen;   // total spaces left in this line
            int gaps = j - i - 1;             // number of gaps between words
            string line = "";

            // 2. If last line OR only one word → left-justify
            if (j == n || gaps == 0) {
                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) line += ' ';
                }
                line += string(maxWidth - line.size(), ' ');
            }
            // 3. Otherwise → distribute spaces evenly
            else {
                int spaceEach = spaces / gaps;
                int extra = spaces % gaps;

                for (int k = i; k < j; k++) {
                    line += words[k];
                    if (k < j - 1) {
                        line += string(spaceEach + (extra > 0 ? 1 : 0), ' ');
                        if (extra > 0) extra--;
                    }
                }
            }

            ans.push_back(line);
            i = j;
        }

        return ans;
    }
};
