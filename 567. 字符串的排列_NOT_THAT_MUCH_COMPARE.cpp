class Solution {
public:
        bool checkInclusion(string s1, string s2) {
                if (s1.size() > s2.size())
                        return false;

                int counter[26] {0};

                for (char ch : s1)
                        counter[ch - 'a']++;
                
                int slideWin[26] {0};

                for (int i = 0; i < s1.size(); i++) {
                        slideWin[s2[i] - 'a']++;
                }
                if (!memcmp(slideWin, counter, sizeof(counter)))
                        return true;
                
                for (int i = 1; i + s1.size() <= s2.size(); i++) {
                        slideWin[s2[i-1] - 'a']--;
                        slideWin[s2[i+s1.size()-1] - 'a']++;

                        if (slideWin[s2[i+s1.size()-1] - 'a'] == counter[s2[i+s1.size()-1] - 'a']
                        && slideWin[s2[i-1] - 'a'] == counter[s2[i-1] - 'a']
                        && !memcmp(slideWin, counter, sizeof(counter)))
                                return true;
                }


                return false;
        }
};
