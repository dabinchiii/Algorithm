#include <bits/stdc++.h>
#define MAX_F 200000

using namespace std;

unordered_map<string, int> m;
int parent[MAX_F + 3];
int cntFriend[MAX_F + 3];

int getId(string name){
    if(m.count(name) == 0) m[name] = m.size() + 1;

    return m[name];
}

int findParent(int x){
    if(parent[x] == x) return x;
    return parent[x] = findParent(parent[x]);
}
void makeUnion(int x, int y){
    x = findParent(x);
    y = findParent(y);

    if(x == y) return;

    parent[y] = x;
    cntFriend[x] += cntFriend[y];
}

void solve(){
    m.clear();
    for(int i=0; i<=MAX_F + 2; i++){
        parent[i] = i;
        cntFriend[i] = 1;
    }

    int f;
    cin >> f;

    string name1, name2;
    int id1, id2, parent1, parent2;
    for(int i=0; i<f; i++){
        cin >> name1 >> name2;

        id1 = getId(name1);
        id2 = getId(name2);

        makeUnion(id1, id2);

        parent1 = findParent(id1);
        parent2 = findParent(id2);

        cout << max(cntFriend[parent1], cntFriend[parent2]) << '\n';
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        solve();
    }

    return 0;
}
