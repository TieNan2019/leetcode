class Solution {
public:
        map<string, map<string, int>> rec;
        int recursion(string ring, string key) {
                if (key.empty())
                        return 0;

                int level = key.size();

                if (rec[ring][key] == 0) {
                        char p = ring.front();
                        int i = 0;
                        /* 右旋 */
                        /* 要按下按键，所以至少有一步 */
                        int toRight = 1;
                        while (p != key.front()) {
                                i++;

                                if (i == ring.size()) {
                                        toRight = INT_MAX;
                                        break;
                                }

                                p = ring[i];
                                toRight++;
                        }

                        int j = ring.size() - 1;
                        p = ring.back();
                        /* 要提前往左走一个，还要按下按键，所以是两步 */
                        int toLeft = 2;
                        while (p != key.front()) {
                                j--;
                                if (j < 0) {
                                        toLeft = INT_MAX;
                                        break;
                                }

                                p = ring[j];
                                toLeft++;
                        }

                        int leftRes = INT_MAX, rightRes = INT_MAX;
                        if (toLeft != INT_MAX) {
                                /* 向左转的情况 */
                                /* 更新轮子的状态 */
                                string newRing = ring.substr(j) + ring.substr(0, j);

                                leftRes = toLeft + recursion(newRing, key.substr(1));
                        }

                        
                        if (toRight != INT_MAX) {
                                /* 向右转的情况 */
                                string newRing = ring.substr(i) + ring.substr(0, i);

                                rightRes = toRight + recursion(newRing, key.substr(1));
                        }

                        rec[ring][key] = leftRes < rightRes ? leftRes : rightRes;
                }

                return rec[ring][key];
        }

        int findRotateSteps(string ring, string key) {

                return recursion(ring, key);
        }
};
