/*
🔢 LeetCode 289. Game of Life

📌 Problem Statement:
Given a 2D grid `board` of 0s (dead) and 1s (alive), compute the next state of the board
according to Conway’s Game of Life rules. Update the board **in-place**.

Rules (for each cell):
1) Any live cell with fewer than two live neighbors dies (underpopulation).
2) Any live cell with two or three live neighbors lives on.
3) Any live cell with more than three live neighbors dies (overpopulation).
4) Any dead cell with exactly three live neighbors becomes a live cell (reproduction).

🎯 Goal:
Modify `board` so that it becomes the next state.

💡 Optimal In-Place Approach (O(1) extra space):
We can encode both current and next states in each cell using two bits:
- bit0 (LSB): current state
- bit1: next state
Transitions:
- If next state is live, set bit1 to 1 → `board[r][c] |= 2`.
After processing all cells, right shift once (`>>= 1`) to finalize next state.

Counting live neighbors must use the **original** state only → check with `(board[nr][nc] & 1)`.

⏱️ Complexity:
- Time: O(m·n) — visit each cell and check up to 8 neighbors
- Space: O(1) — in-place bit encoding (ignoring the input/output board)

✅ Example:
Input:
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output (one step):
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;

        // Directions for the 8 neighbors
        static const int dirs[8][2] = {
            {-1,-1}, {-1,0}, {-1,1},
            { 0,-1},         { 0,1},
            { 1,-1}, { 1,0}, { 1,1}
        };

        // First pass: compute next state into the 2nd bit
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int live = 0;
                for (auto &d : dirs) {
                    int nr = r + d[0], nc = c + d[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        live += (board[nr][nc] & 1);  // only original state
                    }
                }

                int curr = board[r][c] & 1; // original state
                int next = 0;
                if (curr == 1) {
                    // live cell survives with 2 or 3 live neighbors
                    next = (live == 2 || live == 3) ? 1 : 0;
                } else {
                    // dead cell becomes live with exactly 3 live neighbors
                    next = (live == 3) ? 1 : 0;
                }

                if (next == 1) {
                    board[r][c] |= 2; // set next-state bit
                }
            }
        }

        // Second pass: shift to make next state the current state
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                board[r][c] >>= 1;
            }
        }
    }
};
