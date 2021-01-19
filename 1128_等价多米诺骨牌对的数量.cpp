class Solution {
public:
        int numEquivDominoPairs(vector<vector<int>>& dominoes) {
                map<vector<int>, int> counter;

                int res = 0;
                for (auto &v : dominoes) {
                        if (v[0] > v[1]) {
                                int tmp = v[0];
                                v[0] = v[1];
                                v[1] = tmp;
                        }

                        res += counter[v]++;
                }

                return res;
        }
};
