/*
Problem: 380. Insert Delete GetRandom O(1)

Problem Statement:
Implement the RandomizedSet class:
- RandomizedSet() Initializes the RandomizedSet object.
- bool insert(int val): Inserts an item val into the set if not present. Returns true if inserted.
- bool remove(int val): Removes an item val from the set if present. Returns true if removed.
- int getRandom(): Returns a random element from the current set.

Each function must run in O(1) average time.

Approach:
We use:
1. A vector<int> nums to store elements for O(1) random access.
2. An unordered_map<int, int> mp that maps a value → index in nums.
   - Insert: Add val at the end of nums and record its index in mp.
   - Remove: Swap val with the last element, update the index of the swapped element in mp, then pop_back().
   - getRandom: Return nums[rand() % nums.size()].

This ensures O(1) operations on average.

Time Complexity:
- Insert: O(1)
- Remove: O(1)
- GetRandom: O(1)

Space Complexity: O(n) — for storing elements in vector and hashmap.
*/

class RandomizedSet {
public:
    vector<int> nums;                     // stores the elements
    unordered_map<int, int> mp;           // maps element -> index in nums
    
    RandomizedSet() {}
    
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        nums.push_back(val);
        mp[val] = nums.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int last = nums.back();
        int idx = mp[val];
        
        nums[idx] = last;       // move last element to deleted index
        mp[last] = idx;
        
        nums.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};
