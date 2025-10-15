#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, K;
string arrFront[10000], arrBack[10000];
int ans = 0;

void calc() {
	ans = 2 * K;
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < K; j++) {
			if (arrFront[i][j] == arrFront[i - 1][j]) continue;
			ans += K - j;
			break;
		}
		for (int j = 0; j < K; j++) {
			if (arrBack[i][j] == arrBack[i - 1][j]) continue;
			ans += K - j;
			break;
		}
	}
	
	return;
}
int main() {
	cin >> N >> K;

	string str;
	for (int i = 0; i < N; i++) {
		cin >> str;
		arrFront[i] = str.substr(0, K);
		arrBack[i] = str.substr(K);
		reverse(arrBack[i].begin(), arrBack[i].end());
	}
	sort(arrFront, arrFront + N);
	sort(arrBack, arrBack + N);

	calc();

	cout << ans;

	return 0;
}