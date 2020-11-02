class Solution {
public:
        int dp(int n) {
                vector<int> paths(n + 1 > 4 ? n + 1 : 4);

                paths[0] = 0;
                paths[1] = 1;
                paths[2] = 2;
                paths[3] = 4;

                if (n < 4)
                        return paths[n];

                for (int i = 4; i <= n; i++)
                        paths[i] = ((long)paths[i - 1] + paths[i - 2] + paths[i - 3]) % 1000000007;

                return paths.back();
        }

        int waysToStep(int n) {
                return dp(n);
        }
};
