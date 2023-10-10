#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    list<int> lt;
    for(int i=1; i<=n; i++){
        lt.push_back(i);
    }

    list<int> Answer;
    while(!lt.empty()){
        Answer.push_back(lt.front());
        lt.pop_front();
        lt.push_back(lt.front());
        lt.pop_front();
    }

    for(int x: Answer){
        cout << x << ' ';
    }

    return 0;
}
