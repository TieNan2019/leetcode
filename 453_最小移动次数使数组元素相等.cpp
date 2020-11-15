class Solution {
public:
        int minMoves(vector<int>& nums) {
                int minimum = *min_element(nums.begin(), nums.end());

                long sum = accumulate(nums.begin(), nums.end(), 0,
                [=](int a, int b) {
                        int delta = b - minimum;

                        return a + delta;
                });


                return sum;
        }
};
