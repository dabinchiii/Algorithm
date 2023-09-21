#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    bool flag = false;
    int Answer = -1;
    while(!flag && n > 0){
        int curr = n;

        while(curr > 0){
            if(curr % 10 != 4 && curr % 10 != 7) break;
            curr /= 10;

            if(curr == 0){
                flag = true;
                Answer = n;
            }
        }

        n--;
    }

    cout << Answer;

    return 0;
}
