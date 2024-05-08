#include <iostream>
#include <queue>

using namespace std;

int N, K;
int visited[100001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {

    // input
    cin >> N >> K;
    
    pq.push(make_pair(0, N)); // { 수빈이의 위치, 걸린 시간 }

    while(!pq.empty()) {
        int time = pq.top().first;
        int x = pq.top().second;

        pq.pop();

        visited[x] = 1;

        // stop condition
        if(x == K) {
            cout << time;
            break;
        }

        if(x - 1 < 100001 && x - 1 >= 0 && visited[x - 1] != 1) {
            pq.push(make_pair(time + 1, x - 1));
        }
        if(x + 1 < 100001 && x + 1 >= 0 && visited[x + 1] != 1) {
            pq.push(make_pair(time + 1, x + 1));
        }
        if(x * 2 < 100001 && x * 2 >= 0 && visited[x * 2] != 1) {
            pq.push(make_pair(time, x * 2)); // 0초 후 순간 이동
        }
    }

    return 0;
}