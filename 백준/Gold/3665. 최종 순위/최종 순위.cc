#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>

#define MAX_N 500

using namespace std;

int N, M;
int ans[MAX_N + 1];

bool g[MAX_N + 1][MAX_N + 1]; // 인접 행렬

bool solve() {
    vector<int> inDegree(N + 1, 0); // 진입 차수
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (g[i][j]) inDegree[j]++;
        }
    }
    
    int cnt = 0;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0) q.push(i);
    }

    while (!q.empty()) {
        if (q.size() > 1) return false; // 진입차수가 0인 정점이 여러 개다

        int curr = q.front();
        q.pop();

        ans[cnt++] = curr;

        for (int nxt = 1; nxt <= N; nxt++) {
            if (!g[curr][nxt]) continue;

            inDegree[nxt]--; // curr->nxt 연결 끊음
            if (inDegree[nxt] == 0) {
                q.push(nxt);
            }
        }
    }
    
    if (cnt != N) return false;
    return true;
}

void init() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            g[i][j] = false;
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N;

        init();

        vector<int> prevRank(N + 1);
        for (int i = 1; i <= N; i++) {
            cin >> prevRank[i];
        }
        
        for (int i = 1; i <= N; i++) {
            for (int j = i + 1; j <= N; j++) {
                g[prevRank[i]][prevRank[j]] = true; // 등수높 -> 등수낮 간선 생성
            }
        }

        cin >> M;

        int a, b;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            swap(g[a][b], g[b][a]);
        }

        bool result = solve();

        if (!result) {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        for (int i = 0; i < N; i++) cout << ans[i] << ' ';
        cout << '\n';
    }

    return 0;
}
