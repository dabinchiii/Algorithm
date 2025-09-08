#include <iostream>
#include <vector>

using namespace std;

int N;
int arr[33][33];
long long dp[33][33][3];
long long ans;

void solve() {
	dp[1][2][0] = 1;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (arr[i][j] == 1) continue;

			dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][1];

			if (arr[i - 1][j] == 0 && arr[i][j - 1] == 0) {
				dp[i][j][1] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
			}
			
			dp[i][j][2] += dp[i - 1][j][1] + dp[i - 1][j][2];
		}
	}

	ans = dp[N][N][0] + dp[N][N][1] + dp[N][N][2];
	
	return;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	solve();

	cout << ans;

	return 0;
}