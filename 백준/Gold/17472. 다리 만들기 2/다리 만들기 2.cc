#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct loc {
	int r, c;
};
struct bridgeNode {
	int r, c, d, len;
};

int N, M;
int board[10][10];
int ans;

vector<pair<int, int>> g[8];

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

bool check(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}
void mark(int sr, int sc, int id) { 
	// (sr, sc)을 포함하는 섬을 id로 마킹하고, 현재까지 찾은 섬들에 대해 가능한 간선을 그래프에 추가

	queue<loc> q;
	queue<bridgeNode> bq;

	q.push({ sr, sc });
	board[sr][sc] = id;

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];

			if (!check(nr, nc)) continue;

			if (board[nr][nc] == 0) { // 섬과 인접한 바다
				bq.push({ nr, nc, d, 1 });
			}
			else if (board[nr][nc] == 1) {
				board[nr][nc] = id;
				q.push({ nr, nc });
			}
		}
	}

	vector<bool> visited(id, false);
	while (!bq.empty()) {
		int r = bq.front().r;
		int c = bq.front().c;
		int d = bq.front().d;
		int len = bq.front().len;
		bq.pop();

		int nr = r + dr[d];
		int nc = c + dc[d];

		if (!check(nr, nc)) continue;

		if (board[nr][nc] == 0) {
			bq.push({ nr, nc, d, len + 1 });
		}
		else if (board[nr][nc] > 1) { // 다른 섬
			if (len < 2) continue;

			int destId = board[nr][nc];
			if (visited[destId]) continue;
			visited[destId] = true;

			g[id].push_back({ destId, len });
			g[destId].push_back({ id, len });
		}
	}
	return;
}

void mst(int lastId) {
	priority_queue<pair<int, int>> pq;
	vector<bool> visited(8, false);

	pq.push({ 0, 2 }); // 2에서 시작

	int total = 0; // 선택된 간선 총 길이
	int cnt = 0; // 선택된 정점 수
	while (!pq.empty()) {
		int currD = -pq.top().first;
		int currV = pq.top().second;
		pq.pop();

		if (visited[currV]) continue;
		visited[currV] = true;

		cnt++;
		total += currD;

		for (pair<int, int> nxt : g[currV]) {
			int nxtV = nxt.first;
			int nxtD = nxt.second;

			if (visited[nxtV]) continue;

			pq.push({ -nxtD, nxtV });
		}
	}

	if (cnt != lastId - 1) ans = -1;
	else ans = total;

	return;
}
void solve() {
	// 그래프화: 섬-정점(id:2~), 다리-간선
	int id = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == 1) mark(i, j, ++id);
		}
	}
	
	// mst
	mst(id);

	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
		}
	}

	solve();

	cout << ans;

	return 0;
}