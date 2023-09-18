#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    map<char, int> m;
    string str;
    for(int i=0; i<n; i++){
        cin >> str;
        m[str[0]]++;
    }

    vector<char> Answer;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second >= 5){
            Answer.push_back(it->first);
        }
    }

    sort(Answer.begin(), Answer.end());

    if(Answer.empty()){
        cout << "PREDAJA";
    }
    else{
        for(int i=0; i<Answer.size(); i++){
            cout << Answer[i];
        }
    }


    return 0;
}
