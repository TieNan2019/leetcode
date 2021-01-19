class Solution {
public:
        vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
                int rows = grid.size();
                int cols = grid[0].size();

                vector<vector<int>> ans(rows, vector<int>(cols));

                for (int row = 0; row < rows; row++) {
                        for (int col = 0; col < cols; col++) {
                                /* 右移 */
                                int c = (col + k) % cols;
                                /* 下沉 */
                                int r = (row + (col + k) / cols) % rows;

                                ans[r][c] = grid[row][col];
                        }
                }

                return ans;
        }
};
