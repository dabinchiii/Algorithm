#include <bits/stdc++.h>
using namespace std;

bool comp(pair<string, int> a, pair<string, int> b){
    if(a.second != b.second)
        return a.second > b.second;
    if(a.first.length() != b.first.length())
        return a.first.length() > b.first.length();
    return a < b;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, int> cnt;
    string word;
    for(int i=0; i<n; i++){
        cin >> word;
        if(word.length() < m) continue;
        cnt[word]++;
    }

    vector<pair<string, int>> v;
    for(auto it=cnt.begin(); it!=cnt.end(); it++){
        v.push_back({it->first, it->second});
    }

    sort(v.begin(), v.end(), comp);

    for(auto it=v.begin(); it!=v.end(); it++){
        cout << it->first << '\n';
    }

    return 0;
}
