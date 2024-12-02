
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class InputHandler {
public:
    int N; 
    vector<int> M; 
    pair<int, int> start_end; 

    void readInput() {
        cin >> N; 
        for (int i = 0; i < N; i++) {
            int a;
            cin >> a;
            M.push_back(a);
        }
        cin >> start_end.first >> start_end.second;
    }

    // 징검다리 최소 점프 계산 함수
    int steppingStones() {
        vector<bool> visited(N, false);
        queue<pair<int, int>> q; 

        int start = start_end.first - 1; 
        int end = start_end.second - 1; 

        q.push({ start, 0 });
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front().first; 
            int jumps = q.front().second; 
            q.pop();

            if (current == end) {
                return jumps;
            }

            int step = M[current];
            for (int i = current + step; i < N; i += step) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({ i, jumps + 1 });
                }
            }
            for (int i = current - step; i >= 0; i -= step) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({ i, jumps + 1 });
                }
            }
        }
        return -1;
    }
};

int main() {
    InputHandler input;
    input.readInput();
    int result = input.steppingStones();
    cout << result << endl;
    return 0;
}
