class Solution {
public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
                int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
                if (obstacleGrid[rows-1][cols-1])
                        return 0;

                vector<vector<long>> paths(rows, vector<long>(cols, 0));
                paths[rows-1][cols-1] = 1;

                for (int i = rows - 1; i >= 0; i--) {
                        for (int j = cols - 1; j >= 0; j--) {
                                if (obstacleGrid[i][j])
                                        continue;
                                
                                if (i + 1 < rows)
                                        paths[i][j] += paths[i+1][j];

                                if (j + 1 < cols)
                                        paths[i][j] += paths[i][j+1];
                        }
                }

                return paths[0][0];
        }
};
