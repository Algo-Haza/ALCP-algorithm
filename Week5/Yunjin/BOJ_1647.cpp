#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001

using namespace std;

int N, M;
int parent[MAX];
vector<pair<int, pair<int, int>>> edge;
vector<int> node;

int answer = 0;

// 재귀를 이용해서 조상 노드를 찾아 나감
int find_parent(int node) {
    if(node == parent[node]) return node;
    else return parent[node] = find_parent(parent[node]);
}

// 두 노드의 조상이 같은지 확인
bool same_parent(int x, int y) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return true;
    else return false;
}

//
void node_union(int x, int y, int cost) {
    x = find_parent(x);
    y = find_parent(y);

    if(x == y) return;
    parent[y] = x;
    //N--;
}


int main() {
    // input
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.push_back(make_pair(c, make_pair(a, b)));
    }

    // 간선을 비용 기준으로 정렬
    sort(edge.begin(), edge.end());

    // 본인 노드의 부모를 본인으로 설정
    for(int i = 1; i <= N; i++) parent[i] = i;

    // MST
    for(int i = 0; i < edge.size(); i++) {
        // 선택한 간선의 두 노드의 조상이 같지 않다면, 서로 연결해야 한다!
        if(!same_parent(edge[i].second.first, edge[i].second.second)) {
            node_union(edge[i].second.first, edge[i].second.second, edge[i].first);
            node.push_back(edge[i].first); // 비용 저장
        }
    }

    /*
     * 마지막에 추가된 간선을 전체 cost에 포함 하지 않는다.
     * ==> 가장 큰 가중치를 가진 간선을 제외한 MST를 만든다!
     */
    for(int i = 0; i < node.size() - 1; i++) answer += node[i];
    cout << answer;

    return 0;
}