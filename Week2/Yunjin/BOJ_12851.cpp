#include <iostream>
#include <queue>

using namespace std;

int N, K;
int total_count = 0; // 같은 시간, 다른 방법의 수
int min_time = 100001; // 최소 시간
int visited[100001] = {0, }; // 수빈이가 방문한 위치

queue<pair<int, int>> q;

int main() {

    // input
	cin >> N >> K;

	q.push(make_pair(N, 0)); // { 수빈이의 위치, 걸린 시간 }
    visited[N] = 1;
    bool find = false; 

    // BFS
	while (!q.empty()) {
		int location = q.front().first;
		int cnt = q.front().second;
		q.pop();

		visited[location] = 1;

        // 다른 방법으로 동생의 위치에 도달할 때
        if(find && min_time == cnt && location == K) {
            total_count++;
        }

        // 수빈이가 동생이 있는 위치에 처음으로 도달할 떄
		if (!find && location == K) {
			min_time = cnt; // 최소 시간 저장
            find = true; // 처음으로 같은 위치에 도달함
            total_count++;
		}

        // 이동 가능한 위치 
        if(location + 1 < 100001 && location + 1 >= 0 && visited[location + 1] != 1) {
            q.push(make_pair(location + 1, cnt + 1));
        }

        if(location - 1 < 100001 && location - 1 >= 0 && visited[location - 1] != 1) {
            q.push(make_pair(location - 1, cnt + 1));
        } 

        if(location * 2 < 100001 && location * 2 >= 0 && visited[location * 2] != 1) {
            q.push(make_pair(location * 2, cnt + 1));
        }              
	}

    cout << min_time << "\n" << total_count;

    return 0;
}