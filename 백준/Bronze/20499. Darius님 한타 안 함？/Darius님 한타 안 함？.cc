#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, d, a;
    scanf("%d/%d/%d", &k, &d, &a);
    cout << ((k + a < d || d == 0) ? "hasu" : "gosu");

    return 0;
}
