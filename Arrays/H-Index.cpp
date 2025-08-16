/*
Problem: 274. H-Index

Problem Statement:
Given an array of integers `citations` where `citations[i]` is the number of citations 
a researcher received for their ith paper, return the researcher's h-index.

According to the definition of h-index on Wikipedia:
The h-index is defined as the maximum value of h such that the given researcher has 
published at least h papers that have each been cited at least h times.

Example:
Input: citations = [3,0,6,1,5]
Output: 3
Explanation: 
- There are 3 papers with at least 3 citations each (3,5,6).
- The rest have fewer citations. 
Thus, the h-index is 3.

Approach:
1. Sort the array in ascending order.
2. Iterate over each citation:
   - At index i, check if citations[i] >= (n - i).
   - If true, update the maximum h-index as (n - i).
3. Return the maximum h-index found.

Time Complexity: O(n log n)  — Sorting the array
Space Complexity: O(1)       — Sorting in place
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n - i) {
                ans = max(ans, n - i);
            }
        }
        return ans;
    }
};
