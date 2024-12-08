#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<vector<int>> map(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    vector<vector<int>> dp(N, vector<int>(M, 0));
    dp[0][0] = map[0][0];

    // 첫 번째 행 업데이트 (오른쪽으로만 이동)
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + map[0][j];
    }

    // 첫 번째 열 업데이트 (아래로만 이동)
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + map[i][0];
    }

    // 나머지 영역 업데이트
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        }
    }

    cout << dp[N - 1][M - 1] << endl;

    return 0;
}
