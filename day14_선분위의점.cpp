#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countPointsOnSegments(const vector<int>& points, const vector<pair<int, int>>& segments) {
    vector<int> result;
    
    for (const auto& segment : segments) {
        int start = segment.first;
        int end = segment.second;

        auto left = lower_bound(points.begin(), points.end(), start);
        auto right = upper_bound(points.begin(), points.end(), end);
        result.push_back(right - left);
    }
    
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i];
    }
    
    vector<pair<int, int>> segments(m);
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        segments[i] = {start, end};
    }

    sort(points.begin(), points.end());

    vector<int> result = countPointsOnSegments(points, segments);

    for (int count : result) {
        cout << count << '\n';
    }
    
    return 0;
}
