class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 1) {
            return triangle[0][0];
        }

        int len = triangle.size() - 2;
        for (size_t i = len; i != -1; i--) {
            for (size_t j = 0; j < triangle[i].size(); j++) {
                if (triangle[i + 1][j] > triangle[i + 1][j + 1]) {
                    triangle[i][j] += triangle[i + 1][j + 1];
                } else {
                    triangle[i][j] += triangle[i + 1][j];
                }
            }
        }

        return triangle[0][0];
    }
};