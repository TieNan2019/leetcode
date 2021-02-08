class Solution {
public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
                if (matrix.empty())
                        return {};

                int rStart = 0, rEnd = matrix.size();
                int cStart = 0, cEnd = matrix[0].size();


                vector<int> ans;
                int state = 0;
                int r = 0, c = 0;
                while (rStart < rEnd && cStart < cEnd) {
                        switch(state) {
                                case 0:
                                        for (c = cStart; c < cEnd; c++)
                                                ans.push_back(matrix[r][c]);
                                        rStart++;
                                        c = cEnd - 1;
                                break;
                                      
                                case 1:
                                        for (r = rStart; r < rEnd; r++)
                                                ans.push_back(matrix[r][c]);
                                        cEnd--;
                                        r = rEnd - 1;
                                break;

                                case 2:
                                        for (c = cEnd - 1; c >= cStart; c--)
                                                ans.push_back(matrix[r][c]);
                                        rEnd--;
                                        c = cStart;
                                break;

                                case 3:
                                        for (r = rEnd - 1; r >= rStart; r--)
                                                ans.push_back(matrix[r][c]);
                                        cStart++;
                                        r = rStart;

                                break;

                                default:
                                        break;
                        }
                        state++;
                        state %= 4;

                }

                return ans;
        }
};
