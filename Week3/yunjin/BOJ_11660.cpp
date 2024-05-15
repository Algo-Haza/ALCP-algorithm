#include <iostream>

using namespace std;

int N; // 크기
int M; // 구해야 하는 횟수
int arr[1025][1025];
long long dp[1025][1025];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	// dp로 합을 미리 구해둔다
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= N; i++) {
		dp[1][i] = dp[1][i - 1] +  arr[1][i];
		dp[i][1] = dp[i - 1][1] + arr[i][1];
	}
	
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + arr[i][j];
		}
	}


	// 구간 합 구하기
	int x1, y1, x2, y2;
	for (int i = 0; i < M; i++) {

		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1-1][y1 - 1]<< "\n";
		
	
	}
	return 0;
}