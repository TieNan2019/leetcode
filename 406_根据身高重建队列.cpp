class Solution {
public:
        vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
        {
                vector<vector<int>> sorted(people.size(), vector<int>(2, INT_MAX));
                vector<bool> mask(people.size(), false);

                /* 首先按照 "高度" 和 "允许逆排值" 排序 */
                sort(people.begin(), people.end(),
                [](vector<int> & a, vector<int> &b)
                {
                        /* 高度较小的先处理 */
                        if (a[0] < b[0])
                                return false;
                        else if (a[0] > b[0])
                                return true;
                        /* 高度相等时，逆排值较小的 */
                        else if (a[1] < b[1])
                                return false;
                        else
                                return true;
                });


                /* 按照排序的结果进行插入, 如果先插入高度较的 */
                while (!people.empty()) {
                        vector<int> v = people.back();
                        people.pop_back();

                        // 满足大于该数字的要求
                        int offset = 0, cnt = 0;
                        
                        /* 首先，由于一个位置前必须插入比其大的值，为较大值空出位置 */
                        /* 凑够 v[1] 个较大值 */
                        for (offset = 0; offset < sorted.size(); offset++) {
                                if (cnt == v[1])
                                        break;
                                
                                if (v[0] <= sorted[offset][0])
                                        cnt++;
                        }
                        

                        /* 在满足前置最大值的排序后，向后找到第一个没有插入元素的位置 */
                        while (sorted[offset][0] < INT_MAX)
                                offset++;


                        /* 数据不符合条件 */
                        if (offset >= sorted.size())
                                break;

                        sorted[offset] = v;
                }
                
                return sorted;
        }
};
