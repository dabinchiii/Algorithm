#include <iostream>
#include <algorithm>

#define MAX_N 50000

using namespace std;

int N, K;
int arr[MAX_N + 1], dp[3][MAX_N + 1];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> K;

	for (int i = 0; i < 3; i++) {
		for (int j = i * K; j <= N; j++) {
			if(i == 0) dp[i][j] = max(dp[i][j - 1], arr[j] - arr[j - K]);
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - K] + arr[j] - arr[j - K]);
		}
	}

	cout << dp[2][N];

	return 0;
}