#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int angle[3];
    int sum = 0;
    for(int i=0; i<3; i++){
        cin >> angle[i];
        sum += angle[i];
    }

    string Answer = "";
    if(sum != 180) Answer = "Error";
    else{
        if(angle[0] != angle[1] && angle[1] != angle[2] && angle[2] != angle[0]){
            Answer = "Scalene";
        }
        else if(angle[0] == angle[1] && angle[1] == angle[2]){
            Answer = "Equilateral";
        }
        else{
            Answer = "Isosceles";
        }
    }

    cout << Answer;

    return 0;
}
