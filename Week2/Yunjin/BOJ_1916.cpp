#include <iostream>
#include <algorithm>
#define INF 100000000

using namespace std;

int N, M;

int graph[1001][1001] = { 0, };
int dist[1001];
int visited[1001];

int find_shortest_city() {
	int next_city, next_dist;

	next_dist = INF;
	next_city = -1;

	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) continue;
		if (dist[i] < next_dist) {
			next_dist = dist[i];
			next_city = i;
		}
	}
	return next_city;
}

void update(int city) {
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 1) continue;
		if (dist[i] > dist[city] + graph[city][i])
			dist[i] = dist[city] + graph[city][i];
	}
}

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = INF;
			if (i == j) graph[i][j] = 0;
		}
	}
	int start, end, weight;
	for (int i = 0; i < M; i++) {
		cin >> start >> end >> weight;
		if(graph[start][end] > weight)  graph[start][end] = weight;
	}

	

	int startcity, endcity;
	cin >> startcity >> endcity;

	for (int i = 1; i <= N; i++) { dist[i] = graph[startcity][i]; }
	dist[startcity] = 0;
	visited[startcity] = 1;
	for (int i = 1; i <= N; i++) {
		int nextcity = find_shortest_city();
		visited[nextcity] = 1;
		//cout << "nextcity " << nextcity;
		update(nextcity);
	}

	cout << dist[endcity];

	/*for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << "\n";
	}*/
}