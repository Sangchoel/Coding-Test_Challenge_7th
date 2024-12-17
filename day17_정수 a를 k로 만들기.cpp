#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int bfs(int a, int k) {
    vector<bool> visited(1000001, false);
    queue<pair<int, int>> q; 
    
    q.push({a, 0}); 
    visited[a] = true;
    
    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == k) return steps;

        if (current + 1 <= k && !visited[current + 1]) {
            q.push({current + 1, steps + 1});
            visited[current + 1] = true;
        }

        if (current * 2 <= k && !visited[current * 2]) {
            q.push({current * 2, steps + 1});
            visited[current * 2] = true;
        }
    }
    
    return -1;
}

int main() {
    int a, k;
    cin >> a >> k;
    cout << bfs(a, k) << endl;
    return 0;
}
