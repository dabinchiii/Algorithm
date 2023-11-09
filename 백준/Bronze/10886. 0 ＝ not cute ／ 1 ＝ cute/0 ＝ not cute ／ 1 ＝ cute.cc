#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int result[2] = {0, 0};
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        result[num]++;
    }

    if(result[0] > result[1]) cout << "Junhee is not cute!";
    else cout << "Junhee is cute!";

    return 0;
}
