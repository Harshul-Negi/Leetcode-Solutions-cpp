/*
🎯 Problem: 1423. Maximum Points You Can Obtain from Cards
📌 Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

----------------------------------
📝 Problem Statement (short):
You are given an integer array `cardPoints` and an integer `k`. 
You can take cards from either the beginning or the end of the array. 
Return the maximum score you can obtain by taking exactly `k` cards.

----------------------------------
💡 Approach:
- Instead of directly picking k cards, think about which cards you leave.
- Total cards = n, you must leave (n - k) consecutive cards.
- Minimize the sum of that subarray → maximize the total score.
- Sliding window of size (n-k) finds the minimum subarray sum.

----------------------------------
⏱️ Time Complexity: O(n)
📦 Space Complexity: O(1)
*/

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int c : cardPoints) total += c;

        // window size = n - k
        int window = n - k;
        int curr = 0;

        // sum of first window
        for (int i = 0; i < window; i++) curr += cardPoints[i];

        int minSum = curr;
        for (int i = window; i < n; i++) {
            curr += cardPoints[i] - cardPoints[i - window];
            minSum = min(minSum, curr);
        }

        return total - minSum;
    }
};
