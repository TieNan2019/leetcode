class Solution {
public:
        int recursion(string cur, int left, int right, vector<string> & ans) {
                if (left == 0) {
                        /* 左括号用尽时, 直接补满右括号即可 */
                        cur += string(right, ')');
                        ans.push_back(cur);

                        return 0;
                }

                /* 尝试在下一位置添加一个左括号 */
                string leftHalf = cur + '(';
                recursion(leftHalf, left-1, right, ans);

                /* 不允许出现的右括号的次数比左括号还多 */
                if (right - 1 >= left) {
                        /* 尝试在下一个位置添加一个右括号 */
                        string rightHalf = cur + ')';
                        recursion(rightHalf, left, right - 1, ans);
                }

                return 0;
        }


        vector<string> generateParenthesis(int n) {
                vector<string> ans;

                int left = n, right = n;
                recursion("", left, right, ans);

                return ans;
        }
};
