#include <bits/stdc++.h>
#define MAX_N 20

using namespace std;

int n;
int s[MAX_N][MAX_N];
bool visited[MAX_N];
int ans = 40000000;

void bt(int cnt, int start){
    if(cnt == n / 2){
        vector<int> team1, team2;
        for(int i=0; i<n; i++){
            if(visited[i]) team1.push_back(i);
            else team2.push_back(i);
        }

        int power1 = 0, power2 = 0;
        for(int i=0; i<n/2 - 1; i++){
            for(int j=i + 1; j<n/2; j++){
                power1 += s[team1[i]][team1[j]] + s[team1[j]][team1[i]];
                power2 += s[team2[i]][team2[j]] + s[team2[j]][team2[i]];
            }
        }

        ans = min(ans, abs(power1 - power2));

        return;
    }

    for(int i=start; i<n; i++){
        if(visited[i]) continue;

        visited[i] = true;
        bt(cnt + 1, i + 1);
        visited[i] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }

    bt(0, 0);

    cout << ans;

    return 0;
}
