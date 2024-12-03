#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 섬을 탐색하는 클래스
class Island {
public:
    int w, h;
    vector<vector<int>> map;

    // 입력을 받는 함수
    bool input() {
        cin >> w >> h;
        if (w == 0 && h == 0) return false; 
        map.resize(h, vector<int>(w)); 
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }
        return true;
    }

    // 섬의 개수를 세는 함수
    int countIslands() {
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int islandCount = 0;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (map[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j, visited);
                    islandCount++;
                }
            }
        }

        return islandCount;
    }

private:
    int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
    int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

    void bfs(int startY, int startX, vector<vector<bool>>& visited) {
        queue<pair<int, int>> q;
        q.push({ startY, startX });
        visited[startY][startX] = true;

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 8; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny >= 0 && ny < h && nx >= 0 && nx < w && map[ny][nx] == 1 && !visited[ny][nx]) {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                }
            }
        }
    }
};

int main() {
    while (true) {
        Island island;
        if (!island.input()) break; 
        cout << island.countIslands() << endl;
    }
    return 0;
}
