#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>

#define MAX_N 25
#define MAX_M 25

#define MAX_D 1000000

using namespace std;

// 상하좌우
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

int N, M, T, D;
int board[MAX_N][MAX_M];
int ans;

bool isValid(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

vector<vector<int>> dijkstra1() { // (0, 0)에서 시작하여 다른 모든 칸, 기존 비용 구하는 방식 사용
	priority_queue<pair<int, pair<int, int>>> pq;
	vector<vector<int>> dist(N, vector<int>(M, MAX_D + 1));

	pq.push({ 0, {0, 0} });
	dist[0][0] = 0;

	int diff, cost;
	while (!pq.empty()) {
		int currD = -pq.top().first;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();

		if (dist[r][c] < currD) continue;

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (!isValid(nr, nc)) continue;

			// 건너가려는 칸의 높이가 현재보다 낮거나 같다면, 비용은 1
			// 높다면, 비용은 높이차의 제곱
			diff = board[nr][nc] - board[r][c];
			if (diff > T) continue;

			if (diff <= 0) cost = 1;
			else cost = diff * diff;
			
			if (currD + cost >= D) continue;

			if (currD + cost < dist[nr][nc]) {
				dist[nr][nc] = currD + cost;
				pq.push({ -dist[nr][nc], {nr, nc} });
			}
		}
	}

	return dist;
}
vector<vector<int>> dijkstra2() { // (0, 0)에서 시작하여 다른 모든 칸, 기존과 반대로 구하기
	priority_queue<pair<int, pair<int, int>>> pq;
	vector<vector<int>> dist(N, vector<int>(M, MAX_D + 1));

	pq.push({ 0, {0, 0} });
	dist[0][0] = 0;

	while (!pq.empty()) {
		int currD = -pq.top().first;
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		pq.pop();

		if (dist[r][c] < currD) continue;

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (!isValid(nr, nc)) continue;

			int cost;

			// 건너가려는 칸의 높이가 현재보다 낮거나 같다면, 비용은 높이차 제곱
			// 높다면, 비용은 1
			int diff = board[nr][nc] - board[r][c];
			if (diff > T) continue;

			if (diff < 0) cost = diff * diff;
			else cost = 1;

			if (currD + cost >= D) continue;

			if (currD + cost < dist[nr][nc]) {
				dist[nr][nc] = currD + cost;
				pq.push({ -dist[nr][nc], {nr, nc} });
			}
		}
	}

	return dist;
}

void solve() {
	vector<vector<int>> distGo = dijkstra1();
	vector<vector<int>> distBack = dijkstra2();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (distGo[i][j] + distBack[i][j] > D) continue;
			ans = max(ans, board[i][j]);
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> T >> D;
	
	string line;
	char ch;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			ch = line[j];
			board[i][j] = (ch >= 'a' ? ch - 'a' + 26 : ch - 'A');
		}
	}

	solve();

	cout << ans;

	return 0;
}