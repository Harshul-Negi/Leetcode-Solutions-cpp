/*
Problem: LeetCode 121. Best Time to Buy and Sell Stock

Given an array prices[] where prices[i] is the price of a stock on day i, 
you want to maximize your profit by choosing a single day to buy one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve. 
If no profit can be made, return 0.

Approach:
- Keep track of the minimum price seen so far (minPrice).
- For each day, calculate the profit if sold today (prices[i] - minPrice).
- Update maxProfit if this profit is higher.
- Update minPrice if today’s price is lower.
- This ensures we find the largest difference between a later selling price and an earlier buying price.

Time Complexity: O(n)  — Single pass through the array
Space Complexity: O(1) — Only a few extra variables
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);                 // update buying price
            maxProfit = max(maxProfit, price - minPrice);    // calculate profit
        }

        return maxProfit;
    }
};
