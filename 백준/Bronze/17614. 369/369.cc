#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int Answer = 0;
    for(int i=1; i<=n; i++){
        int curr = i;
        while(curr > 0){
            if((curr % 10) % 3 == 0 && curr % 10 != 0)
                Answer++;
            curr /= 10;
        }
    }

    cout << Answer;

    return 0;
}
