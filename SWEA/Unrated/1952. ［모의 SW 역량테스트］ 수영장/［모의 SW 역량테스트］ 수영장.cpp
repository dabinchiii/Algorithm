#include <iostream>
#include <vector>

#define min(x, y) (x) < (y) ? (x) : (y)

using namespace std;

int ticket[4], month[13];
int ans;

void solve() {
	vector<int> dp(13, 0);

	for (int i = 1; i <= 12; i++) {
		dp[i] = month[i] * ticket[0] + dp[i - 1];
		dp[i] = min(dp[i], ticket[1] + dp[i - 1]);
		if (i - 3 >= 0) dp[i] = min(dp[i], ticket[2] + dp[i - 3]);
	}

	dp[12] = min(dp[12], ticket[3]);

	ans = dp[12];

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		for (int i = 0; i < 4; i++) cin >> ticket[i];
		for (int i = 1; i <= 12; i++) cin >> month[i];

		solve();

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}