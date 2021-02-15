class Solution {
public:
        int recursion(const char **dict, const string &digits, char *str, int len, vector<string> &ans) {
                if (len == digits.size()) {
                        ans.push_back(str);
                        return 0;
                }

                int n = strlen(dict[digits[len]]);

                // int n = 10;
                for (int i = 0; i < n; i++) {
                        str[len] = dict[digits[len]][i];
                        recursion(dict, digits, str, len + 1, ans);
                }

                str[len] = '\0';

                return 0;

        }
        vector<string> letterCombinations(string digits) {
                if (digits.empty())
                        return {};

                const char *dict[] = {
                        ['0'] = "",
                        ['1'] = "",
                        ['2'] = "abc",
                        ['3'] = "def",
                        ['4'] = "ghi",
                        ['5'] = "jkl",
                        ['6'] = "mno",
                        ['7'] = "pqrs",
                        ['8'] = "tuv",
                        ['9'] = "wxyz"
                };

                char *str = new char[digits.size() + 1];
                memset(str, 0, digits.size() + 1);
                vector<string> ans;
                recursion(dict, digits, str, 0, ans);

                delete[] str;

                return ans;
        }
};
