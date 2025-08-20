/*
Problem: 135. Candy

Problem Statement:
There are n children standing in a line, each child is assigned a rating value.
We need to distribute candies to these children such that:
1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their immediate neighbors.
Return the minimum number of candies required.

Approach (Greedy with Two Passes):
- First Pass (Left to Right):  
  If `ratings[i] > ratings[i-1]`, then `candies[i] = candies[i-1] + 1`.
  (This ensures the increasing rating condition in forward direction.)

- Second Pass (Right to Left):  
  If `ratings[i] > ratings[i+1]`, then `candies[i] = max(candies[i], candies[i+1] + 1)`.
  (This ensures the increasing rating condition in backward direction.)

- Finally, sum up all candies.

Why Greedy Works:
- By handling both directions separately, we ensure the local optimal choice:
  - Forward ensures each child respects their left neighbor.
  - Backward ensures each child respects their right neighbor.
- The combination guarantees global optimal distribution with minimum candies.

Time Complexity: O(n) — two passes through ratings
Space Complexity: O(n) — to store candies
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);  // each child gets at least 1 candy

        // Pass 1: Left to Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Pass 2: Right to Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        // Total candies
        int total = 0;
        for (int c : candies) {
            total += c;
        }
        return total;
    }
};
