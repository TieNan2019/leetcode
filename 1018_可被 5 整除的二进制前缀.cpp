class Solution {
public:
        vector<bool> prefixesDivBy5(vector<int>& A) {

                vector<bool> ret(A.size(), false);

                if (A[0] == 0) {
                        ret[0] = true;
                        if (A.size() > 1 && A[1] == 0) {
                                ret[1] = true;

                                if (A.size() > 2 && A[2] == 0)
                                        ret[2] = true;
                        }
                }
                else if (A[0] == 1 && A[2] == 1 && A[1] == 0) {
                                ret[2] = true;
                }

                int last = (A[0] * 4 + A[1] * 2 + A[2]) % 10;

                for (int i = 3; i < A.size(); i++) {
                        switch(last) {
                                // 7 和 2 结尾 * 2 + 1 后可以得到 5
                                case 2: case 7:
                                        if (A[i] == 1)
                                                ret[i] = true;
                                        break;
                                // 0 和 5 结尾 * 2 + 0 后得五的倍数
                                case 0: case 5:
                                        if (A[i] == 0)
                                                ret[i] = true;
                                        break;
                                default:
                                        break;
                        }

                        last = (last * 2 + A[i]) % 10;
                }

                return ret;
        }
};
