#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> solution(n);

    for (int i = 0; i < n; i++) {
        cin >> solution[i];
    }

    int left = 0, right = n - 1;
    int best_sum = 2e9 + 1;
    int answer1 = solution[left], answer2 = solution[right];

    while (left < right) {
        int sum = solution[left] + solution[right];

        if (abs(sum) < abs(best_sum)) {
            best_sum = sum;
            answer1 = solution[left];
            answer2 = solution[right];
        }

        if (sum > 0) {
            right--;
        }
        else {
            left++;
        }
    }

    cout << answer1 << " " << answer2 << "\n";
    return 0;
}
