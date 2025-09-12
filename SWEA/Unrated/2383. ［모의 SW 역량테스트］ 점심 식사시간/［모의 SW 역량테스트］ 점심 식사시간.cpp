#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
	int r, c;
	int arrivalTime; // 계단입구 도착 시간
	Person() {}
	Person(int r, int c) {
		this->r = r;
		this->c = c;
	}
};
struct sNode {
	int r, c, h;
};
bool cmp(Person &a, Person &b) {
	return a.arrivalTime < b.arrivalTime;
}

int N, ans;
int board[10][10];
//int sList[10][10]; // 계단 리스트 [r][c]=h
vector<sNode> sList;
vector<Person> pList;
int cnt;
bool selected[10]; // 사람마다 어떤 계단 배정되었는지 여부

int processDown(vector<Person> &list, int height) {
	if (list.empty()) return 0; // 사람없음

	sort(list.begin(), list.end(), cmp); // 계단 도착시간기준 오름차순 정렬

	int size = list.size() + 3;
	vector<int> D(size); // [0]: 계단 입구에 가장 빨리 도착하는 사람
	for (int i = 3; i < size; i++) {
		Person p = list[i - 3];
		if (D[i - 3] <= p.arrivalTime + 1) { // 갈 수 있는 상태
			D[i] = p.arrivalTime + 1 + height; // 도착시간 + 대기시간 + 내려가는 시간
		}
		else { // 대기해야함
			D[i] = D[i - 3] + height; // 내려가자마자
		}
	}

	return D[size - 1];
}
void makeList() {
	vector<Person> list[2];

	for (int i = 0; i < cnt; i++) {
		Person p = pList[i];
		int no = selected[i]; // 사람 i에 배정된 계단

		p.arrivalTime = abs(p.r - sList[no].r) + abs(p.c - sList[no].c);
		list[no].push_back(p);
	}

	// 각각의 계단의 사람리스트를 이용해서 내려가기 구현
	int timeA = processDown(list[0], sList[0].h); 
	int timeB = processDown(list[1], sList[1].h);
	int res = max(timeA, timeB); // 동시에 내려가니까

	ans = min(ans, res);

	return;
}
void divide(int idx) {
	if (idx == cnt) {
		makeList();
		return;
	}

	selected[idx] = 0;
	divide(idx + 1);

	selected[idx] = 1;
	divide(idx + 1);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;
	for (int tc = 1; tc <= TC; tc++) {
		cin >> N;

		pList = vector<Person>();
		sList = vector<sNode>();
		ans = 1000000000;

		int c;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> c;
				if (c == 1) pList.push_back(Person(i, j));
				else if (c > 1) sList.push_back({ i, j, c });
			}
		}

		cnt = pList.size();
		fill(selected, selected + 10, false);
		
		divide(0);

		printf("#%d %d\n", tc, ans);
	}

	return 0;
}