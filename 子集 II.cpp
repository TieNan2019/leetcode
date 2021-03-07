class Solution {
public:
        void recursion(int *seq, int len, map<int, int>::iterator it, 
        const map<int, int>::iterator end, vector<vector<int>> &ans) {
                if (it == end) {
                        ans.emplace_back(seq, seq + len);
                        return ;
                }


                /* 先一次性填入元素 */
                for (int i = 0; i < it->second; i++)
                        seq[len + i] = it->first;
                

                auto next = it;
                next++;
                /* 务必要按照从多到少的顺序填入数据, 否则每次都需要重写缓冲区 */
                for (int k = it->second; k >= 0; k--) {
                        recursion(seq, len + k, next, end, ans);
                }
        }

        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
                /* 先对元素计数就可以很容易解决去重排列的问题 */
                map<int, int> counter;
                for (int &x : nums)
                        counter[x]++;
                
                int *seq = new int[nums.size()+1];
                vector<vector<int>> ans;

                recursion(seq, 0, counter.begin(), counter.end(), ans);

                delete[] seq;
                return ans;
        }
};
