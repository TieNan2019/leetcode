class Solution {
public:
        vector<vector<int>> findContinuousSequence(int target) {
                vector<vector<int>> ans;

                for (int y = 1; y * 2 <= target; y++) {
                        long delta = 1 - 4 * (y - (long)y * y - 2 * target);

                        if (delta >= 0) {
                                int x = (sqrt(delta) - 1) / 2;

                                if ((x + y) * (x - y + 1) == target * 2) {

                                        vector<int> v(x - y + 1);
                                        for (int i = y; i <= x; i++) {
                                                v[i - y] = i;
                                        }

                                        ans.push_back(v);
                                }
                        }
                }

                return ans;
        }
};
