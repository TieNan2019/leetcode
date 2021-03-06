class Solution {
public:
        vector<int> countBits(int num) {
                vector<int> ans{0};

                if (num <= 0)
                        return ans;

                ans.resize(num+1);
                ans[1] = 1;

                for (int i = 2; i <= num; i++)
                        /* 在分析 n & (n - 1) 的计位程序中获得灵感 */
                        ans[i] = ans[i & (i - 1)] + 1;

                return ans;
        }
};
