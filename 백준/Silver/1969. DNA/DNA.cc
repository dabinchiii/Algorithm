#include <bits/stdc++.h>

using namespace std;

bool comp(pair<char, int> a, pair<char, int> b){
    if(a.second != b.second) return a.second > b.second;
    return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for(int i=0; i<n; i++){
        cin >> s[i];
    }

    string AnswerDNA = "";
    int AnswerDis = 0;
    for(int i=0; i<m; i++){
        map<char, int> cnt;

        for(int j=0; j<n; j++){
            cnt[s[j][i]]++;
        }

        vector<pair<char, int>> v;
        for(auto x : cnt){
            v.push_back(x);
        }

        sort(v.begin(), v.end(), comp);

        int sum = 0;
        for(pair<char, int> x : v){
            sum += x.second;
        }

        AnswerDNA.push_back(v[0].first);
        AnswerDis += sum - v[0].second;
    }

    cout << AnswerDNA << '\n' << AnswerDis;

    return 0;
}
