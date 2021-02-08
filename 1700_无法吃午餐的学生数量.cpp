class Solution {
public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
                vector<int> counter(2);

                for (const auto &x : students)
                        counter[x]++;

                int top = 0;
                while (top < sandwiches.size()) {
                        if (counter[sandwiches[top]] > 0) {
                                counter[sandwiches[top]]--;
                                top++;
                        }
                        else {
                                return counter[1] + counter[0];
                        }
                }

                return counter[1] + counter[0];
        }
};
