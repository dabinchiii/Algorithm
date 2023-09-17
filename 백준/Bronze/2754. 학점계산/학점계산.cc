#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string credit;
    cin >> credit;

    double score = 0;
    if(credit != "F"){
        score += 'E' - credit[0];

        if(credit[1] != '0')
            score += (credit[1]=='+' ? 0.3 : -0.3);
    }

    cout << fixed;
    cout.precision(1);

    cout << score;

    return 0;
}
