class Solution {
public:

        int maxArea(vector<int>& height) {
                int left = 0, right = height.size() - 1;
                int maximum = (right - left) * min(height[left], height[right]);

                int l = left, r = right;
                while (left < right) {

                        while (height[l] <= height[left] && l < right)
                                l++;
                        while (height[r] <= height[right] && r > left)
                                r--;
                        
                        int leftVol = (right - l) * min(height[l], height[right]);
                        int rightVol = (r - left) * min(height[left], height[r]);
                        int midVol = (r - l) * min(height[l], height[r]);

                        if (leftVol > rightVol && leftVol > midVol && leftVol > maximum) {
                                left = l;
                                maximum = leftVol;
                        }
                        else if (rightVol > leftVol && rightVol > midVol && rightVol > maximum) {
                                right = r;
                                maximum = rightVol;
                        }
                        else {
                                left = l;
                                right = r;
                                
                                if (midVol > leftVol && midVol > rightVol && midVol > maximum) {
                                        maximum = midVol;
                                }
                        }
                }

                return maximum;
        }
};
