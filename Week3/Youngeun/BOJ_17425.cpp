#include <iostream>
using namespace std;
long long dp[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	for (int i = 1; i <= 1000000; i++) {
		for (int j = i; j <= 1000000; j += i) {
			dp[j] += i;
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		dp[i] += dp[i - 1];
	}
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}	
}