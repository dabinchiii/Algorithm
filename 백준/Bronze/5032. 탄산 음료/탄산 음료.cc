#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int e, f, c;
    cin >> e >> f >> c;

    int cnt = e + f, Answer = 0;
    while(cnt >= c){
        Answer += cnt / c;
        cnt = cnt % c + cnt / c;
    }
    cout << Answer;

    return 0;
}
