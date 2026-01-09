#include <iostream>
#include <vector>
#include <queue>

#define MAX_N 300
#define MAX_M 300

using namespace std;

struct loc {
	int r, c;
};

int N, M;
loc s, e;
bool board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];
int ans;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

queue<loc> q;
queue<loc> nxtQ;

bool check(int r, int c) {
	return r >= 0 && r < N && c >= 0 && c < M;
}

bool bfs() {
	while (!nxtQ.empty()) {
		q.push(nxtQ.front());
		nxtQ.pop();
	}

	while (!q.empty()) {
		loc curr = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = curr.r + dr[d];
			int nc = curr.c + dc[d];

			if (!check(nr, nc)) continue;
			if (visited[nr][nc]) continue;

			if (nr == e.r && nc == e.c) {
				return true;
			}

			visited[nr][nc] = true;

			if (board[nr][nc]) {
				nxtQ.push({ nr, nc });
				board[nr][nc] = false;
			}
			else {
				q.push({ nr, nc });
			}
		}
		
	}
	
	return false;
}
void solve() {
	nxtQ.push(s);
	visited[s.r][s.c] = true;

	int jump = 1;
	while (!bfs()) ++jump;
	ans = jump;

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	cin >> s.r >> s.c >> e.r >> e.c;
	--s.r; --s.c; --e.r; --e.c;

	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			if (line[j] == '1') board[i][j] = true;
		}
	}

	solve();

	cout << ans;

	return 0;
}