#include <iostream>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int N, K;
int arr[MAX_N + 1], sum[MAX_N + 1], dp[4][MAX_N + 1];
int ans;

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> arr[i];
	cin >> K;

	int curr = 0;
	for (int i = 1; i <= K; i++) curr += arr[i];
	sum[K] = curr;

	for (int i = K + 1; i <= N; i++) {
		curr -= arr[i - K];
		curr += arr[i];
		sum[i] = curr;
		
	}

	for (int i = 1; i <= 3; i++) {
		for (int j = i * K; j <= N; j++) {
			dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - K] + sum[j]);
		}
	}

	ans = dp[3][N];

	cout << ans;

	return 0;
}