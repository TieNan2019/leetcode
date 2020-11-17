/* 双指针法，不能处理存在负数的情况 */
class Solution {
public:
        int pivotIndex(vector<int>& nums) {
                if (nums.empty())
                        return -1;

                int head = 0, tail = nums.size();
                int sum = nums.front();
                while (head < tail) {
                        if (sum < 0) {
                                head++;
                                sum += nums[head];
                                // cout << "Head : " << head << " : " << sum << endl;
                        }
                        else {
                                tail--;
                                sum -= nums[tail];
                                // cout << "Tail : " << tail << " : " << sum << endl;
                        }
                }

                return sum ? -1 : tail;
        }
};
