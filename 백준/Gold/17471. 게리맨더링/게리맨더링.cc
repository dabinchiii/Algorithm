#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
int arr[11]; // 인구수
int total;
bool team[11];
int ans;

bool visited[11];

vector<int> g[11];

int bfs(int start, bool currTeam) {
	queue<int> q;
	fill(visited, visited + N + 1, false);
	int cnt = 1;

	q.push(start);
	visited[start] = true;
	int curr;
	while (!q.empty()) {
		curr = q.front();
		q.pop();
		for (int nxt : g[curr]) {
			if (visited[nxt] || team[nxt] != currTeam) continue;
			visited[nxt] = true;
			q.push(nxt);
			cnt++;
		}
	}

	return cnt;
}
bool isValid() {
	int cntA = 0, cntB = 0, bIdx;
	for (int i = 1; i <= N; i++) {
		if (!team[i]) cntA++;
		else bIdx = i;
	}
	cntB = N - cntA;
	if (cntB == 0) return false;

	// A 선거구 모두 연결됐는지 확인
	if (bfs(1, false) != cntA) return false;
	
	// B 선거구 모두 연결됐는지 확인
	if (bfs(bIdx, true) != cntB) return false;

	return true;
}
void subset(int cnt, int totalA) {
	if (cnt == N + 1) {
		int totalB = total - totalA;
		if (isValid()) ans = min(ans, abs(totalA - totalB));
		return;
	}

	team[cnt] = false;
	subset(cnt + 1, totalA + arr[cnt]);

	team[cnt] = true;
	subset(cnt + 1, totalA);

	return;
}
void solve() {
	ans = 1000;

	team[1] = false; // 1번 구역을 A팀으로 고정
	subset(2, arr[1]);

	if (ans == 1000) ans = -1;

	return;
}
int main() {
	// N <= 10이니까 부분집합 가능 => 2^10
	// 각 구역 별로 A 선거구에 포함되는 경우, B 선거구에 포함되는 경우를 구함..
	// 각 선거구는 적어도 하나의 구역을 포함해야 하므로 하나는 고정 시킴 => 2^9
	// 구역 별로 선거구가 모두 정해지면, 유효성 검사
	// 유효하다 == A 선거구끼리 모두 연결 && B 선거구끼리 모두 연결
	// 유효할 경우에 인구 차이 최소값 갱신 시도

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	int num, u;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		for (int j = 0; j < num; j++) {
			cin >> u;
			g[i].push_back(u);
			g[u].push_back(i);
		}
	}

	solve();

	cout << ans;

	return 0;
}