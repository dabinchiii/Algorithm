#include <bits/stdc++.h>
using namespace std;

double convert(string credit){
    double result = 0.0;

    if(credit == "F")
        return result;

    result += 'E' - credit[0];
    if(credit[1] == '+') result += 0.5;

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string subject, credit;
    double weight;
    double sum = 0.0;
    int cnt = 0;

    for(int i=0; i<20; i++){
        cin >> subject >> weight >> credit;

        if(credit == "P") continue;

        cnt += weight;
        sum += weight * convert(credit);
    }
    cout << fixed;
    cout.precision(6);
    cout << sum / (double)cnt;

    return 0;
}
