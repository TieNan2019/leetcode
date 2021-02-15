class Solution {
public:
        int myAtoi(string s) {
                long ans = 0;
                int sign = 1;

                bool effectiveSign = true;
                for (char ch : s) {
                        switch(ch) {
                                case ' ':
                                        if (!effectiveSign)
                                                return sign * ans;
                                        break;
                                case '+':
                                        if (effectiveSign)
                                                effectiveSign = false;
                                        else
                                                return sign * ans;
                                        break;
                                case '-':
                                        if (effectiveSign) {
                                                sign = -1;
                                                effectiveSign = false;
                                        }
                                        else {
                                                return sign * ans;
                                        }
                                        break;
                                default:
                                        if (isdigit(ch)) {
                                                effectiveSign = false;
                                                ans = ans * 10 + ch - '0';
                                                
                                                if (ans * sign > INT_MAX)
                                                        return INT_MAX;
                                                else if (ans * sign < INT_MIN)
                                                        return INT_MIN;
                                        }
                                        else {
                                                return sign * ans;
                                        }
                        }
                }

                return ans * sign;

        }
};
