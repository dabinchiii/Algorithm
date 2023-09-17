#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> arr(5);
    int maxLength = -1;
    for(int i=0; i<5; i++){
        cin >> arr[i];
        maxLength = max(maxLength, (int)arr[i].length());
    }

    string Answer = "";

    for(int i=0; i<maxLength; i++){
        for(int j=0; j<5; j++){
            if(i < arr[j].length()){
                Answer += arr[j][i];
            }
        }
    }

    cout << Answer;

    return 0;
}
