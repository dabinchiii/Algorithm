#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    bitset<32> origin(n), comp(-n);
    int Answer = (origin ^ comp).count();
    cout << Answer;

    return 0;
}
