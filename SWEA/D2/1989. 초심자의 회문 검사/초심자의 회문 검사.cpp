#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
	int len = (int)s.length();
	for (int i = 0; i < len / 2; i++) {
		if (s[i] != s[len - i - 1]) return false;
	}
	return true;
}
int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;

		bool Answer = isPalindrome(s);

		cout << "#" << t << ' ' << (Answer ? 1 : 0) << '\n';
	}

	return 0;
}