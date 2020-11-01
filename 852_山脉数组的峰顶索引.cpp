class Solution {
public:
        int peakIndexInMountainArray(vector<int>& arr) {
                int left = 1, right = arr.size() - 1;
                int mid;
                while (left <= right) {
                        mid = left + (right - left) / 2;
                        // cout << left << " " << mid << " " << right << endl;

                        if (arr[mid] > arr[mid-1]
                        && arr[mid] > arr[mid+1]) {
                                return mid;
                        }
                        else if (arr[mid] > arr[mid-1]
                        && arr[mid] < arr[mid+1]) {
                                left = mid + 1;
                        }
                        else if (arr[mid] < arr[mid-1]
                        && arr[mid] > arr[mid+1]) {
                                right = mid - 1;
                        }
                }

                return -1;
        }
};
