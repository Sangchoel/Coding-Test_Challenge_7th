#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class TruckBridge {
private:
    int n, w, L;                
    vector<int> trucks;          
    queue<int> bridge;         
    int time;                  
    int current_weight;     

public:
    void input() {
        cin >> n >> w >> L;
        trucks.resize(n);
        for (int i = 0; i < n; ++i) {
            cin >> trucks[i];
        }
    }

    int solve() {
        time = 0;
        current_weight = 0;

        for (int truck : trucks) {
            while (true) {
                if (bridge.size() == w) {
                    current_weight -= bridge.front();
                    bridge.pop();
                }
                if (current_weight + truck <= L) {
                    bridge.push(truck);
                    current_weight += truck;
                    ++time; 
                    break;
                }
                else {
                    bridge.push(0);
                    ++time;
                }
            }
        }
        time += w;
        return time;
    }
};

int main() {
    TruckBridge t;
    t.input();                
    int time = t.solve();     
    cout << time << endl;    
    return 0;
}
