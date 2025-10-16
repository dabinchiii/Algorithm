#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;

int main() {
	cin >> N >> K;

	vector<int> arr(N - 1);

	int curr, prev;
	cin >> curr; // 첫 번째 원소
	for (int i = 0; i < N - 1; i++) {
		prev = curr;
		cin >> curr;
		arr[i] = curr - prev;
	}

	sort(arr.begin(), arr.end());
	
	int sum = 0;
	for (int i = N - K - 1; i >= 0; i--) {
		sum += arr[i];
	}

	cout << sum;

	return 0;
}