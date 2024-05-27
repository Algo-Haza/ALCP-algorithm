#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N; // 보석의 개수
int K; // 가방의 개수
int answer = 0;

// 각 가방에 담겨있는 최고의 보석을 위한 우선순위 큐
priority_queue<int, vector<int>, less<int>> pq;

vector<int> backpack; // backpack[i] : i 가방에 담을 수 있는 최대 무게
vector<pair<int, int>> dia;

int main() {
    // input
    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        int info, value;
        cin >> info >> value;
        dia.push_back({info, value});
    }

    for(int i = 0; i < K; i++) {
        int bag;
        cin >> bag;
        backpack.push_back(bag);
    }

    // 보석, 가방 모두 오름차순 정렬
    sort(backpack.begin(), backpack.end());
    sort(dia.begin(), dia.end());

    int index = 0;
    long long sum = 0;

    // 가방을 전부 확인
    for(int i = 0; i < K; i++) {
        // 다이아들을 확인하면서, 현재 가방이 감당 가능할 정도까지 우선순위 큐에 담음
        while(index < N && backpack[i] >= dia[index].first) {
            pq.push(dia[index].second);
            index++;
        }

        // 우선순위 큐 top이, 현재 가방에 넣을 수 있는 가장 비싼 보석
        if(!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum;

}