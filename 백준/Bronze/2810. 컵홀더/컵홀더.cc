#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string str;
    cin >> str;

    int holder = n + 1;
    for(int i=0; i<n; i++){
        if(str[i] == 'L'){
            holder--;
            i++;
        }
    }

    int Answer = min(holder, n);
    cout << Answer;

    return 0;
}
