#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 20
using namespace std;

int N, L;
int t[MAX_N + 1], k[MAX_N + 1];
int ans;

void solve() {
	vector<vector<int>> dp(N + 1, vector<int>(L + 1, 0));

	for (int i = 1; i <= N; i++) {
		int currT = t[i], currK = k[i];

		for (int j = 1; j <= L; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - currK >= 0) dp[i][j] = max(dp[i][j], dp[i - 1][j - currK] + currT);
		}
	}

	ans = dp[N][L];

	return;
}
int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N >> L;

		for (int i = 1; i <= N; i++) cin >> t[i] >> k[i];

		solve();

		printf("#%d %d\n", tc, ans);
	}


	return 0;
}