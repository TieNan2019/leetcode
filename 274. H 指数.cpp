class Solution {
public:
        int hIndex(vector<int>& citations) {
                /* key : 引用次数； value : 相应的论文数目 */
                map<int, int> cnt;

                for (int i = 0; i < citations.size(); i++)
                        cnt[citations[i]]++;
                

                int h = 0;
                for (auto i = cnt.rbegin()->first; i >= 0; i--){
                        cnt[i] += cnt[i+1];

                        if (cnt[i] >= i)
                                h = max(i, h);
                }

                return h;
        }
};
