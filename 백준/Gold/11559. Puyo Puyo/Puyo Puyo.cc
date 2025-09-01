#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int N = 12, M = 6;
char board[12][6];
int ans;
stack<char> st;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void print() {
	cout << "=======================\n";
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << board[i][j] << ' ';
		}
		cout << endl;
	}
}

bool checkPuyo(int sr, int sc) { // 4개 이상짜리였다면 없애고 true반환, 아니면 false
	char ch = board[sr][sc];
	queue<pair<int, int>> q, q2;
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	q.push({ sr, sc });
	q2.push({ sr, sc });
	visited[sr][sc] = true;

	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			nr = r + dr[d];
			nc = c + dc[d];

			if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
			if (board[nr][nc] != ch) continue;
			if (visited[nr][nc]) continue;

			visited[nr][nc] = true;
			q.push({ nr, nc });
			q2.push({ nr, nc });
		}
	}

	if (q2.size() < 4) return false;

	while (!q2.empty()) {
		board[q2.front().first][q2.front().second] = '.';
		q2.pop();
	}

	return true;
}

void down() { // 중력
	for (int c = 0; c < M; c++) {
		for (int r = 0; r < N; r++) {
			if (board[r][c] == '.') continue;
			st.push(board[r][c]);
			board[r][c] = '.';
		}

		int r = N - 1;
		while (!st.empty() && r >= 0) {
			board[r--][c] = st.top();
			st.pop();
		}
	}
}
bool play() {
	bool boom = false;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] == '.') continue;
			boom |= checkPuyo(i, j);
		}
	}

	if (!boom) return false;

	down();

	return true;
}
void solve() {
	int t = 0;
	while (true) {
		if (!play()) {
			ans = t;
			break;
		}
		//print();
		t++;
	}
	return;
}
int main() {
	string line;
	for (int i = 0; i < N; i++) {
		cin >> line;
		for (int j = 0; j < M; j++) {
			board[i][j] = line[j];
		}
	}

	solve();

	cout << ans;

	return 0;
}