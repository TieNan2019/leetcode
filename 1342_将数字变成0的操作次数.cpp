class Solution {
public:
        int numberOfSteps (int num) {
                int cnt = 0;

                while (num) {
                        switch(num & 1) {
                                case 0:
                                        num >>= 1;
                                        cnt++;
                                        break;
                                case 1:
                                        num--;
                                        cnt++;
                                        break;
                                default:
                                        break;
                        }
                }

                return cnt;
        }
};
