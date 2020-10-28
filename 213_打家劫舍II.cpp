class Solution {
public:
        map<bool, map<int, int>> m;
        int recursion(const vector<int> nums, 
        int index = 0, bool head = false) {
                // 超出范围
                if (index >= nums.size())
                        return 0;

                // 头节点已经被占用，且到达末尾节点
                if (index == nums.size() - 1 && head)
                        return 0;
                
                if (index == nums.size() - 1 && !head)
                        return nums[index];


                // int steal = nums[index] + recursion(nums, index+2, head);
                int steal = nums[index];
                if (m[head].find(index+2) == m[head].end()) {
                        int r = recursion(nums, index+2, head);
                        m[head][index+2] = r;
                        steal += r;
                }
                else {
                        steal += m[head][index + 2];
                }



                // int keep = recursion(nums, index+1, head);
                int keep = 0;
                if (m[head].find(index+1) == m[head].end()) {
                        int k = recursion(nums, index+1, head);
                        m[head][index+1] = k;
                        keep = k;
                }
                        keep = m[head][index+1];


                return steal > keep ? steal : keep;
        }


        int rob(vector<int>& nums) {
                m[true][0] = nums.front();
                int head = nums.front() + recursion(nums, 2, true);
                int noHead = recursion(nums, 1, false);
                // cout << head << endl;
                // cout << noHead << endl;

                return head > noHead ? head : noHead;
        }
};
