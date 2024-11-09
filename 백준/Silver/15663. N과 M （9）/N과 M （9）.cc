#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m;
int num[8];
vector<int> arr(8);
bool visited[8];
set< vector<int> > ans;

void dfs(int cnt){
    if(cnt == m){
        if(ans.find(arr) != ans.end()) return;

        ans.insert(arr);

        for(int i=0; i<m; i++) cout << arr[i] << ' ';
        cout << '\n';

        return;
    }

    for(int i=0; i<n; i++){
        if(visited[i]) continue;

        arr[cnt] = num[i];
        visited[i] = true;
        
        dfs(cnt + 1);

        visited[i] = false;
    }

    return;
}

void solve(){
    sort(num, num + n);

    dfs(0);

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