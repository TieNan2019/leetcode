class Solution {
public:
        int numTrees(int n) {
                if (n == 0 || n == 1)
                        return 1;
                
                if (n == 2)
                        return 2;

                int count = 0;
                int sum = 0;

                for (int i = 0; i < n; i++) {
                        int leftSize = i;
                        int rightSize = n - i - 1;
                        // cout << leftSize << " " << rightSize << endl;

                        /* 当根点确定,树的可能构成的个数为 左子树的所有可能性 x 右子树的所有可能性 */
                        sum += numTrees(leftSize) * numTrees(rightSize);
                }

                return sum;
        }
};
