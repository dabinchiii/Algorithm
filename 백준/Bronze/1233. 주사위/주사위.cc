#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    map<int, int> m;
    for(int i=1; i<=s1; i++){
        for(int j=1; j<=s2; j++){
            for(int k=1; k<=s3; k++){
                m[i+j+k]++;
            }
        }
    }

    int maxValue = -1;
    vector<int> Answer;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second > maxValue){
            maxValue = it->second;
            Answer.clear();
        }
        if(it->second == maxValue){
            Answer.push_back(it->first);
        }
    }

    sort(Answer.begin(), Answer.end());
    cout << Answer[0];

    return 0;
}
