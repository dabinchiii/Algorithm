#include <bits/stdc++.h>

using namespace std;

bool comp(const string &a, const string &b){
    if(a.length() != b.length()) return a.length() < b.length();
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<string> arr;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        str.push_back(' ');

        int start = 0;
        for(int j=0; j<str.length(); j++){
            if(str[j] < '0' || str[j] > '9'){
                if(start == j){
                    start = j + 1;
                    continue;
                }

                string numStr = str.substr(start, j - start);

                int nonZero = 0;
                while(numStr[nonZero] == '0') nonZero++;
                numStr = numStr.substr(nonZero);
                if(numStr.length() == 0) numStr = "0";

                arr.push_back(numStr);
                start = j + 1;
            }
        }
    }

    sort(arr.begin(), arr.end(), comp);

    for(string x : arr){
        cout << x << '\n';
    }

    return 0;
}
