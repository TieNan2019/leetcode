class Solution {
public:
        int countBinarySubstrings(string s) {
                int count = 0;

                for (int h = 0; h < s.size(); h++) {
                        int balance = 0;

                        switch(s[h]) {
                                case '0': balance++; break;
                                case '1': balance--; break;
                                default: break;
                        }

                        for (int t = h + 1; t < s.size(); t++) {
                                switch(s[t]) {
                                        case '0': balance++; break;
                                        case '1': balance--; break;
                                        default: break;
                                }

                                if (balance == 0) {
                                        // cout << balance << " : " << s.substr(h, t+1) << endl;
                                        count++;
                                }
                        }
                }

                return count;
        }
};
