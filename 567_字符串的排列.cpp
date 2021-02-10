class Solution {
public:
        bool checkInclusion(string s1, string s2) {
                int counter[26] {0};

                for (auto ch : s1)
                        counter[ch - 'a']++;
                
                for (int i = 0; i < s2.size(); i++) {
                        if (counter[s2[i] - 'a'] > 0) {
                                int cnt[26];
                                memcpy(cnt, counter, sizeof(int) * 26);

                                int j;
                                for (j = 0; j < s1.size(); j++) {
                                        if (j + i >= s2.size())
                                                return false;

                                        cnt[s2[j + i] - 'a']--;
                                        if (cnt[s2[j + i] - 'a'] < 0)
                                                break;
                                }
                                if (j == s1.size())
                                        return true;
                        }
                }

                return false;
        }
};
