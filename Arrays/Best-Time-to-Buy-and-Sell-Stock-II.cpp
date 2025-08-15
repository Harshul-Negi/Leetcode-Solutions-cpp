/*
Problem: 122. Best Time to Buy and Sell Stock II

Problem Statement:
You are given an integer array prices where prices[i] is the price of a given stock on the i-th day.
On each day, you may decide to buy and/or sell the stock. You can hold at most one share at a time, 
but you can buy it and then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 3.
Total profit = 4 + 3 = 7.

Approach:
We can sum all the "uphill" differences between consecutive days.
Whenever price[i] > price[i-1], we add the profit from buying at i-1 and selling at i.

Theory:
- Since we can complete unlimited transactions, every small increase can be taken as a profit.
- Taking every local increase leads to the global maximum profit.
- This is a greedy approach — local optimal choices give the global optimal result.

Time Complexity: O(n) — One pass through prices
Space Complexity: O(1) — Constant space
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};
