class Solution {
public:
        bool validMountainArray(vector<int>& A) {
                if(A.size() < 3)
                        return false;
                if (A[0] - A[1] >= 0)
                        return false;

                bool upHill = true;

                for (int i = 1; i < A.size(); i++) {
                        int delta = A[i] - A[i-1];

                        if (delta == 0)
                                return false;

                        if (upHill && delta < 0)
                                upHill = false;
                        
                        if (!upHill && delta > 0)
                                return false;
                }

                return !upHill;
        }
};
