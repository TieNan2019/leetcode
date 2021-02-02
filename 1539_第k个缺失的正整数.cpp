class Solution {
public:
        int findKthPositive(vector<int>& arr, int k) {
                int key = 0;

                int i = 0;

                int hits = 1;
                while (hits <= k) {
                        key++;

                        if (i < arr.size() && arr[i] == key)
                                i++;
                        else
                                hits++;
                }

                return key;
        }
};
