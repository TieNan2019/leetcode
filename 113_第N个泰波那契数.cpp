class Solution {
public:
        int tribonacci(int n) {
                switch(n) {
                        case 0:
                                return 0;
                                break;
                        case 1: case 2:
                                return 1;
                                break;
                        default:
                                break;
                }

                vector<int> seq(n + 1, 0);
                seq[0] = 0, seq[1] = 1, seq[2] = 1;

                for (int i = 3; i <= n; i++)
                        seq[i] = seq[i-1] + seq[i-2] + seq[i-3];

                return seq.back();
        }
};
