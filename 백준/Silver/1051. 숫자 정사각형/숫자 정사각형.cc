#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    string line;
    for(int i=0; i<n; i++){
        cin >> line;
        for(int j=0; j<m; j++){
            arr[i][j] = line[j] - '0';
        }
    }

    int Answer = 1;
    for(int x1=0; x1<n; x1++){
        for(int y1=0; y1<m; y1++){
            for(int l=1; ; l++){
                int x2 = x1 + l, y2 = y1 + l;
                if(x2 >= n || y2 >= m) break;
                
                if(arr[x1][y1] != arr[x2][y2]) continue;
                if(arr[x1][y1] != arr[x1][y2]) continue;
                if(arr[x1][y1] != arr[x2][y1]) continue;

                Answer = max(Answer, (x2 - x1 + 1) * (y2 - y1 + 1));
            }
        }
    }

    cout << Answer;

    return 0;
}
