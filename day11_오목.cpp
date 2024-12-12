#include <iostream>
#include <vector>

using namespace std;

class Omog {
private:
    vector<vector<int>> checkerboard;
    int dx[4] = { 1, 0, 1, -1 }; // 가로, 세로, 대각선 2개
    int dy[4] = { 0, 1, 1, 1 };

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < 19 && y < 19;
    }

    bool checkFive(int stone, int x, int y, int dir) {
        int count = 1; 
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        while (isValid(nx, ny) && checkerboard[nx][ny] == stone) {
            count++;
            nx += dx[dir];
            ny += dy[dir];
        }

        nx = x - dx[dir];
        ny = y - dy[dir];
        while (isValid(nx, ny) && checkerboard[nx][ny] == stone) {
            count++;
            nx -= dx[dir];
            ny -= dy[dir];
        }

        if (count == 5) {
            // 이전 방향에 같은 돌이 있다면 무효
            int prevX = x - dx[dir];
            int prevY = y - dy[dir];
            if (isValid(prevX, prevY) && checkerboard[prevX][prevY] == stone) {
                return false;
            }
            return true;
        }

        return false;
    }

public:
    Omog() : checkerboard(19, vector<int>(19, 0)) {}

    void input() {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                cin >> checkerboard[i][j];
            }
        }
    }

    void solve() {
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < 19; j++) {
                if (checkerboard[i][j] == 1 || checkerboard[i][j] == 2) {
                    int stone = checkerboard[i][j];
                    for (int dir = 0; dir < 4; dir++) {
                        if (checkFive(stone, i, j, dir)) {
                            cout << stone << endl;
                            cout << i + 1 << " " << j + 1 << endl;
                            return;
                        }
                    }
                }
            }
        }
        cout << 0 << endl;
    }
};

int main() {
    Omog omog;
    omog.input();
    omog.solve();
    return 0;
}
