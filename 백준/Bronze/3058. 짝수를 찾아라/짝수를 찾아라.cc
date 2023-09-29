#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int sum = 0, minNum = 101;
        int num;
        for(int i=0; i<7; i++){
            cin >> num;
            if(num % 2 == 0){
                sum += num;
                minNum = min(minNum, num);
            }
        }

        cout << sum << ' ' << minNum << '\n';
    }

    return 0;
}
