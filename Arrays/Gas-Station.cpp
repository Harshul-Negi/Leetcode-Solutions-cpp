/*
Problem: 134. Gas Station

Problem Statement:
There are n gas stations arranged in a circle, where the amount of gas at the i-th station is gas[i].
You have a car with an unlimited gas tank and it costs cost[i] to travel from station i to its next (i+1).
You begin the journey with an empty tank at one of the gas stations.
Return the starting gas station’s index if you can travel around the circuit once in the clockwise direction, otherwise return -1.
If there exists a solution, it is guaranteed to be unique.

Example:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
Output: 3
Explanation:
Start at station 3 (0-indexed) with 0 gas.
Refuel = 4. Travel to 4 → gas left = 3.
Refuel = 5. Travel to 0 → gas left = 6.
Refuel = 1. Travel to 1 → gas left = 4.
Refuel = 2. Travel to 2 → gas left = 4.
Refuel = 3. Travel to 3 → gas left = 4.
You completed the circuit.

Approach (Greedy):
1. First, check if total gas < total cost → impossible to complete → return -1.
2. Traverse stations keeping track of current tank.
   - If tank becomes negative, reset start to the next station (i+1) and reset tank to 0.
   - Because if we can’t reach i+1 from the current start, none of the stations between start and i can be a valid start.
3. The index stored in `start` will be the answer.

Time Complexity: O(n) — Single pass through the array
Space Complexity: O(1) — No extra space used
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, totalCost = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if (totalGas < totalCost) return -1; // impossible case

        int tank = 0, start = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) { // reset starting point
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};
