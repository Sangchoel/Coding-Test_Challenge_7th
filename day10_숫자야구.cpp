#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

pair<int, int> calculateStrikeAndBall(const string& guess, const string& target) {
    int strikes = 0, balls = 0;

    for (int i = 0; i < 3; ++i) {
        if (guess[i] == target[i]) {
            ++strikes;
        } else if (find(target.begin(), target.end(), guess[i]) != target.end()) {
            ++balls;
        }
    }

    return {strikes, balls};
}

int main() {
    int n;
    cin >> n;

    vector<pair<string, pair<int, int>>> queries;

    for (int i = 0; i < n; ++i) {
        string question;
        int strikes, balls;
        cin >> question >> strikes >> balls;
        queries.push_back({question, {strikes, balls}});
    }

    int possibleAnswers = 0;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            if (i == j) continue;
            for (int k = 1; k <= 9; ++k) {
                if (i == k || j == k) continue;

                string candidate = to_string(i) + to_string(j) + to_string(k);
                bool isValid = true;

                for (const auto& query : queries) {
                    string question = query.first;
                    int expectedStrikes = query.second.first;
                    int expectedBalls = query.second.second;

                    auto [strikes, balls] = calculateStrikeAndBall(question, candidate);

                    if (strikes != expectedStrikes || balls != expectedBalls) {
                        isValid = false;
                        break;
                    }
                }

                if (isValid) {
                    ++possibleAnswers;
                }
            }
        }
    }

    cout << possibleAnswers << endl;

    return 0;
}
