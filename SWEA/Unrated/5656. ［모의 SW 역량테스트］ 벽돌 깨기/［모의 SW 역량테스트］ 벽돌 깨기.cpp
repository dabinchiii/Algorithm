#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>

using namespace std;

int N, W, H;
int ans;

stack<int> st;

int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

struct boomNode {
	int r, c, left;
};
int countRemain(vector<vector<int>> &map) {
	int count = 0;
	for (int r = 0; r < H; r++) {
		for (int c = 0; c < W; c++) {
			if (map[r][c] != 0) count++;
		}
	}

	return count;
}
void boom(int sr, int sc, vector<vector<int>> &map) {
	queue<boomNode> q;

	if (map[sr][sc] > 1) {
		q.push({ sr, sc, map[sr][sc] - 1 });
	}
	map[sr][sc] = 0;

	while (!q.empty()) {
		boomNode curr = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int nr = curr.r, nc = curr.c;
			for (int i = 0; i < curr.left; i++) {
				nr += dr[d];
				nc += dc[d];

				if (nr < 0 || nr >= H || nc < 0 || nc >= W) break;
				if (map[nr][nc] == 0) continue;

				if (map[nr][nc] > 1) {
					q.push({ nr, nc, map[nr][nc] - 1 });
				} // 1이면 지금 뿌시고 끝
				map[nr][nc] = 0;
			}
		}
		
	}

	return;
}
void down(vector<vector<int>> &map) {
	for (int c = 0; c < W; c++) {
		// 현재 열에 남아있는 벽돌 찾기
		for (int r = 0; r < H; r++) {
			if (map[r][c] == 0) continue;

			st.push(map[r][c]);
			map[r][c] = 0;
		}

		// 재배치
		int r = H - 1;
		while (!st.empty()) {
			map[r--][c] = st.top();
			st.pop();
		}
	}
	return;
}
void drop(int count, vector<vector<int>> &map) { // 중복순열. 주어진 board에 대하여, 구슬을 0~W 열에서 낙하시킴
	int remainCnt = countRemain(map);

	if (remainCnt == 0) {
		ans = 0;
		return;
	}
	if (count == N) { // 만약 구슬을 N번 낙하시키기 전에 모든 벽돌이 다 제거되면, 감지하지 못하는 문제 => 현재 남아있는 벽돌 수 체크
		ans = min(ans, countRemain(map));
		return;
	}

	for (int c = 0; c < W; c++) {
		// 가장 위에 있는 벽돌 찾음
		int r = 0;
		while (r < H && map[r][c] == 0) r++;
		if (r == H) continue; // 빈 열

		vector<vector<int>> newMap(map);
		boom(r, c, newMap);
		down(newMap); // 중력 작용
		drop(count + 1, newMap);

	}
	
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> W >> H;

		vector<vector<int>> map(H, vector<int>(W));

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}

		ans = H * W;

		drop(0, map);

		cout << '#' << tc << ' ' << ans << '\n';
	}

}