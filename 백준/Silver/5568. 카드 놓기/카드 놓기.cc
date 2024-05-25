#include <bits/stdc++.h>
#define MAX_N 10
#define MAX_K 4

using namespace std;

int n, k;
string card[MAX_N];
int seq[MAX_K];
bool visited[MAX_N];
set<string> s;

void bt(int cnt){
    if(cnt == k){
        for(int i=0; i<k; i++){
            string str = "";
            for(int j=0; j<k; j++){
                str += card[seq[(i + j) % k]];
            }
            s.insert(str);
        }

        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        seq[cnt] = i;
        visited[i] = true;
        bt(cnt + 1);
        visited[i] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<n; i++){
        cin >> card[i];
    }

    bt(0);

    cout << s.size();

    return 0;
}
