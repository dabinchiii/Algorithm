#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct TrieNode {
	int depth;
	map<string, TrieNode *> child;

	TrieNode() {
		depth = -1;
	}
	~TrieNode() { // 소멸자
		// todo
	}

	void insert(vector<string> &tokens, int idx) {
		if (idx == tokens.size()) {

			return;
		}

		string token = tokens[idx];
		auto pos = child.find(token);
		if (pos == child.end()) { // 아직 없다
			TrieNode *newNode = new TrieNode();
			newNode->depth = depth + 1;

			child[token] = newNode;
		}
		
		child[token]->insert(tokens, idx + 1);
		
		return;
	}

	void print() {
		
		for (auto curr : child) {
			

			int cnt = 2 * curr.second->depth;

			string res = "";
			for (int i = 0; i < cnt; i++) res += '-';
			res += curr.first;

			cout << res << '\n';

			curr.second->print();
		}

		return;
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	TrieNode root;
	root.depth = -1;

	int N, K;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K;
		
		vector<string> tokens;
		for (int j = 0; j < K; j++) {
			cin >> str;
			tokens.push_back(str);
		}

		root.insert(tokens, 0);
	}

	root.print();

	return 0;
}