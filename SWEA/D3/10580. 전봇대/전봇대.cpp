#include <iostream>
#include <algorithm>

using namespace std;

int N;
pair<int, int> line[1000];
int ans;

void solve() {
	// 나보다 시작점 높은데 도착점 낮음 => 교차
	ans = 0;
	sort(line, line + N);

	for (int i = 0; i < N; i++) {
		int e = line[i].second;
		for (int j = i + 1; j < N; j++) { // 정렬했으므로 시작점은 j가 더 높은 상태
			if (line[j].second < e) ans++; // 도착점 더 낮음
		}
	}

	return;
}

int main() {
	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;
		for (int i = 0; i < N; i++) cin >> line[i].first >> line[i].second;

		solve();

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}
