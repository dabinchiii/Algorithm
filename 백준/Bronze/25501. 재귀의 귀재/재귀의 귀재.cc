#include <bits/stdc++.h>

using namespace std;

int cnt;
string s;

int recursion(int l, int r){
    cnt++;
    if(l >= r) return 1;
    if(s[l] != s[r]) return 0;
    return recursion(l + 1, r - 1);
}

int isPalindrome(){
    return recursion(0, s.length() - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        cin >> s;

        cnt = 0;
        int returnValue = isPalindrome();

        cout << returnValue << ' ' << cnt << '\n';
    }
    return 0;
}
