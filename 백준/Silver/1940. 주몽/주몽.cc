#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    int Answer = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i == j) break;
            if(v[i] + v[j] == m){
                Answer++;
                break;
            }
        }
    }

    cout << Answer;

    return 0;
}
