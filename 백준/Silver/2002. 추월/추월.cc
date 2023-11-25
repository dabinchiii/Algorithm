#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<string, int> m;
    string carNum;
    for(int i=0; i<n; i++){
        cin >> carNum;
        m[carNum] = i;
    }

    int Answer = 0;
    vector<bool> visited(n, false);
    for(int i=0; i<n; i++){
        cin >> carNum;

        int order = m[carNum];
        visited[order] = true;

        for(int j=0; j<order; j++){
            if(!visited[j]){
                Answer++;
                break;
            }
        }
    }

    cout << Answer;

    return 0;
}
