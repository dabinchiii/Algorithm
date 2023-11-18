#include <iostream>
#include <string>

using namespace std;

int cntClap(int num) {
	int cnt = 0;
	while (num > 0) {
		int mod = num % 10;
		if (mod == 3 || mod == 6 || mod == 9) {
			cnt++;
		}
		num /= 10;
	}
	return cnt;
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int cnt = cntClap(i);

		if (cnt == 0) cout << i;
		else {
			for (int j = 0; j < cnt; j++) {
				cout << '-';
			}
		}
		cout << ' ';
	}

	return 0;
}