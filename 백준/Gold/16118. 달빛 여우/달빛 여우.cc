#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 4000
#define INF 800000000

using namespace std;

struct nodeW {
	int v;
	double d;
	int order; // 홀/짝 판별용
};

struct comp {
	bool operator()(nodeW a, nodeW b) {
		return a.d > b.d;
	}
};
int N, M;
vector<pair<int, double>> g[MAX_N + 1];
int ans;

double distF[MAX_N + 1], distW[MAX_N + 1][2];

void dijkstraFox() {
	for (int i = 1; i <= N; i++) distF[i] = INF;

	priority_queue<pair<double, int>> pq;

	pq.push({ 0.0, 1 });
	distF[1] = 0.0; // 1에서 시작

	while (!pq.empty()) {
		int currV = pq.top().second;
		int currD = -pq.top().first;
		pq.pop();

		if (distF[currV] < currD) continue;

		for (pair<int, int> nxt : g[currV]) {
			int nxtV = nxt.first;
			int nxtD = currD + nxt.second;

			if (nxtD < distF[nxtV]) {
				distF[nxtV] = nxtD;
				pq.push({ -nxtD, nxtV });
			}
		}
	}
	return;
}
void dijkstraWolf() {
	for (int i = 1; i <= N; i++) distW[i][0] = distW[i][1] = INF;
	
	priority_queue<nodeW, vector<nodeW>, comp> pq;
	
	pq.push({ 1, 0.0, 0 }); // 1번 노드에 짝수번의 간선을 이동하여 0초에 도달했다.
	distW[1][0] = 0;

	while (!pq.empty()) {
		nodeW curr = pq.top();
		pq.pop();

		if (distW[curr.v][curr.order] < curr.d) continue;

		for (pair<int, int> nxt : g[curr.v]) {
			int nxtV = nxt.first;
			double nxtD = curr.d + (curr.order ? 2.0 : 0.5) * nxt.second;
			int nxtOrder = curr.order ? 0 : 1;

			if (nxtD < distW[nxtV][nxtOrder]) {
				distW[nxtV][nxtOrder] = nxtD;
				pq.push({ nxtV, nxtD, nxtOrder});
			}
		}
	}
	
	return;
}
void solve() {
	// 여우 다익스트라
	dijkstraFox();

	// 늑대 다익스트라
	dijkstraWolf();
	
	// 여우가 먼저 도착하는 정점 찾기
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (distF[i] < min(distW[i][0], distW[i][1])) cnt++;
	}
	ans = cnt;

	return;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	int a, b;
	double d;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> d;
		g[a].push_back({ b, d });
		g[b].push_back({ a, d });
	}

	solve();

	cout << ans;

	return 0;
}