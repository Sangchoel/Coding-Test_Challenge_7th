#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class RouteNavigation {
private:
    int width, height, storeCount;
    vector<vector<int>> map;
    vector<pair<int, int>> stores;
    pair<int, int> guard;

    pair<int, int> to2DCoord(int dir, int dist) {
        if (dir == 1) return {0, dist};
        if (dir == 2) return {height, dist};
        if (dir == 3) return {dist, 0};
        if (dir == 4) return {dist, width};
        return {0, 0};
    }

    int calculateDistance(pair<int, int> a, pair<int, int> b) {
        int perimeter = 2 * (width + height);
        int linearA = toLinearCoord(a);
        int linearB = toLinearCoord(b);
        int clockwiseDist = abs(linearA - linearB);
        int counterClockwiseDist = perimeter - clockwiseDist;
        return min(clockwiseDist, counterClockwiseDist);
    }

    int toLinearCoord(pair<int, int> coord) {
        if (coord.first == 0) return coord.second;
        if (coord.first == height) return width + height + (width - coord.second);
        if (coord.second == 0) return width + height + width + (height - coord.first);
        if (coord.second == width) return width + coord.first;
        return 0;
    }

public:
    void input() {
        cin >> width >> height;
        map.resize(height + 1, vector<int>(width + 1, 0));

        cin >> storeCount;
        for (int i = 0; i < storeCount; ++i) {
            int dir, dist;
            cin >> dir >> dist;
            stores.push_back(to2DCoord(dir, dist));
        }

        int guardDir, guardDist;
        cin >> guardDir >> guardDist;
        guard = to2DCoord(guardDir, guardDist);
    }

    void calculateShortestDistance() {
        int totalDistance = 0;

        for (const auto& store : stores) {
            totalDistance += calculateDistance(guard, store);
        }

        cout << totalDistance << endl;
    }
};

int main() {
    RouteNavigation navigation;
    navigation.input();
    navigation.calculateShortestDistance();
    return 0;
}
