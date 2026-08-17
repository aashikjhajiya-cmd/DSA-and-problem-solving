class Solution {
public:
    void sortIntervals(vector<vector<int>>& points) {
        int n = points.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (points[j][1] > points[j + 1][1]) {
                    vector<int> temp = points[j];
                    points[j] = points[j + 1];
                    points[j + 1] = temp;
                }
            }
        }
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sortIntervals(points);
        int arrows = 1;
        int end = points[0][1];
        for (size_t i = 1; i < points.size(); i++) {
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            }
        }
        return arrows;
    }
};
