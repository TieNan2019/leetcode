class Solution {
public:
        int subtractProductAndSum(int n) {
                string s = to_string(n);

                int multi = accumulate(s.begin(), s.end(), 1, [](int a, int b){
                        return a * (b - '0');
                });

                int addon = accumulate(s.begin(), s.end(), 0, [](int a, int b) {
                        return b + a - '0';
                });

                return multi - addon;
        }
};
