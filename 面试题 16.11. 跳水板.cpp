class Solution {
public:
        vector<int> divingBoard(int shorter, int longer, int k) {
                if (k == 0)
                        return {};
                if (shorter >= longer)
                        return {shorter * k};

                vector<int> ans(k + 1);

                for (int l = 0; l <= k; l++)
                        ans[l] = l * longer + (k - l) * shorter;

                return ans;
        }
};
