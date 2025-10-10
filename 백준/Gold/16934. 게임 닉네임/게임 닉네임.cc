#include <iostream>
#include <string>

using namespace std;

int N;

struct TrieNode {
	int finish;
	TrieNode *node[26];

	TrieNode() {
		finish = 0;
		for (int i = 0; i < 26; i++) node[i] = NULL;
	}
	~TrieNode() {
		for (int i = 0; i < 26; i++) {
			if (node[i]) delete node[i];
		}
	}

	void insert(string &str, int idx, string *alias) {
		if (idx == str.size()) {
			++finish;

			if (alias->size() == 0) {
				if (finish == 1) *alias = str;
				else *alias = str + to_string(finish);
			}

			return;
		}

		int curr = str[idx] - 'a';
		if (node[curr] == NULL) {
			node[curr] = new TrieNode();
			
			if(alias->size() == 0) *alias = str.substr(0, idx + 1);
		}

		node[curr]->insert(str, idx + 1, alias);

		return;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	TrieNode root;
	string nickname, alias;
	for (int i = 0; i < N; i++) {
		cin >> nickname;

		alias = "";
		root.insert(nickname, 0, &alias);

		cout << alias << '\n';
	}

	return 0;
}