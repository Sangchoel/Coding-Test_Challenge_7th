#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MinJumpSolver {
private:
    int N;
    vector<int> A;
    vector<int> jumps;

public:
    MinJumpSolver(int n, const vector<int>& arr) : N(n), A(arr), jumps(n, 1000000) {}

    int solve() {
        queue<int> q;
        jumps[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 1; i <= A[curr]; i++) {
                int next = curr + i;
                if (next >= N) break;

                if (jumps[next] > jumps[curr] + 1) {
                    jumps[next] = jumps[curr] + 1;
                    q.push(next);
                }
            }
        }

        return jumps[N - 1] == 1000000 ? -1 : jumps[N - 1];
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    MinJumpSolver solver(N, A);
    cout << solver.solve() << endl;

    return 0;
}
