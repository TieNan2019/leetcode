class Solution {
public:
        int balancedStringSplit(string s) {
                int cnt = 0;

                int pv = 0;

                for (char ch : s) {
                        switch(ch) {
                                case 'R':
                                        pv--;
                                        if (pv == 0)
                                                cnt++;
                                        break;
                                case 'L':
                                        pv++;
                                        if (pv == 0)
                                                cnt++;
                                        break;
                                default:
                                        break;
                        }
                }

                return cnt;
        }
};
