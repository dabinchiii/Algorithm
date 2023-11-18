#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	int testNo;
	for (int t = 1; t <= T; t++) {
		cin >> testNo;

		vector<int> cnt(100 + 1, 0);

		int score;
		for (int i = 0; i < 1000; i++) {
			cin >> score;
			cnt[score]++;
		}

		int Answer = -1;
		int maxValue = -1;

		for (int i = 0; i <= 100; i++) {
			if (cnt[i] >= maxValue) {
				maxValue = cnt[i];
				Answer = i;
			}
		}
		cout << "#" << t << ' ' << Answer << '\n';
	}

	return 0;
}