class Solution {
public:
        bool isValidSudoku(vector<vector<char>>& board) {
                /* 区纪录 */
                bool sections[9][9];
                memset(sections, 0, 9 * 9);

                /* 行纪录 */
                bool rows[9][9], cols[9][9];
                memset(rows, 0, 9 * 9);
                /* 列纪录 */
                memset(cols, 0, 9 * 9);

                for (int r = 0; r < board.size(); r++) {
                        for (int c = 0; c < board.front().size(); c++) {
                                const char &cheese = board[r][c];

                                if (cheese == '.')
                                        continue;
                                
                                if (rows[r][cheese - '0' - 1])
                                        return false;
                                else
                                        rows[r][cheese - '0' - 1] = true;

                                if (cols[c][cheese - '0' - 1])
                                        return false;
                                else
                                        cols[c][cheese - '0' - 1] = true;
                                
                                if (sections[r / 3 * 3 + c / 3][cheese - '0' - 1])
                                        return false;
                                else
                                        sections[r / 3 * 3 + c / 3][cheese - '0' - 1] = true;

                        }
                }


                return true;
        }
};
