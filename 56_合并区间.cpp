class Solution {
public:
        /* 路径点 */
        typedef struct {
                /* 表示当前的数是否出现过 */
                bool occupied;
                /* 表示当前数是否和下一个数字相连 */
                bool concatnate;
        } rec_t;

        #define LEN_P    3001
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
                /* 模拟一个路径 */
                rec_t path[LEN_P];
                memset(path, 0, LEN_P * sizeof(rec_t));

                for (const auto &v : intervals) {
                        /* 前面的每个数都是连续的 */
                        for (int i = v.front(); i < v.back(); i++) {
                                path[i].occupied = true;
                                path[i].concatnate = true;
                        }
                        /* 最后一个虽然有, 但是不与下一个数相连 */
                        path[v.back()].occupied = true;
                }


                vector<vector<int>> ans;

                int start = -1;
                for (int i = 0; i < LEN_P; i++) {
                        /* 发现头 */
                        if (path[i].occupied && start == -1) {
                                start = i;
                        }
                        /* 有数字, 但是已经断开 */
                        if (path[i].occupied && !path[i].concatnate) {
                                ans.push_back({start, i});
                                start = -1;
                        }
                }

                return ans;
        }
};
