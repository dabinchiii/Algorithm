#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int w = 1 + (n - 1) * 4;
    int center = (n - 1) * 2;
    for(int i=-n + 1; i<n; i++){
        int d = abs(i) * 2;

        for(int j=0; j<w; j++){
            if(j >= center - d && j <= center + d) cout << '*';
            else if(j % 2 == 0) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
        if(i >= 0) d++;
        for(int j=0; j<w; j++){

            if(j > center - d && j < center + d) cout << ' ';
            else if(j % 2 == 0) cout << '*';
            else cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}
