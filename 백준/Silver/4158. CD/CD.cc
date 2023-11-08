#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    vector<int> sg(MAX), sy(MAX);
    while(true){
        cin >> n >> m;
        if(n == 0 && m == 0) break;

        for(int i=0; i<n; i++){
            cin >> sg[i];
        }
        for(int i=0; i<m; i++){
            cin >> sy[i];
        }

        int Answer = 0;
        int idxSg = 0, idxSy = 0;
        while(idxSg < n && idxSy < m){
            if(sg[idxSg] > sy[idxSy]){
                idxSy++;
            }
            else if(sg[idxSg] < sy[idxSy]){
                idxSg++;
            }
            else{
                Answer++;
                idxSg++;
                idxSy++;
            }
        }

        cout << Answer << '\n';
    }
    return 0;
}
