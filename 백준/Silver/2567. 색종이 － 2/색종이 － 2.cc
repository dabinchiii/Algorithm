#include <iostream>
#include <queue>

#define MAX 102

using namespace std;

int n;
bool board[MAX][MAX];
bool visited[MAX][MAX];
int ans;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void stick(int sr, int sc) {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			board[sr + i][sc + j] = true;
		}
	}
	return;
}
void bfs(int sr, int sc) {
	queue<pair<int, int>> q;
	
	q.push({ sr, sc });
	visited[sr][sc] = true;

	int r, c, nr, nc;
	while (!q.empty()) {
		r = q.front().first;
		c = q.front().second;
		q.pop();

		for (int d = 0; d < 4; d++) {
			nr = r + dr[d];
			nc = c + dc[d];

			if (nr < 0 || nr > 100 || nc < 0 || nc > 100) continue;
			if (visited[nr][nc]) continue;

			if (board[nr][nc]) { // 색종이와 맞닿음
				ans++;
				continue;
			}
			else {
				q.push({ nr, nc });
				visited[nr][nc] = true;
			}
		}
	}
}
void solve() {
	for (int i = 0; i <= 101; i++) {
		for (int j = 0; j <= 101; j++) {
			if (!board[i][j] && !visited[i][j]) bfs(i, j);
		}
	}
	return;
}
int main() {
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		stick(a + 1, b + 1);
	}

	solve();

	cout << ans;

	return 0;
}