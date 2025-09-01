#include <iostream>
#include <vector>

using namespace std;

int N, L;
int board[100][100];
int ans;

bool checkRow(int r) {
	vector<bool> visited(N, false);
	for (int c = 0; c < N - 1; c++) {
		int curr = board[r][c];
		int nxt = board[r][c + 1];

		if (abs(curr - nxt) >= 2) return false;
		else if (nxt == curr - 1) { // 한 칸 낮음
			for (int l = L; l >= 1; l--) {
				if (c + l >= N || visited[c + l] || board[r][c + l] != nxt) return false;
				visited[c + l] = true;
			}
		}
		else if (nxt == curr + 1) { // 한 칸 높음
			for (int l = 0; l < L; l++) {
				if (c - l < 0 || visited[c - l] || board[r][c - l] != curr) return false;
				visited[c - l] = true;
			}
		}
	}

	return true;
}
bool checkCol(int c) {
	vector<bool> visited(N, false);
	for (int r = 0; r < N - 1; r++) {
		int curr = board[r][c];
		int nxt = board[r + 1][c];

		if (abs(curr - nxt) >= 2) return false;
		else if (nxt == curr - 1) { // 한 칸 낮음
			for (int l = L; l >= 1; l--) {
				if (r + l >= N || visited[r + l] || board[r + l][c] != nxt) return false;
				visited[r + l] = true;
			}
		}
		else if (nxt == curr + 1) { // 한 칸 높음
			for (int l = 0; l < L; l++) {
				if (r - l < 0 || visited[r - l] || board[r - l][c] != curr) return false;
				visited[r - l] = true;
			}
		}
	}
	return true;
}
void solve() {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (checkRow(i)) {
			cnt++;
		}
		if (checkCol(i)) {
			cnt++;
		}
	}
	ans = cnt;
	return;
}

int main() {
	cin >> N >> L;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	solve();

	cout << ans;

	return 0;
}