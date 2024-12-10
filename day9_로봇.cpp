#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

class robot {
private:
    int M, n; 
    vector<pair<string, int>> order; 
    int x, y, dir;

public:
    void input() {
        cin >> M >> n;

        for (int i = 0; i < n; i++) {
            string cmd;
            int val;
            cin >> cmd >> val;
            order.push_back({ cmd, val });
        }
    }

    void nav() {
        x = 0;
        y = 0;
        dir = 0;
        //동남서북 기준
        int dx[4] = { 1,0,-1,0 };
        int dy[4] = { 0,-1,0,1 };

        //   북(3)
        //서(2)   동(0)  
        //    남(1)
        //
        for (int i = 0; i < order.size(); i++) {
            if (order[i].first == "TURN") {
                if (order[i].second == 0) {
                    dir = (dir + 3) % 4;
                }
                else if(order[i].second == 1){
                    dir = (dir + 1) % 4;

                }
            }
            else if (order[i].first == "MOVE") {
                int nx = x + (dx[dir] * order[i].second);
                int ny = y + (dy[dir] * order[i].second);

                if (nx < 0 || ny < 0 || nx > M || ny > M) {
                    cout << -1 << endl;
                    return;
                }

                x = nx;
                y = ny;
            }
        }
        cout << x << " " << y;
    }
};

int main() {
    robot myRobot;

    myRobot.input();
    myRobot.nav();

    return 0;
}
