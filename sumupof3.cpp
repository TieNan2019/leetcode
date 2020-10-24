#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


class Solution {
public:
        int threeSumClosest(std::vector<int>& nums, int target) {
                int Sum;

                unsigned int Err = (unsigned int)-1;
                int TmpErr;

                std::sort(nums.begin(), nums.end());
                int Res = nums[0] + nums[1] + nums[2];

                for (int f = 0; f < nums.size() - 2; f++) {
                        int b = f + 1, e = nums.size() - 1;

                        while (b != e) {
                                // 求和
                                Sum = nums[f] + nums[b] + nums[e];
                                TmpErr = target - Sum;

                                std::cout << "Get " << TmpErr << " : " << nums[f] << ", " << nums[b] << ", " << nums[e] << std::endl;


                                //
                                if (abs(TmpErr) < Err) {
                                        Res = Sum;
                                        Err = abs(TmpErr);
                                }

                                if (TmpErr > 0)
                                        b++;
                                else
                                        e--;
                        }
                }

                return Res;
        }
};



int main(void)
{
        // std::vector<int> nums = {-3, 0, 1, 2};
        std::vector<int> nums = {0, 2, 1, -3};
        int target = 1;

        Solution s;

        std::cout << s.threeSumClosest(nums, target) << std::endl;

        return 0;
}
