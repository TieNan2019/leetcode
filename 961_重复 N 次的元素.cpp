class Solution {
public:
        int repeatedNTimes(vector<int>& A) {
                map<int, int> counter;

                for (const auto &x : A) {
                        /* 2N 个元素中，有一个元素出现 N-1 次，因次只要有个元素曾经出现过，即已经找到了该元素 */
                        if (counter.find(x) != counter.end())
                                return x;
                        counter[x]++;
                }
                return -1;
        }
};
