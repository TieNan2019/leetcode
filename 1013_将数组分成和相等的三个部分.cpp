class Solution {
public:
        bool canThreePartsEqualSum(vector<int>& arr) {
                int left;

                int total = accumulate(arr.begin(), arr.end(), 0);

                int target = 0;
                int dTarget = total;
                for (left = 0; left < arr.size(); left++) {
                        target += arr[left];
                        dTarget -= arr[left];

                        if (target * 2 == dTarget)
                                break;
                }

                if (target * 2 != dTarget)
                        return false;
                // cout << target << " : " << dTarget << endl;

                int right;
                int midPart = 0;
                int rightPart = dTarget;
                for (right = left + 1; right < arr.size() - 1; right++) {
                        midPart += arr[right];
                        rightPart -= arr[right];

                        if (rightPart == midPart) {
                                // cout << right << " : " << midPart << " : " << rightPart << endl;
                                return true;
                        }
                }

                return false;
        }
};
