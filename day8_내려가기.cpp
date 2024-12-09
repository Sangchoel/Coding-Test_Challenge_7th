ㅇ#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int max_dp[3] = {0}, min_dp[3] = {0};  // 이전 줄의 최대/최소 점수
    int curr[3];                           // 현재 줄의 입력 값

    for (int i = 0; i < n; i++) {
        cin >> curr[0] >> curr[1] >> curr[2];

        // 새로운 최대/최소 값을 임시로 계산
        int temp_max[3], temp_min[3];
        temp_max[0] = curr[0] + max(max_dp[0], max_dp[1]);
        temp_max[1] = curr[1] + max({max_dp[0], max_dp[1], max_dp[2]});
        temp_max[2] = curr[2] + max(max_dp[1], max_dp[2]);

        temp_min[0] = curr[0] + min(min_dp[0], min_dp[1]);
        temp_min[1] = curr[1] + min({min_dp[0], min_dp[1], min_dp[2]});
        temp_min[2] = curr[2] + min(min_dp[1], min_dp[2]);

        // 결과 업데이트
        for (int j = 0; j < 3; j++) {
            max_dp[j] = temp_max[j];
            min_dp[j] = temp_min[j];
        }
    }

    // 최종 결과
    cout << *max_element(max_dp, max_dp + 3) << " "
         << *min_element(min_dp, min_dp + 3) << endl;

    return 0;
}
