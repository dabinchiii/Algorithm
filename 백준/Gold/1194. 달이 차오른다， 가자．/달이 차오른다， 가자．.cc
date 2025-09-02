#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct loc {
	int r, c;
};

int N, M;
char board[50][50];
int ans;

loc ms;


int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct qNode {
	int r, c, d, k;
};

bool check(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M; 
}
void solve() {
	ans = -1;

	int INF = 5000;
	queue<qNode> q;
	bool visited[50][50][64]; // 3차원 => [r][c][키 정보]


	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 50; j++) {
			for (int k = 63; k >= 0; k--) {
				visited[i][j][k] = false;
			}
		}
	}
	q.push({ ms.r, ms.c, 0, 0 }); // r, c, 누적 거리, 보유한 키 정보
	visited[ms.r][ms.c][0] = 0;

	while (!q.empty()) {
		qNode curr = q.front();
		q.pop();

		if (board[curr.r][curr.c] == '1') {
			ans = curr.d;
			return;
		}

		for (int d = 0; d < 4; d++) {
			int nr = curr.r + dr[d];
			int nc = curr.c + dc[d];
			int nd = curr.d + 1;
			int nk = curr.k;

			if (!check(nr, nc)) continue;
			if (board[nr][nc] == '#') continue; // 벽

			else if (board[nr][nc] >= 'a' && board[nr][nc] <= 'f') { // 열쇠
				int idx = board[nr][nc] - 'a';
				nk |= (1 << idx);
			}
			else if(board[nr][nc] >= 'A' && board[nr][nc] <= 'F'){ // 문
				int idx = board[nr][nc] - 'A';
				if ((curr.k & (1 << idx)) == 0) { // 열쇠 없음
					continue; 
				}
			}
			
			if (visited[nr][nc][nk]) continue;

			visited[nr][nc][nk] = true;
			q.push({ nr, nc, nd, nk });
			
		}
	}

	ans = -1;

	return;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];

			if (board[i][j] == '0') {
				ms = { i, j }; // 민식이 서 있는 곳
				board[i][j] = '.';
			}
		}
	}

	solve();

	cout << ans;

	return 0;
}