class Solution {
public:
        struct counter {
                char ch;
                int n;

                counter(char ch, int n): ch(ch), n(n) {}

	        bool operator <(const counter b) const{
		        return this->n < b.n;
	        }
        };

        bool cmp(const counter &a, const counter &b) {
                if (a.n < b.n)
                        return true;
                return false;
        }

        string reorganizeString(string S) {
                map<char, int> dict;

                for (char ch : S)
                        dict[ch]++;

                priority_queue <counter> que;

                for (auto it = dict.begin(); it != dict.end(); it++) {
                        que.push(counter(it->first, it->second));
                }

                string res;

                while (!que.empty()) {
                        counter a = que.top();
                        que.pop();

                        /* 可以填入 */
                        if (res.empty() || res.back() != a.ch) {
                                res = res + a.ch;

                                a.n--;
                        }
                        else if (que.empty()) {
                                return "";
                        }
                        /* 字母重复 */
                        else if (res.back() == a.ch) {
                                counter b = que.top();
                                que.pop();

                                res = res + b.ch;
                                b.n--;

                                if (b.n)
                                        que.emplace(b);
                        }
                        if (a.n)
                                que.emplace(a);
                }

                return res;       
        }
};
