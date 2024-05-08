#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 123456789

using namespace std;

int N, M; // 회의에 참석하는 사람 수, 서로 알고 있는 관계의 수

int graph[101][101];
int visited[101] = {0,};

vector<vector<int>> components;

void BFS() {
    for(int i = 0; i < N; i++) {

        // 위원회
        if(visited[i] != 1) {
            vector<int> v;
            queue<int> q;
            visited[i] = 1;

            v.push_back(i); // vector를 이용해서 이차원 배열 표현을 위해 v 사용
            q.push(i);

            while(!q.empty()) {
                int x = q.front();
                q.pop();
                for(int n = 0; n < N; n++) {
                    if(visited[n] = 0 || graph[x][n] == INF) continue;
                    q.push(n);
                    v.push_back(n);
                    visited[n] = 1;
                }
            }

            components.push_back(v);
        }
    }
}


int main() {
    // input
    cin >> N >> M;
    
    for(int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;

        // 서로 알고 있는 가중치 0 그래프
        graph[start - 1][end - 1] = 1;
        graph[end - 1][start - 1] = 1;
    }

    // 서로 모르는 값은 INF로 초기화
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!graph[i][j]) graph[i][j] = INF;
        }
    }

    BFS(); // 위원회 

    // 플로이드-와샬
    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k]+graph[k][j]);
            }
        }
    }

    // 위원회의 수 출력
    cout << components.size() << "\n";

    vector<int> answer;

    // 위원회의 의사 전달 시간의 최댓값 중 최소
    for(auto v : components) {
        int time = 0;
        int min_time = INF;
        for(int i : v) {
            int max_time = 0;
            for(int j : v) {
                if(i == j) continue;
                if(graph[j][i] > max_time) max_time = graph[j][i];
            }
            if(max_time < min_time) {
                min_time = max_time;
                time = i;
            }
        }
        answer.push_back(time + 1);
    }

    // 오름차순으로 정렬하여 출력
    sort(answer.begin(), answer.end());

    for(int x : answer) {
        cout << x << "\n";
    }

    return 0;
}