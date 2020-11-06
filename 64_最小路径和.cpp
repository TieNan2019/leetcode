class Solution {
public:

        int minPathSum(vector<vector<int>>& grid)
        {
                int rows = grid.size(), cols = grid[0].size();

                vector<vector<int>> cost (rows, vector<int>(cols));
                cost[rows - 1][cols - 1] = grid[rows - 1][cols - 1];

                for (int i = rows - 1; i >= 0; i--) {
                        for (int j = cols - 1; j >= 0; j--) {
                                if (j == cols - 1 && i == rows - 1)
                                        continue;

                                int right = INT_MAX, down = INT_MAX;

                                if (i + 1 < rows)
                                        down = cost[i + 1][j];
                                if (j + 1 < cols)
                                        right = cost[i][j + 1];
                        
                                cost[i][j] = (down < right ? down : right) + grid[i][j];
                        }
                }

                return cost[0][0];
        }
};
