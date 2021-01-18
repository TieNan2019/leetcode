class Solution {
public:
        vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {

                int evenSum = 0;
                for (int i = 0; i < A.size(); i++)
                        if (A[i] % 2 == 0) {
                                evenSum += A[i];
                        }
                

                vector<int> seq(A.size(), evenSum);


                for (int i = 0; i < queries.size(); i++) { 
                        const int &val = queries[i][0];
                        const int &index = queries[i][1];

                        if (A[index] % 2 == 0)
                                evenSum -= A[index];
                        
                        int tmp = A[index] + val;
                        A[index] += val;

                        if (tmp % 2 == 0)
                                evenSum += A[index];

                        seq[i] = evenSum;
                }

                return seq;
        }
};
