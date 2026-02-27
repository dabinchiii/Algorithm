#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> pos, neg;
bool hasZero;
long long ans;

void solve() {
	sort(pos.begin(), pos.end(), greater<int>());
	sort(neg.begin(), neg.end());

	int lenPos = (int)pos.size(), lenNeg = (int)neg.size();

	for (int i = 0; i + 1< lenPos; i += 2) {
		if (pos[i] == 1 || pos[i + 1] == 1) ans += pos[i] + pos[i + 1];
		else ans += pos[i] * pos[i + 1];
	}
	if (lenPos % 2) ans += pos[lenPos - 1];

	for (int i = 0; i + 1< lenNeg; i += 2) {
		ans += neg[i] * neg[i + 1];
	}
	if (lenNeg % 2 && !hasZero) ans += neg[lenNeg - 1];

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num == 0) hasZero = true;
		else if (num > 0) pos.push_back(num);
		else neg.push_back(num);
	}

	solve();

	cout << ans;

	return 0;
}