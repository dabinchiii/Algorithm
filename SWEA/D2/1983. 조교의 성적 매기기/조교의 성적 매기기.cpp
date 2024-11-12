#include <bits/stdc++.h>

using namespace std;

int n, k;
int total[100];
string ans;

string strR[] = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};

bool compare(int a, int b){
    return a > b;
}

void solve(){
    cin >> n >> k;
    k--;

    int mid, fin, ass;
    for(int i=0; i<n; i++){
        cin >> mid >> fin >> ass;
        total[i] = mid  * 35 + fin * 45 + ass * 20;
    }

    int kScore = total[k];
    sort(total, total + n, compare);

    int r = 0;
    while(true){
        if(kScore >= total[(r + 1) * (n / 10) - 1]) break;
        r++;
    }

    ans = strR[r];

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=1; t<=T; t++){
        solve();
        cout << '#' << t << ' ' << ans << '\n';
    }

    return 0;
}
