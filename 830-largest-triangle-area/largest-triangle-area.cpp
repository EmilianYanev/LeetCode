class Solution {
public:
    double shoelaceFormula(const vector<int>& point1, const vector<int>& point2, const vector<int>& point3) {
        int x1 = point1[0];
        int x2 = point2[0];
        int x3 = point3[0];

        int y1 = point1[1];
        int y2 = point2[1];
        int y3 = point3[1];

        double area = 0;

        double downwardProducts = (x1 * y2) + (x2 * y3) + (x3 * y1);
        double upwardProducts = (y1 * x2) + (y2 * x3) + (y3 * x1);

        area = abs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) * 0.5;
        return area;
    }
    double largestTriangleArea(vector<vector<int>>& points) {
        int len1 = points.size() - 3;
        int len2 = len1 + 1;
        int len3 = len2 + 1;

        double biggest = -1;
        double current = 0;

        for(int i = 0; i <= len1; i++) {
            for(int j = i + 1; j <= len2; j++){
                for(int k = j + 1; k <= len3; k++){
                    current = shoelaceFormula(points[i], points[j], points[k]);
                    if(current > biggest) {
                        biggest = current;
                    }
                }
            }
        }

        return biggest;
    }
};