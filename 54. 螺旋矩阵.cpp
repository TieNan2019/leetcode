class Solution {
public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
                vector<int> ans(matrix.size() * matrix.front().size());

                int p = 0;



                enum state_t {
                        UPPER,
                        RIGHT,
                        DOWN,
                        LEFT
                } state;

                state = UPPER;
                int r = 0, c = 0;

                int rUpper = 0, rDowner = matrix.size() - 1;
                int cLeft = 0, cRight = matrix.front().size() - 1;
                while (p < ans.size()) {
                        ans[p] = matrix[r][c];

                        switch (state) {
                                case UPPER:
                                        if (c == cRight) {
                                                rUpper++;
                                                state = RIGHT;
                                                r++;
                                        }
                                        else
                                                c++;
                                        break;
                                case RIGHT:
                                        if (r == rDowner) {
                                                cRight--;
                                                c--;
                                                state = DOWN;
                                        }
                                        else
                                                r++;
                                        break;
                                case DOWN:
                                        if (c == cLeft) {
                                                state = LEFT;
                                                r--;
                                                rDowner--;
                                        }
                                        else
                                                c--;
                                        break;
                                case LEFT:
                                        if (r == rUpper) {
                                                state = UPPER;
                                                c++;
                                                cLeft++;
                                        }
                                        else
                                                r--;
                                        break;
                                default:
                                        break;
                        }
                        p++;
                }

                return ans;
        }
};
