#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(true){
        vector<int> side(3);
        for(int i=0; i<3; i++){
            cin >> side[i];
        }

        if(side[2] + side[1] + side[0] == 0) break;

        sort(side.begin(), side.end());

        string Answer = "";

        if(side[0] + side[1] <= side[2]){
            Answer = "Invalid";
        }
        else if(side[0] == side[2]){
            Answer = "Equilateral";
        }
        else if(side[0] == side[1] || side[1] == side[2]){
            Answer = "Isosceles";
        }
        else{
            Answer = "Scalene";
        }

        cout << Answer << '\n';
    }

    return 0;
}
