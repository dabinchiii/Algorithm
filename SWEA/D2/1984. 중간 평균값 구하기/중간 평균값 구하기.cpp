#include <iostream>
#include <algorithm>

using namespace std;

int num[10];
double ans;

void solve(){
    for(int i=0; i<10; i++){
        cin >> num[i];
    }

    sort(num, num + 10);

    int minNum = num[0], maxNum = num[9];

    int curr = 0;
    while(curr < 10 && num[curr] == minNum){
        num[curr] = -1;
        curr++;
    }

    curr = 9;
    while(curr >= 0 && num[curr] == maxNum){
        num[curr] = -1;
        curr--;
    }

    double sum = 0.0, n = 0;
    for(int i=0; i<10; i++){
        if(num[i] == -1) continue;
        n++;
        sum += num[i];
    }

    ans = sum / n;

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    cout << fixed;
    cout.precision(0);

    for(int t=1; t<=T; t++){
        solve();
        cout << "#" << t << ' ' << ans << '\n';
    }

    return 0;
}