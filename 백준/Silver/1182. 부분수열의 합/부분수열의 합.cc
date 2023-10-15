#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> arr(20);
vector<bool> visited(20, false);
int currSum, Answer;

void f(int depth){

    if(depth == n){
        if(currSum == s) Answer++;
        return;
    }

    f(depth + 1);

    visited[depth] = true;
    currSum += arr[depth];
    f(depth + 1);
    currSum -= arr[depth];
    visited[depth] = false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    f(0);

    if(s == 0) Answer -= 1;

    cout << Answer;

    return 0;
}
