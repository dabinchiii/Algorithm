#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct loc {
	int r, c;
};
int w, h;
vector<vector<char>> board(1000, vector<char>(1000));
int ans;

queue<loc> fire;

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

void printBoard() {
	cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << board[i][j];
		}
		cout << endl;
	}

}
bool isValid(int r, int c) {
	return r >= 0 && r < h && c >= 0 && c < w;
}

void spreadFire() {
	int cnt = fire.size();

	for (int i = 0; i < cnt; i++) {
		loc curr = fire.front();
		fire.pop();

		for (int d = 0; d < 4; d++) {
			int nr = curr.r + dr[d];
			int nc = curr.c + dc[d];

			if (!isValid(nr, nc)) continue;
			if (board[nr][nc] != '.') continue;

			board[nr][nc] = 'F';
			fire.push({ nr, nc });
		}
	}

	return;
}
void solve() {
	ans = -1;

	cin >> h >> w;

	int sr, sc;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') {
				sr = i;
				sc = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'F') {
				fire.push({ i, j });
			}
		}
	}

	queue<pair<loc, int>> q;
	vector<vector<bool>> visited(h, vector<bool>(w, false));

	q.push({ {sr, sc}, 0 });
	visited[sr][sc] = true;

	int t = -1;
	while (!q.empty()) {
		int r = q.front().first.r;
		int c = q.front().first.c;
		int cnt = q.front().second;
		q.pop();

		if (t != cnt) {
			spreadFire();
			t = cnt;

			//printBoard();
		}

		for (int d = 0; d < 4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];


			if (!isValid(nr, nc)) {
				ans = cnt + 1;
				return;
			}

			if (board[nr][nc] != '.') continue;
			if (visited[nr][nc]) continue;

			q.push({ {nr, nc}, cnt + 1 });
			visited[nr][nc] = true;
		}
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	solve();
	if (ans == -1) cout << "IMPOSSIBLE\n";
	else cout << ans << '\n';

	return 0;
}