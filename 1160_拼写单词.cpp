class Solution {
public:
        int countCharacters(vector<string>& words, string chars) {
                int alphabet[124] = {0};

                for (char ch : chars)
                        ++alphabet[ch];

                int count[124];
                int ans = 0;
                for (const auto &w : words) {
                        memcpy(count, alphabet, 124 * sizeof(int));

                        bool jmp = false;
                        for (char ch : w) {
                                count[ch]--;

                                if (count[ch] < 0) {
                                        jmp = true;
                                        break;
                                }
                        }

                        if (!jmp)
                                ans += w.size();
                }

                return ans;
        }
};
