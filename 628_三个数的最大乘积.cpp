class Solution {
public:
        int maximumProduct(vector<int>& nums) {
                sort(nums.begin(), nums.end());
                int res1 = nums.back() * *(nums.end() - 2) * *(nums.end() - 3);
                int res2 = nums.back() * -nums[0] * -nums[1];


                return max(res1, res2);
        }
};
