#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class plusplus {
private:
    int T;
    int number;
    vector<int> n;
    vector<int> dp;

public:    
    void input() {
        cin >> T;
        for (int i = 0; i < T; i++) {
            cin >> number;
            n.push_back(number);
        }
    }

    void solve() {
        dp.resize(12, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;

        for (int i = 4; i < 11; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        for (int i = 0; i < T; i++) {
            cout << dp[n[i]] << endl;
        }
    }

};

int main() {
    plusplus solver;
    solver.input();
    solver.solve();
    return 0;
}
