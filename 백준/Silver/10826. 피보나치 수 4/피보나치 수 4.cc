#include <bits/stdc++.h>
#define MAX_N 10000

using namespace std;

string dp[MAX_N + 1];

void add(int pos, string a, string b){
    while(a.length() < b.length()) a.push_back('0');
    while(a.length() > b.length()) b.push_back('0');

    string result = "";
    int curr, carry = 0, value;
    for(int i=0; i<a.length(); i++){
        curr = carry + (a[i] - '0') + (b[i] - '0');
        carry = curr / 10;
        value = curr % 10;

        char ch = '0' + value;
        result.push_back(ch);
    }

    if(carry) result.push_back('1');

    dp[pos] = result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;


    dp[0] = "0";
    dp[1] = "1";
    for(int i=2; i<=n; i++){
        add(i, dp[i-1], dp[i-2]);
    }

    string Answer = dp[n];
    reverse(Answer.begin(), Answer.end());

    cout << Answer;

    return 0;
}
