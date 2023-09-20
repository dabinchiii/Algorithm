#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin >> m >> n;

    vector<int> square;
    int num = 1;
    while(true){
        int curr = num * num;

        if(curr > n) break;
        if(curr >= m) square.push_back(curr);

        num++;
    }

    int sum = 0;
    for(int i=0; i<square.size(); i++){
        sum += square[i];
    }

    if(square.empty()) cout << -1;
    else cout << sum << '\n' << square[0];

    return 0;
}
