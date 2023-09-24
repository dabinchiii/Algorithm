#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<int> s;
    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        s.insert(num);
    }
    for(int i=0; i<m; i++){
        cin >> num;
        auto it = s.find(num);
        if(it != s.end()){
            s.erase(it);
        }
        else{
            s.insert(num);
        }
    }

    int Answer = s.size();
    cout << Answer;

    return 0;
}
