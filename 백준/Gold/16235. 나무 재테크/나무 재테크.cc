#include <bits/stdc++.h>

using namespace std;

int n, m, k;
int a[10][10];
int nutrient[10][10];
vector<int> tree[10][10];
int ans;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void springSummer(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int newNutr = 0;
            vector<int> v;

            sort(tree[i][j].begin(), tree[i][j].end());

            for(int currAge : tree[i][j]){
                if(nutrient[i][j] < currAge){
                    newNutr += currAge / 2;
                    continue;
                }

                nutrient[i][j] -= currAge;
                v.push_back(currAge + 1);
            }

            tree[i][j] = v;

            nutrient[i][j] += newNutr;
        }
    }

    return;
}

void autumn(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int curr : tree[i][j]){
                if(curr % 5) continue;

                for(int u=0; u<8; u++){
                    int nxtX = i + dx[u];
                    int nxtY = j + dy[u];

                    if(nxtX < 0 || nxtX >= n) continue;
                    if(nxtY < 0 || nxtY >= n) continue;

                    tree[nxtX][nxtY].push_back(1);
                }
            }
        }
    }

    return;
}

void winter(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            nutrient[i][j] += a[i][j];
        }
    }

    return;
}

void solve(){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            nutrient[i][j] = 5;
        }
    }

    for(int t=0; t<k; t++){
        springSummer();
        autumn();
        winter();
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += tree[i][j].size();
        }
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
        }
    }

    int x, y, z;
    for(int i=0; i<m; i++){
        cin >> x >> y >> z;
        x--; y--;
        tree[x][y].push_back(z);
    }

    solve();

    cout << ans;

    return 0;
}
