class Solution {
public:
        vector<vector<int>> generateMatrix(int n) {
                int val = 1;
                vector<vector<int>> matrix(n, vector<int>(n));
                int rUpper = 0, rDowner = n - 1;
                int cLeft = 0, cRight = n - 1;

                int r = 0, c = 0;

                enum {
                        RIGHT,
                        DOWN,
                        LEFT,
                        UP
                } direct;
                direct = RIGHT;

                while (val <= n * n) {
                        matrix[r][c] = val;

                        switch(direct) {
                                case RIGHT:
                                        if (c == cRight) {
                                                r++;
                                                direct = DOWN;
                                                rUpper++;
                                        }
                                        else
                                                c++;
                                        break;
                                case DOWN:
                                        if (r == rDowner) {
                                                c--;
                                                direct = LEFT;
                                                cRight--;
                                        }
                                        else
                                                r++;
                                        break;
                                case LEFT:
                                        if (c == cLeft) {
                                                r--;
                                                direct = UP;
                                                rDowner--;
                                        }
                                        else
                                                c--;
                                        break;
                                case UP:
                                        if (r == rUpper) {
                                                c++;
                                                direct = RIGHT;
                                                cLeft++;
                                        }
                                        else
                                                r--;
                                        break;
                                default:
                                        break;
                        }


                        val++;
                }


                return matrix;
        }
};
