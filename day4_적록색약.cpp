#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class redgreen {
public:
    redgreen(int size) :
        N(size),
        rgb_map(size, vector<char>(size)),
        visited(size, vector<bool>(size, false)),
        nomal_count(0),
        color_blind_count(0) {}

    void input() {
        for (int i = 0; i < N; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < N; j++) {
                rgb_map[i][j] = row[j];
            }
        }
    }

    void solve() {
        // 일반인 구역 계산
        visited.assign(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bfs(i, j, true); 
                    nomal_count++;
                }
            }
        }

        // 적록색약 구역 계산
        visited.assign(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    bfs(i, j, false); 
                    color_blind_count++;
                }
            }
        }
    }

    void printResult() {
        cout << nomal_count << " " << color_blind_count << endl;
    }

private:
    int N;
    vector<vector<char>> rgb_map; // 문자를 저장하는 2D 배열
    vector<vector<bool>> visited;
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int nomal_count, color_blind_count;

    void bfs(int startx, int starty, bool nomal_blind) {
        queue<pair<int, int>> q;
        char target_color = rgb_map[startx][starty];
        q.push({ startx, starty });
        visited[startx][starty] = true;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
                    // 일반인 기준
                    if (nomal_blind) {
                        if (rgb_map[nx][ny] == target_color) {
                            visited[nx][ny] = true;
                            q.push({ nx, ny });
                        }
                    }
                    // 적록색약 기준
                    else {
                        if ((target_color == 'R' || target_color == 'G') &&
                            (rgb_map[nx][ny] == 'R' || rgb_map[nx][ny] == 'G')) {
                            visited[nx][ny] = true;
                            q.push({ nx, ny });
                        }
                        else if (rgb_map[nx][ny] == target_color) {
                            visited[nx][ny] = true;
                            q.push({ nx, ny });
                        }
                    }
                }
            }
        }
    }
};

int main() {
    int N;
    cin >> N;

    redgreen rg(N);
    rg.input();
    rg.solve();
    rg.printResult();

    return 0;
}
