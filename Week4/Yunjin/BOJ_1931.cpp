#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<long long, long long>> v;
int answer = 0;

bool cmp(pair<long long, long long> a, pair<long long, long long> b) {
	if (a.second < b.second) return true;
	else if (a.second > b.second) return false;
	else {
		if (a.first < b.first) return true;
		else return false;
	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		long long start, end;
		cin >> start >> end;
		v.push_back({ start, end });
	}

	// 끝나는 시간이 이른 순으로 정렬
	sort(v.begin(), v.end(), cmp);

	for(int i = 0; i < v.size(); i++) {
		cout << v[i].first << " " << v[i].second << "\n";
	}

	int current_start;
	int current_end;

	for (int i = 0; i < N; i++) {
		if (i == 0) {
			answer++;
			current_start = v[i].first; // 현재 시작 시간
			current_end = v[i].second; // 현재 종료 시간
			continue;
		}
		
		else {
			if (v[i].first >= current_end) { // 현재 종료 시간보다 다음 수업이 늦게 시작할 때
				answer++;
				current_start = v[i].first;
				current_end = v[i].second;
				continue;
			}
			
		}
	}

	cout << answer;
}