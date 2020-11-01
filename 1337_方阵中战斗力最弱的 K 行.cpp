class Solution {
public:
        int cnt(vector<int> v)
        {
                int left = 0, right = v.size();
                int mid;

                while (left < right) {
                        mid = left + (right - left) / 2;

                        if (v[mid] == 0) {
                                right = mid;
                        }
                        else if (v[mid] == 1) {
                                left = mid + 1;
                        }

                }

                return left;
        }
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k)
        {
                vector<vector<int>> seq(mat.size(), vector<int>(2, 0));

                for (int i = 0; i < mat.size(); i++)
                        seq[i] = {i, cnt(mat[i])};


                sort(seq.begin(), seq.end(),
                [](const vector<int> &a, const vector<int> &b) {
                        if (a[1] == b[1])
                                return a[0] < b[0];
                        return a[1] < b[1];     
                });

                // for (auto v : seq)
                        // cout << v[0] << " --- " << v[1] << endl;

                vector<int> res(k);
                for (int i = 0; i < k; i++) {
                        res[i] = seq[i][0];
                }

                return res;
        }
};
