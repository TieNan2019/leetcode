class Solution {
public:

        int numWays(int n, vector<vector<int>>& relation, int k) {
                /* 邻接表 */
                map<int, vector<int>> paths;
                for (const auto &v : relation)
                        paths[v.back()].push_back(v.front());
                
                vector<vector<int>> methods(k, vector<int>(n, 0));

                for (const auto &v : relation)
                        if (v.front() == 0)
                                methods[0][v.back()]++;

                for (int level = 1; level < k; level++) {
                        for (int dst = 0; dst < n; dst++) {
                                for (auto it : paths[dst]) {
                                        methods[level][dst] += methods[level - 1][it];
                                }
                        }
                }

                return methods[k-1][n-1];
        }
};
