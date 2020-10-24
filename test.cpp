#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> input(void) {
        int rows;
        cin >> rows;

        vector<vector<int>> points(rows, vector<int>(4));

        for (int i = 0; i < rows; i++) {
                cin >> points[i][1] >> points[i][2];
                points[i][0] = points[i][1] + points[i][2];
                points[i][3] = i;
        }


        return points;
}

int output(vector<vector<int>> v)
{
        sort(v.begin(), v.end(),
        [](vector<int> a, vector<int> b) {
                return a[1] < b[1];
        });

        for (auto x : v) {
                cout << x[1] << " " << x[2] << endl;
        }
        return 0;
}


int main(void)
{
        vector<vector<int>> points = input();


        sort(points.begin(), points.end(),
        [](const vector<int> &a, const vector<int> &b){
                return a[0] > b[0];
        });

        int i;
        for (i = 1; i < points.size(); i++) {
                for (int j = 0; j < i; j++) {
                        if (points[j][1] - points[i][1] > 0
                        && points[j][2] - points[i][2] > 0) {

                                vector<vector<int>> tmp(points.begin(), points.begin()+i);
                                output(tmp);
                                return 0;
                        }
                }
        }

        return 0;
}
