#include <bits/stdc++.h>
#define MAX_N 10000
using namespace std;

int n;
vector<vector<int>> g(MAX_N + 1);
vector<int> visited(MAX_N + 1);
int node1, node2;
int Answer;

void init(){
    for(int i=1; i<=n; i++){
        g[i].clear();
        visited[i] = 0;
    }
    Answer = 0;
}

void mark1(int currV){
    for(int nxt : g[currV]){
        if(!visited[nxt]){
            visited[nxt] = 1;
            mark1(nxt);
        }
    }
}

void mark2(int currV){
    if(!visited[currV]){
        visited[currV] = 2;
    }
    else if(visited[currV] == 1){
        Answer = currV;
        return;
    }
    else{
        return;
    }

    for(int nxt : g[currV]){
        mark2(nxt);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int test_case=0; test_case<T; test_case++){
        cin >> n;

        init();

        int a, b;
        for(int i=0; i<n-1; i++){
            cin >> a >> b; // a가 b의 부모
            g[b].push_back(a); // 부모를 저장
        }

        cin >> node1 >> node2;

        visited[node1] = 1;
        mark1(node1);

        mark2(node2);

        cout << Answer << '\n';
    }


    return 0;
}
