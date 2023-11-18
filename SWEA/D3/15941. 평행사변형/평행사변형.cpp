#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;

		int Answer = n * n;

		cout << "#" << t << ' ' << Answer << '\n';
	}

	return 0;
}