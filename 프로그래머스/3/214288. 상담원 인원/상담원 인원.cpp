#include <string>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<vector<int>> list[6];
int arr[6];
int ans;

int calc() {
	int res = 0;

	for (int i = 1; i <= K; i++) {
		priority_queue<int> pq;
		//printf("%d번 상담의 상담사 수: %d\n", i, arr[i]);

		for (int j = 0; j < arr[i]; j++) {
			pq.push(0);
		}

		for (vector<int> curr : list[i]) {
			int start = curr[0];
			int currTop = -pq.top();

			//printf("%d번 상담, top=%d, curr=(%d, %d), 대기시간=%d\n", i, currTop, curr[0], curr[1], max(0, currTop - start));

			if (currTop > start) {
				res += currTop - start;
			}

			int endT = max(currTop, start) + curr[1];
			pq.pop();
			pq.push(-endT);
		}
	}

	return res;
}
void dfs(int left, int kind) {
	if (kind == K) {
		if (left == 0) return;

		arr[K] = left;

		int res = calc();
		if (res < ans) ans = res;

		return;
	}

	for (int i = 1; i <= left; i++) {
		arr[kind] = i;
		dfs(left - i, kind + 1);
		arr[kind] = -1;
	}

	return;
}
int solution(int k, int n, vector<vector<int>> reqs) {
	K = k; N = n;

	for (vector<int> req : reqs) {
		list[req[2]].push_back(req);
	}

	ans = 30000000;
	dfs(N, 1);

	return ans;
}