class Solution {
public:
        int target;
        int fill;
        int rows, cols;
        void recursion(vector<vector<int>>& image, int r, int c) {
                // cout << r << " " << c << endl;
                /* 上 */
                if (r - 1 >= 0 && image[r-1][c] == target && image[r-1][c] != fill) {
                        image[r-1][c] = fill;
                        recursion(image, r-1, c);
                }

                /* 下 */
                if (r + 1 < rows && image[r+1][c] == target && image[r+1][c] != fill) {
                        image[r+1][c] = fill;
                        recursion(image, r+1, c);
                }

                /* 左 */
                if (c - 1 >= 0 && image[r][c-1] == target && image[r][c-1] != fill) {
                        image[r][c-1] = fill;
                        recursion(image, r, c-1);
                }
                /* 右 */
                if (c + 1 < cols && image[r][c+1] == target && image[r][c+1] != fill) {
                        image[r][c+1] = fill;
                        recursion(image, r, c+1);
                }
        }

        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
                target = image[sr][sc];
                fill = newColor;

                rows = image.size();
                cols = image[0].size();

                image[sr][sc] = newColor;
                recursion(image, sr, sc);

                return image;
        }
};
