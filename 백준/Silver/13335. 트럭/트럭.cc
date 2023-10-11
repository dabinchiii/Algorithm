#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, w, l;
    cin >> n >> w >> l;

    vector<int> truck(n);
    for(int i=0; i<n; i++){
        cin >> truck[i];
    }

    int Answer = 0;
    list<int> bridge;
    int currW = 0;

    int i = 0;
    while(i < n){
        Answer++;
        if(bridge.size() == w){
            currW -= bridge.front();
            bridge.pop_front();
        }

        if(currW + truck[i] <= l){
            bridge.push_back(truck[i]);
            currW += truck[i];
            i++;
        }
        else{
            bridge.push_back(0);
        }
    }
    Answer += w; // 마지막 트럭이 통과하는 시간

    cout << Answer;

    return 0;
}
