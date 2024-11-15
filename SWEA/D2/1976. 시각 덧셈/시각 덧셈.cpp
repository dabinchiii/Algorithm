#include <iostream>

using namespace std;

int h1, m1, h2, m2;
int ansH, ansM;

void solve(){
    cin >> h1 >> m1 >> h2 >> m2;

    ansH = h1 + h2;
    ansM = m1 + m2;

    if(ansM >= 60){
        ansH += ansM / 60;
        ansM %= 60;
    }

    if(ansH >= 12){
        ansH %= 12;
    }

    if(ansH == 0) ansH += 12;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;  
    cin >> T;

    for(int t=1; t<=T; t++){
        solve();
        cout << '#' << t << ' ';
        cout << ansH << ' ' << ansM << '\n';
    }

    return 0;
}