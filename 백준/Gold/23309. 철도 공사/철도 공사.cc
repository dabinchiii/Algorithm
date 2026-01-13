#include <iostream>

#define MAX_N 2000000

using namespace std;

int N, M;
pair<int, int> st[MAX_N + 1];
int head, tail;

void printState() {
	/*for (int i = 0; i < 10; i++) {
		printf("[%d] %d <- %d -> %d\n", i, st[i].prev, i, st[i].nxt);
	}
	cout << endl;*/
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	
	int prev = -1, curr = -1, nxt = -1;
	for (int i = 0; i < N; i++) {
		cin >> curr;
		if (i == 0) head = curr;
		st[curr].first = prev;
		prev = curr;
	}
	tail = curr;

	printState();

	curr = tail;
	while (curr != -1) {
		st[curr].second = nxt;
		nxt = curr;
		curr = st[curr].first;
	}

	st[head].first = tail;
	st[tail].second = head;

	printState();

	string comm;
	int num, target, ans;
	for (int i = 0; i < M; i++) {
		cin >> comm;
		
		printState();

		if (comm == "BN") {
			cin >> curr >> num;
			ans = nxt = st[curr].second;

			st[curr].second = num;
			st[num].first = curr;

			st[num].second = nxt;
			st[nxt].first = num;
		}
		else if (comm == "BP") {
			cin >> curr >> num;
			ans = prev = st[curr].first;

			st[prev].second = num;
			st[num].first = prev;

			st[num].second = curr;
			st[curr].first = num;
		}
		else if (comm == "CN") {
			cin >> curr;
			ans = target = st[curr].second;
			nxt = st[target].second;

			st[curr].second = nxt;
			st[nxt].first = curr;
			
			st[target].first = st[target].second = -1;
		}
		else { // CP
			cin >> curr;
			ans = target = st[curr].first;
			prev = st[target].first;

			st[curr].first = prev;
			st[prev].second = curr;
			
			st[target].first = st[target].second = -1;
		}

		cout << ans << '\n';
	}


	return 0;
}