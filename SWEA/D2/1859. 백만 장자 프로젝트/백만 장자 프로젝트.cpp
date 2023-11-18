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

		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		long long Answer = 0;
		
		arr.push_back(-1);
		int currMax = arr[n];
		for (int i = n - 1; i >= 0; i--) {
			if (currMax < arr[i]) {
				currMax = arr[i];
			}
			else {
				Answer += currMax - arr[i];
			}
		}



		cout << "#" << t << ' ' << Answer << '\n';
	}

	return 0;
}