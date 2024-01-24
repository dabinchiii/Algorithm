#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int num;
        cin >> num;

        string rev = to_string(num);
        reverse(rev.begin(), rev.end());
        int revNum = stoi(rev);

        int sum = num + revNum;
        string str = to_string(sum);

        int len = str.length();
        bool Answer = true;
        for(int i=0; i<len / 2; i++){
            if(str[i] == str[len - 1 - i]) continue;
            Answer = false;
            break;
        }

        cout << (Answer ? "YES" : "NO") << '\n';
    }

    return 0;
}
