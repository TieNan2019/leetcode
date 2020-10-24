#include <iostream>
#include <vector>
#include <algorithm>


class Solution {
public:
        std::vector<int> twoSum(std::vector<int>& nums, int target) {
                int head = 0;
                int tail = nums.size() - 1;
                int Sum;

                // 取最大值
                int Err = ((unsigned int)-1)/2 + 1;

                std::vector<int> Nums(nums.begin(), nums.end());


                std::sort(Nums.begin(), Nums.end());

                while (head != tail) {
                        Sum = Nums[head] + Nums[tail];

                        Err = Sum - target;

                        std::cout << target << " " << Sum << " " << Nums[head] << " " << Nums[tail] << std::endl;

                        if (Err == 0) {
                                int a = 0, b = nums.size() - 1;

                                while (nums[a] != Nums[head])
                                        a++;
                                while (nums[b] != Nums[tail])
                                        b--;

                                std::vector<int> Res = {a, b};
                                std::sort(Res.begin(), Res.end());

                                return Res;
                        }

                        if (Err > 0)
                                tail--;
                        else
                                head++;
                }

                return {0};
        }
};


int main(void)
{
        std::vector<int> nums = {3, 3};
        int target = 6;

        Solution s;
        std::vector <int> Res = s.twoSum(nums, target);

        std::cout << Res[0] << " " << Res[1] << std::endl;

        return 0;
}
