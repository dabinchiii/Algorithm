#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int Answer = 0;
    int tap;
    for(int i=0; i<n; i++){
        cin >> tap;
        Answer += tap;
    }
    Answer -= n - 1;

    cout << Answer;

    return 0;
}
