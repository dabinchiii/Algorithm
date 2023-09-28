#include <bits/stdc++.h>

using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second < b.second;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, l;
    cin >> k >> l;

    map<string, int> m;

    string num;
    for(int i=0; i<l; i++){
        cin >> num;
        m[num] = i;
    }

    vector<pair<string, int>> v;
    for(auto it : m){
        v.push_back({it.first, it.second});
    }
    sort(v.begin(), v.end(), comp);

    for(int i=0; i<min(k, (int)v.size()); i++){
        cout << v[i].first << '\n';
    }

    return 0;
}
