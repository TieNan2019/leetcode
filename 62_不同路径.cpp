class Solution {
public:
        int uniquePaths(int m, int n) {
                vector<vector<int>> rec(m, vector<int>(n));
                rec[m-1][n-1] = 1;

                for (int i = m - 1; i >= 0; i--)
                        for (int j = n - 1; j >= 0; j--) {
                                if (j + 1 < n)
                                        rec[i][j] += rec[i][j+1];
                                if (i + 1 < m)
                                        rec[i][j] += rec[i+1][j];
                        }
                

                return rec[0][0];
        }
};
