#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solve(int n, string s) {
	if (n % 2) return false;

	for (int i = 0; i < n / 2; i++) {
		if (s[i] != s[n / 2 + i]) return false;
	}
	return true;
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n;
		cin >> n;

		string s;
		cin >> s;

		bool Answer = solve(n, s);

		cout << "#" << t << ' ' << (Answer ? "Yes" : "No") << '\n';
	}

	return 0;
}