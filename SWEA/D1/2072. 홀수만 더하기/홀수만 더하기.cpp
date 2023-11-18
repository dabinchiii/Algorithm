#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int sum = 0;

		int num;
		for (int i = 0; i < 10; i++) {
			cin >> num;
			sum += (num % 2 ? num : 0);
		}

		cout << "#" << t << ' ' << sum << '\n';
	}

	return 0;
}