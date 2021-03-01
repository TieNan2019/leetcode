class Solution {
public:
        int removeDuplicates(vector<int>& nums) {
                int head = 1, tail = 1;
                int oldVal = nums.front(), cnt = 1;

                while (tail < nums.size()) {
                        if (nums[tail] == oldVal) {
                                if (cnt < 2) {
                                        nums[head] = nums[tail];
                                        head++;
                                        cnt++;
                                }
                        }
                        else {
                                nums[head] = nums[tail];
                                head++;
                                cnt = 1;
                                oldVal = nums[tail];
                        }

                        tail++;
                }

                return head;
        }
};
