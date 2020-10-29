class Solution {
public:
        vector<vector<int>> generate(int numRows) {
                if (numRows == 0)
                        return {};
                vector<vector<int>> res(1, vector<int>({1}));

                // /*
                for (int i = 1; i < numRows; i++) {
                        vector<int> line = {1};
                        for (int j = 0; j < res.back().size() - 1; j++) {
                                line.push_back(res.back()[j] + res.back()[j+1]);
                        }
                        line.push_back(1);
                        res.push_back(line);
                }
                // */

                return res;
        }
};
