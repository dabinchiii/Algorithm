#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    priority_queue<int> q;

    int a;
    for(int i=0; i<n; i++){
        cin >> a;

        if(a == 0){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else{
            int present;
            for(int j=0; j<a; j++){
                cin >> present;
                q.push(present);
            }
        }
    }

    return 0;
}
