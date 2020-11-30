class Solution {
public:
        bool isMonotonic(vector<int>& A) {
                int idx = 0;

                int sign = 0;
                while (idx < A.size() - 1) {
                        if (A[idx] - A[idx+1] > 0) {
                                sign = 1;
                                break;
                        }
                        else if (A[idx] - A[idx+1] < 0) {
                                sign = -1;
                                break;
                        }

                        idx++;
                }

                if (sign == 0)
                        return true;

                for (; idx < A.size() -1; idx++) {
                        if ((A[idx] - A[idx+1]) * sign < 0)
                                return false;
                }

                return true;
        }
};
