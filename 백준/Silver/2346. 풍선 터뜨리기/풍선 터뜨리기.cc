#include <bits/stdc++.h>
using namespace std;




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    deque<pair<int, int>> dq;
    int num;
    for(int i=1; i<=n; i++){
        cin >> num;
        dq.push_back({i, num});
    }

    while(!dq.empty()){
        int currIdx = dq.front().first;
        int currNum = dq.front().second;
        dq.pop_front();

        cout << currIdx << ' ';

        if(currNum > 0){
            for(int i=0; i<currNum - 1; i++){
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else{
            for(int i=0; i< -currNum; i++){
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    return 0;
}
