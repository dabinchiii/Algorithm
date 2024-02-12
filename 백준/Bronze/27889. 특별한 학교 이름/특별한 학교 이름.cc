#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string, string> m;

    m["NLCS"] = "North London Collegiate School";
    m["BHA"] = "Branksome Hall Asia";
    m["KIS"] = "Korea International School";
    m["SJA"] = "St. Johnsbury Academy";

    string str;
    cin >> str;
    cout << m[str];

    return 0;
}
