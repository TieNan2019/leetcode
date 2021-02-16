class Solution {
public:
        string add(const string &num1, const string &num2) {
                int maxLen = max(num1.size(), num2.size()) + 1;

                string a = string(maxLen - num1.size(), '0') + num1;
                string b = string(maxLen - num2.size(), '0') + num2;

                int upper = 0;
                for (int i = a.size() - 1; i > 0; i--) {
                        int x = a[i] - '0';
                        int y = b[i] - '0';

                        int res = x + y + upper;

                        upper = res / 10 > 0;
                        a[i] = res % 10 + '0';
                }

                if (upper)
                        a.front() = '1';
                else
                        a = a.substr(1);

                return a;
        }

        string multi(const string &num1, char num2, int zeros) {
                string m = "0";

                int k = num2 - '0';


                for (int i = 0; i < num1.size(); i++) {
                        int f = num1[num1.size() - 1 - i] - '0';
                        m = add(m, to_string(f * k) + string(i, '0'));
                }

                return m + string(zeros, '0');
        }

        
        string multiply(string num1, string num2) {
                if (num1 == "0" || num2 == "0")
                        return "0";

                string ans;                
                for (int i = 0; i < num2.size(); i++) {
                        ans = add(ans, multi(num1, num2[num2.size() - 1 - i], i));
                }

                return ans;
        }
};
