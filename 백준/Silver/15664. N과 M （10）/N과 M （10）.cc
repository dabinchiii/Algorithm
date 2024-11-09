#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m;
int num[8];
vector<int> arr(8);
bool visited[8];
set< vector<int> > s;

void dfs(int cnt, int left){
    if(cnt == m){
        if(s.find(arr) != s.end()) return;

        s.insert(arr);

        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';

        return;
    }

    for(int i=left; i<n; i++){
        if(visited[i]) continue;

        arr[cnt] = num[i];
        visited[i] = true;

        dfs(cnt + 1, i);

        visited[i] = false;
    }

    return;
}

void solve(){
    sort(num, num + n);

    dfs(0, 0);

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> num[i];

    solve();

    return 0;
}