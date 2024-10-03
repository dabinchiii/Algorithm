#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> line;
    int num;
    for(int i=1; i<=n; i++){
        cin >> num;
        line.insert(line.end() - num, i);
    }

    for(int curr : line) cout << curr << ' ';

    return 0;
}
