#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for(int i=1; i<=n; i++){
        vector<long long int> side(3);
        for(int j=0; j<3; j++){
            cin >> side[j];
            side[j] *= side[j];
        }

        sort(side.begin(), side.end());

        bool Answer = (side[0] + side[1] == side[2]);

        cout << "Scenario #" << i << ":\n";
        cout << (Answer ? "yes" : "no") << "\n\n";
    }

    return 0;
}
