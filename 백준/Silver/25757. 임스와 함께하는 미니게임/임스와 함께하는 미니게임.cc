#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    char game_type;
    cin >> n >> game_type;

    int leastNum;
    if(game_type == 'Y') leastNum = 1;
    else if(game_type == 'F') leastNum = 2;
    else leastNum = 3;

    set<string> players;
    string player;
    for(int i=0; i<n; i++){
        cin >> player;
        players.insert(player);
    }

    cout << (int)players.size() / leastNum;

    return 0;
}
