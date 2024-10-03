#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> line(n + 1, 0);
    int num;
    for(int i=1; i<=n; i++){
        cin >> num;

        int cnt = 0;
        for(int j=1; j<=n; j++){
            if(line[j] == 0) cnt++;
            if(cnt > num){
                line[j] = i;
                break;
            }
        }

    }

    for(int i=1; i<=n; i++){
        cout << line[i] << ' ';
    }

    return 0;
}
