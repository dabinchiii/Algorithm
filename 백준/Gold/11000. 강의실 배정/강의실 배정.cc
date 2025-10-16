#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N;
vector<pair<int, int>> arr;

int main() {
	cin >> N;
	int s, t;
	for (int i = 0; i < N; i++) {
		cin >> s >> t;
		arr.push_back({ s, t });
	}
	sort(arr.begin(), arr.end()); // s 기준 오름차순 정렬

	priority_queue<int> pq; // min heap
	pq.push(-arr[0].second);
	for (int i = 1; i < N; i++) {
		if (-pq.top() <= arr[i].first) {
			pq.pop();
		}
		pq.push(-arr[i].second);
	}

	cout << pq.size();

	return 0;
}