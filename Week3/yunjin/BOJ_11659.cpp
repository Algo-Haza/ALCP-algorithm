#include <iostream>

using namespace std;

int N;
int M;
int arr[100001];
long long dp[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// dp로 합을 미리 구해둔다
	dp[1] = arr[1];
	for (int i = 2; i <= N; i++) {
		dp[i] = dp[i - 1] + arr[i];
	}

	// 구간 합 구학
	int start, end;
	for (int i = 0; i < M; i++) {

		cin >> start >> end;
		if (start == 1) {
			cout << dp[end] << "\n";
		}
		else {
			cout << dp[end] - dp[start - 1] << "\n";
		}
	
	}
	return 0;
}