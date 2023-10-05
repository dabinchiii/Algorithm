#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l;
    cin >> n >> l;

    vector<int> fruit(n);
    for(int i=0; i<n; i++){
        cin >> fruit[i];
    }
    sort(fruit.begin(), fruit.end());

    int Answer = l;

    for(int i=0; i<n; i++){
        if(fruit[i] <= Answer){
            Answer++;
        }
        else{
            break;
        }
    }

    cout << Answer;

    return 0;
}
