#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct TrieNode {
	int depth;
	map<string, TrieNode *> child;

	void insert(vector<string> &tokens, int idx) {
		if (idx == tokens.size()) {
			return;
		}

		string token = tokens[idx];
		auto it = child.find(token);
		
		if (it == child.end()) { // 없다
			TrieNode *newNode = new TrieNode();
			newNode->depth = depth + 1;

			child[token] = newNode;
		}

		child[token]->insert(tokens, idx + 1);
	}

	void print() {
		for (auto curr : child) {
			string res = "";
			for (int i = 0; i < depth; i++) res += ' ';
			res += curr.first;

			cout << res << '\n';

			curr.second->print();
		}
	}
};
vector<string> split(string path) {
	vector<string> tokens;
	
	path += '\\';
	int len = (int)path.size();
	int start = 0;
	for (int i = 0; i < len; i++) {
		if (path[i] == '\\') {
			tokens.push_back(path.substr(start, i - start));
			start = i + 1;
		}
	}

	return tokens;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	TrieNode root;
	root.depth = 0;

	string path;
	for (int i = 0; i < N; i++) {
		cin >> path;
		vector<string> tokens = split(path);
		
		root.insert(tokens, 0);
	}

	root.print();

	return 0;
}