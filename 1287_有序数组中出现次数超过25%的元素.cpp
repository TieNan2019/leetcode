class Solution {
public:
        int findSpecialInteger(vector<int>& arr) {
                int len = arr.size();

                int ans = 0;
                int head = arr.front();
                ans = count(arr.begin(), arr.end(), head);
                if (ans * 4 > len)
                        return head;


                int firstQuart = arr[len / 4];
                ans = count(arr.begin(), arr.end(), firstQuart);
                if (ans * 4 > len)
                        return firstQuart;

                int mid = arr[len / 2];
                ans = count(arr.begin(), arr.end(), mid);
                if (ans * 4 > len)
                        return mid;

                int thirdQuart = arr[len / 4 * 3];
                ans = count(arr.begin(), arr.end(), thirdQuart);
                if (ans * 4 > len)
                        return thirdQuart;

                return arr.back();
        }
};
