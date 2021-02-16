class Solution {
public:
        void rotate(vector<vector<int>>& matrix) {
                for (int r = 0; r < matrix.size(); r++) {
                        for (int c = 0; c < matrix[0].size() / 2; c++) {
                                int tmp = matrix[r][c];
                                matrix[r][c] = matrix[r][matrix.front().size() - 1 - c];
                                matrix[r][matrix.front().size() - 1 - c] = tmp;
                        }
                }

                for (int r = 0; r < matrix.size(); r++) {
                        for (int c = 0; c < matrix.size() - 1 - r; c++) {
                                int tmp = matrix[matrix.size() - 1 - c][matrix.size() - 1 - r];
                                matrix[matrix.size() - 1 - c][matrix.size() - 1 - r] = matrix[r][c];
                                matrix[r][c] = tmp;
                        }
                }
        }
};
