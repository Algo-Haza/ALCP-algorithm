#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 1001

using namespace std;

int N; // 우주신들의 개수
int M; // 통로의 개수

/**
 * 간선이 주어지지 않은 MST 문제
 * ==> find_parent, same_parent, node_union 외에 find_dist를 추가한다.
*/

vector<pair<int, int>> nodes;
vector<pair<int, int>> connects;
vector<pair<double, pair<int, int>>> edges;

int parent[MAX];
double answer = 0;

// 재귀를 이용해서 조상 노드를 찾아 나감
int find_parent(int node) {
    if(node == parent[node]) return node;
    return parent[node] = find_parent(parent[node]);
}

// 두 노드의 조상이 같은지 확인
bool same_parent(int x, int y) {
   x = find_parent(x);
   y = find_parent(y);

   if(x == y) return true;
   else return false;
}

void node_union(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    parent[y] = x;
}

// 간선의 가중치가 주어지지 않았기 때문에, 계산하는 함수 필요
double find_dist(int x1, int y1, int x2, int y2) {
    double dx = pow(x1 - x2, 2);
    double dy = pow(y1 - y2, 2);
    double dist = sqrt(dx + dy);

    return dist;
}

int main() {
    // input
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        nodes.push_back(make_pair(a, b));
    }

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        connects.push_back(make_pair(a, b));
    }

    // 자기 자신의 부모를 자기로 초기화
    for(int i = 1; i <= N; i++) parent[i] = i;

    /**
     * MST
    */

    // 1. 이미 주어진 연결 노드를 union
    for(int i = 0; i < M; i++) {
        int node1 = connects[i].first;
        int node2 = connects[i].second;

        if(!same_parent(node1, node2)) node_union(node1, node2);
    }

    // 2. 모든 노드 사이 거리 계산
    for(int i = 0; i < N - 1; i++) {
        int x1 = nodes[i].first;
        int y1 = nodes[i].second;

        for(int j = i + 1; j < N; j++) {
            int x2 = nodes[j].first;
            int y2 = nodes[j].second; 

            double dist = find_dist(x1, y1, x2, y2);
            edges.push_back(make_pair(dist, make_pair(i + 1, j + 1))); // 노드 번호
        }
    }

    // 3. 간선의 가중치 정렬
    sort(edges.begin(), edges.end());

    // 4. MST
    for(int i = 0; i < edges.size(); i++) {
        int node1 = edges[i].second.first;
        int node2 = edges[i].second.second;
        double dist = edges[i].first;

        if(!same_parent(node1, node2)) {
            node_union(node1, node2);
            answer += dist;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << answer;

    return 0;
}