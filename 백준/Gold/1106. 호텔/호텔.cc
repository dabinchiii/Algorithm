#include <iostream>
#include <vector>
#include <algorithm>

#define INF 110010

using namespace std;

int C, N;

int main() {
	cin >> C >> N;
	
	vector<pair<int, int>> arr(N);

	int maxValue = -1;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
		maxValue = max(maxValue, arr[i].second);
	}

	int maxIdx = C + maxValue;
	vector<int> dp(maxIdx + 1, INF);
	dp[0] = 0;

	for (int i = 1; i <= maxIdx; i++) {
		
		for (auto curr : arr) {
			if (i - curr.second < 0) continue;
			dp[i] = min(dp[i], dp[i - curr.second] + curr.first);
		}
	}

	int ans = INF;
	for (int i = C; i <= maxIdx; i++) {
		ans = min(ans, dp[i]);
	}

	cout << ans;

	return 0;
}