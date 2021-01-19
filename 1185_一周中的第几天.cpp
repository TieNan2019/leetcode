/* 出自 DoDo敲可爱 的答案 */
/* 原问题地址 : https://www.zhihu.com/question/320212466/answer/1669412498 */

class Solution {
public:
        string dayOfTheWeek(int day, int month, int year) {
                vector<string> W {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

                int q = day;
                int m = month;
                int y = year;

                if (m == 1 || m == 2) {
                        m += 12;
                        y--;
                }

                int j = y / 100;
                int k = y % 100;

                int h = (q + 26 * (m + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
                if (h == 0)
			h = 6;
		else if (h == 1)
			h = 7;
		else
			h -= 1;

                return W[h];
        }
};
