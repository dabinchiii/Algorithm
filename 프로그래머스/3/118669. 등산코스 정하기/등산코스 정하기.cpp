#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define MAX_N 50000
#define INF 100000000

using namespace std;

vector<pair<int, int>> g[MAX_N + 1];

vector<int> solution(int N, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	for (vector<int> path : paths) {
		int u = path[0];
		int v = path[1];
		int d = path[2];

		g[u].push_back({ v, d });
		g[v].push_back({ u, d });
	}

	vector<int> dist(N + 1, INF);
	priority_queue<pair<int, int>> pq; // {-현재intensity, 노드}

	for (int gate : gates) {
		pq.push({ 0, gate });
		dist[gate] = 0;
	}

	vector<bool> isPeak(N + 1, false);
	for (int peak : summits) {
		isPeak[peak] = true;
	}

	while (!pq.empty()) {
		int currV = pq.top().second;
		int currD = -pq.top().first;
		pq.pop();

		if (dist[currV] < currD) continue;

		for (pair<int, int> nxt : g[currV]) {
			int nxtV = nxt.first;
			int nxtD = max(currD, nxt.second);

			if (dist[nxtV] > nxtD) {
				dist[nxtV] = nxtD;
				
				if (!isPeak[nxtV]) pq.push({ -nxtD, nxtV });
			}
		}
	}

	vector<int> answer;
	int minD = INF, minV = -1;
	for (int i = 1; i <= N; i++) {
		if (!isPeak[i]) continue;
		if (dist[i] < minD) {
			minD = dist[i];
			minV = i;
		}
	}

	answer.push_back(minV);
	answer.push_back(minD);

	return answer;
}