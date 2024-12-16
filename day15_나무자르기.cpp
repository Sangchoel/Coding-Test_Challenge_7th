#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class felling {
private:
    int N = 0, M = 0;
    vector<int> tree_height;
    int answer = 0;
public:
    void input() {
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            int tree;
            cin >> tree;
            tree_height.push_back(tree);
        }
    }
    void solve() {
        sort(tree_height.begin(), tree_height.end());

        int low = 0, high = tree_height.back();

        while (low <= high) {
            int mid = (low + high) / 2;
            long long cutted_tree = 0;

            for (int height : tree_height) {
                if (height > mid) {
                    cutted_tree += (height - mid);
                }
            }

            if (cutted_tree == M) {
                answer = mid;
                break;
            }
            else if (cutted_tree > M) {
                answer = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    void output() {
        cout << answer << endl;
    }

};

int main() {
    felling f;
    f.input();
    f.solve();
    f.output();
    return 0;
}
