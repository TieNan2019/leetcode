class Solution {
public:
        /* 从中心开始，按照一个从小到大的菱形的顺序向外输出，即可满足题意，也不会引入额外的运算储存资源 */
        vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
                vector<vector<int>> res({{r0, c0}});

                /* 为了顺利便利到边缘，求取上界 ———— 即曼哈顿距离在棋盘中的最大值 */
                int limit = 0;
                /* 取出原点到四个边界点之间的距离 */
                vector<int> rAlter = {r0+c0, C-c0+R-2, R-1-r0+c0, R+C-r0-c0-2};

                /* 距离中最大的一个作为上界 */
                for (int x : rAlter)
                        limit = max(limit, x);


                /* 按照距离从小到达的顺序便利周围的点 ———— 初始化时就已即把原点加入类结果，所以 r 从 1 开始遍历即可 */
                for (int r = 1; r <= limit; r++) {

                        /* 中心点的右下侧边 */
                        for (int i = 0; i < r; i++) {
                                int j = r - i;
                                // cout << r0 + i << ", " << c0 + j << endl;

                                if (c0 + j < C && c0 + j >= 0 && r0 + i < R && r0 + i >= 0)
                                        res.push_back({r0+i, c0+j});
                        }

                        /* 中心点的左下侧边 */
                        for (int i = 1; i <= r; i++) {
                                int j = r - i;
                                // cout << r0+i << ", " << c0 - j << endl;

                                if (c0 - j < C && c0 - j >= 0 && r0 + i < R && r0 + i >= 0)
                                        res.push_back({r0+i, c0-j});
                        }

                        /* 中心点的左上侧边 */
                        for (int i = 0; i < r; i++) {
                                int j = r - i;
                                // cout << r0 - i << ", " << c0 - j << endl;

                                if (c0 - j < C && c0 - j >= 0 && r0 - i < R && r0 - i >= 0)
                                        res.push_back({r0-i, c0-j});
                        }

                        /* 中心点的右上侧边 */
                        for (int i = 1; i <= r; i++) {
                                int j = r - i;
                                // cout << r0 - i << ", " << c0 + j << endl;

                                if (c0 + j < C && c0 + j >= 0 && r0 - i < R && r0 - i >= 0)
                                        res.push_back({r0-i, c0+j});
                        }
                        
                }


                return res;
        }
};
