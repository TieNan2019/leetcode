class Solution {
public:
        bool isBackward(int begin, int end, const char *s) {
                end--;
                while (begin < end) {
                        if (s[begin] != s[end])
                                return false;
                        
                        begin++, end--;
                }

                return true;
        }

        void split(int *slices, int len, const char *s, const int sLen, vector<vector<string>> &ans) {
                if(slices[len - 1] == sLen) {
                        vector<string> item;

                        for (int i = 0; i < len - 1; i++)
                                item.emplace_back(s + slices[i], s + slices[i+1]);
                        ans.push_back(item);

                        return ;
                }

                for (int end = slices[len-1] + 1; end <= sLen; end++) {
                        if (isBackward(slices[len-1], end, s)) {
                                slices[len] = end;
                                split(slices, len + 1, s, sLen, ans);
                        }
                }
        }

        vector<vector<string>> partition(string s) {
                vector<vector<string>> ans;
                int *slices = new int[s.size() + 1];
                slices[0] = 0;

                const char *str = s.c_str();

                split(slices, 1, str, s.size(), ans);

                delete[] slices;
                return ans;
        }
};
