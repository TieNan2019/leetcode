class Solution {
public:
        double findMaxAverage(vector<int>& nums, int k) {
                vector<double> dnums(nums.size());
                transform(nums.begin(), nums.end(),
                dnums.begin(), [=](int b) {
                        return b / (double)k;
                });

                double average = 0.0;
                for (int i = 0; i < k; i++)
                        average += dnums[i];

                k--;
                double ave = average;
                for (int i = 1; i + k < dnums.size(); i++) {
                        // 此处犯过一个错误
                        // 每次滑动窗口的值都是由 ave 的旧值来进行更新，
                        // 而 average 记录着之前用来更新的最大值，并不符合两步之间的递推关系
                        // 所以要对 ave 进行更新，切记！！！
                        ave = ave - dnums[i-1] + dnums[i+k];
                        average = average > ave ? average : ave;
                        // cout << dnums[i] << " : " << average << endl;
                }

                return average;
        }
};
