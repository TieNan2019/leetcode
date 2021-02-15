class Solution {
public:
        string convert(string s, int numRows) {
                if (numRows == 1)
                        return s;

                string ans(s.size(), 0);

                int p = 0;
                for(int base = 0; base < numRows; base++) {
                        int lp = 0;
                        int index = base;

                        while(index < s.size()) {
                                ans[p] = s[index];

                                lp++;
                                p++;

                                if (base == 0 || base == numRows - 1)
                                        index += 2 * (numRows - 1);
                                else {
                                        if (lp % 2 == 0) {
                                                index += base * 2;
                                        }
                                        else {
                                                index += (numRows - 1 - base) * 2;
                                        }
                                }
                        }
                }

                return ans;
        }
};
