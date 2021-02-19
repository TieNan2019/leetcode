class Solution {
public:
        void nextPermutation(vector<int>& nums) {

                int head = nums.size() - 2;
                while (head >= 0 && nums[head] >= nums[head + 1])
                        head--;

                if (head < 0) {
                        reverse(nums.begin(), nums.end());
                        return ;
                }


                int index = head;
                int minLarger = INT_MAX;

                for (int i = head + 1; i < nums.size(); i++)
                        if (minLarger > nums[i] && nums[i] > nums[head]) {
                                index = i;
                                minLarger = nums[i];
                        }
                int shift = index - head;


                auto start = nums.begin() + head;
                auto end = nums.end();
                vector<int> tmp(start, start + shift);

                copy(start + shift, end, start);
                copy(tmp.begin(), tmp.end(), start + distance(start + shift, end));

        }
};
