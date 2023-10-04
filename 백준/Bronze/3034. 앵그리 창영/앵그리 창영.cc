#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, h;
    cin >> n >> w >> h;

    int maxLen = sqrt(w*w + h*h);
    int match;
    for(int i=0; i<n; i++){
        cin >> match;
        cout << (match <= maxLen ? "DA" : "NE") << '\n';
    }

    return 0;
}
