#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L, K, C;
vector<int> cp;
int ansLen, ansStart;

int findNext(int currIdx, int x) {
	int nxtIdx = currIdx;
	while (nxtIdx >= 0 && cp[currIdx] - cp[nxtIdx] <= x) --nxtIdx;
	return nxtIdx + 1;
}
bool check(int x) {
	int currIdx = K;

	for (int i = 0; i < C; i++) { // C번 자른다
		int nxtIdx = findNext(currIdx, x);
		
		if (currIdx == nxtIdx) return false;
		currIdx = nxtIdx;
		if (currIdx == 0) break;
	}

	if (cp[currIdx] > x) return false;

	ansLen = x;
	ansStart = cp[currIdx];

	return true;
}
int main() {
	cin >> L >> K >> C;

	int p;
	for (int i = 0; i < K; i++) {
		cin >> p;
		cp.push_back(p);
	}
	cp.push_back(L);
	sort(cp.begin(), cp.end());

	int left = 1, right = L;
	while (left <= right) {
		int mid = (left + right) / 2;

		if (check(mid)) { // 가능
			right = mid - 1;
		}
		else { // 불가능
			left = mid + 1;
		}
	}

	cout << ansLen << ' ' << ansStart;

	return 0;
}