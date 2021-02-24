class Solution {
public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
        {
                vector<vector<int>> ans;

                enum {
                        UNDONE,
                        MATCHING,
                        MATCHED
                } state;
                state = UNDONE;

                int front = -1, back = -1;
                for (int i = 0; i < intervals.size(); i++) {
                        if (state == UNDONE) {
                                if (newInterval.back() < intervals[i].front()) {
                                        ans.push_back(newInterval);
                                        ans.push_back(intervals[i]);
                                        state = MATCHED;
                                }
                                else if (newInterval.front() > intervals[i].back()) {
                                        ans.push_back(intervals[i]);
                                }
                                else {
                                        front = min(newInterval.front(), intervals[i].front());
                                        back = max(newInterval.back(), intervals[i].back());
                                        state = MATCHING;
                                }
                        }
                        else if (state == MATCHED) {
                                ans.push_back(intervals[i]);
                        }
                        else {
                                if (back < intervals[i].front()) {
                                        ans.push_back({front, back});
                                        ans.push_back(intervals[i]);

                                        state = MATCHED;
                                }
                                else {
                                        front = min(front, intervals[i].front());
                                        back = max(back, intervals[i].back());
                                }
                        }
                }

                if (state == MATCHING)
                        ans.push_back({front, back});
                else if (state == UNDONE)
                        ans.push_back(newInterval);


                return ans;
        }
};
