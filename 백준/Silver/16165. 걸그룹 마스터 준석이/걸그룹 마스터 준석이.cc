#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    map<string, string> memberInfo;
    map<string, int> teamId;
    vector<set<string>> teamList(n);

    string teamName, member;
    int teamNum;
    for(int i=0; i<n; i++){
        cin >> teamName >> teamNum;

        teamId[teamName] = i;

        for(int j=0; j<teamNum; j++){
            cin >> member;
            memberInfo[member] = teamName;
            teamList[i].insert(member);
        }
    }

    string name;
    int quiz;
    for(int i=0; i<m; i++){
        cin >> name >> quiz;
        if(quiz){
            cout << memberInfo[name] << '\n';
        }
        else{
            for(string x : teamList[teamId[name]])
                cout << x << '\n';
        }

    }

    return 0;
}
