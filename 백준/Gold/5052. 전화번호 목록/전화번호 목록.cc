#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool ans;

struct TrieNode {
	bool finish;
	TrieNode *node[10];

	TrieNode() { // 생성자
		finish = false;
		for (int i = 0; i < 10; i++) node[i] = NULL;
	}
	~TrieNode() {
		for (int i = 0; i < 10; i++) {
			if (node[i]) delete node[i];
		}
	}

	void insert(string &str, int idx) {
		if (idx == str.size()) {
			finish = true;
			return;
		}

		int curr = str[idx] - '0';
		if (node[curr] == NULL) {
			node[curr] = new TrieNode();
		}
		else if (node[curr]->finish) { // 있으면 안되는데 있다.
			ans = false;
			return;
		}

		node[curr]->insert(str, idx + 1);

		return;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; ++tc) {
		int N;
		cin >> N;

		vector<string> arr;
		string str;
		for (int i = 0; i < N; i++) {
			cin >> str;
			arr.push_back(str);
		}

		// 짧은 것부터 넣어야 되므로
		sort(arr.begin(), arr.end());

		TrieNode root;
		ans = true;
		for (string curr : arr) {
			root.insert(curr, 0);
			if (!ans) break;
		}

		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}