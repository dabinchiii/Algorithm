#include <iostream>
#include <algorithm>
#include <cmath>

#define MAX_W 1000

#define S1 (MAX_W + 1)
#define S2 (MAX_W + 2)

using namespace std;

int N, W;
pair<int, int> arr[MAX_W + 5];
int dp[MAX_W + 1][MAX_W + 1];
int seq[MAX_W + 1][MAX_W + 1];

int dist(int x, int y, int k) {
	if (x == 0) x = (k == 1 ? S1 : S2);
	return abs(arr[x].first - arr[y].first) + abs(arr[x].second - arr[y].second);
}

int f(int a, int b) {
	if (a == W || b == W) return dp[a][b] = 0;
	if (dp[a][b] != -1) return dp[a][b];

	int target = max(a, b) + 1; // 이번에 처리할 사건 번호

	int d1, d2; // d1: 이번 문제를 경찰차1이 처리했을 때 거리합, d2: 이번 문제를 경찰차2가 처리했을 때 거리합
	d1 = dist(a, target, 1) + f(target, b);
	d2 = dist(b, target, 2) + f(a, target);

	if (d1 < d2) {
		seq[a][b] = 1; // 이번 사건은 1번이 푼다.
	}
	else {
		seq[a][b] = 2;
	}

	return dp[a][b] = min(d1, d2);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> W;
	for (int i = 1; i <= W; i++) cin >> arr[i].first >> arr[i].second;
	
	arr[S1] = { 1, 1 };
	arr[S2] = { N, N };
	for (int i = 0; i <= W; i++) {
		for (int j = 0; j <= W; j++) {
			dp[i][j] = -1;
			seq[i][j] = -1;
		}
	}

	f(0, 0);
	
	cout << dp[0][0] << '\n';
	int a = 0, b = 0;
	for (int i = 0; i < W; i++) {
		cout << seq[a][b] << '\n';
		if (seq[a][b] == 1) a = i + 1;
		else b = i + 1;
	}

	return 0;
}