#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int hp, mp, pow, dep;
        cin >> hp >> mp >> pow >> dep;

        int incHp, incMp, incPow, incDep;
        cin >> incHp >> incMp >> incPow >> incDep;

        hp += incHp;
        mp += incMp;
        pow += incPow;
        dep += incDep;

        int Answer = max(1, hp) + 5 * max(1, mp) + 2 * max(0, pow) + 2 * dep;
        cout << Answer << '\n';
    }

    return 0;
}
