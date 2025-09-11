#include <string>
#include <vector>
#include <queue>

#define MAX_N 50
#define MAX_M 50
#define MAX_K 2500

using namespace std;

struct qNode {
	int r, c, d; // d는 path의 길이와 같음
	string path;
};

int N, M;
bool visited[MAX_N + 1][MAX_M + 1][MAX_K + 1];

// 하좌우상
int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};
char ch[] = { 'd', 'l', 'r', 'u'};

bool check(int r, int c) {
	return r > 0 && r <= N && c > 0 && c <= M;
}
string solution(int n, int m, int sr, int sc, int destr, int destc, int k) {
	N = n;
	M = m;

	queue<qNode> q;

	q.push({ sr, sc, 0, "" });

	while (!q.empty()) {
		qNode curr = q.front();
		q.pop();

		//printf("curr: (%d, %d) %s\n", curr.r, curr.c, curr.path.c_str());

		if (curr.d == k) {
			if (curr.r == destr && curr.c == destc) {
				return curr.path;
			}
			continue; // 이미 k니까 더 가면 나가리
		}

		for (int d = 0; d < 4; d++) {
			int nr = curr.r + dr[d];
			int nc = curr.c + dc[d];
			int nd = curr.d + 1;
			string npath = curr.path + ch[d];

			if (!check(nr, nc)) continue;
			if (visited[nr][nc][nd]) continue;

			visited[nr][nc][nd] = true;
			q.push({ nr, nc, nd, npath });
		}
	}

	return "impossible";
}