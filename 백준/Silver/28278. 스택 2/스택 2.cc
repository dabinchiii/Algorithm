#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    stack<int> st;

    int command, x;
    for(int i=0; i<n; i++){
        cin >> command;

        switch(command){
        case 1:
            cin >> x;
            st.push(x);
            break;
        case 2:
            if(!st.empty()){
                cout << st.top() << '\n';
                st.pop();
            }
            else{
                cout << -1 << '\n';
            }
            break;
        case 3:
            cout << st.size() << '\n';
            break;
        case 4:
            cout << (st.empty() ? 1 : 0) << '\n';
            break;
        case 5:
            cout << (!st.empty() ? st.top() : -1) << '\n';
            break;
        }

    }

    return 0;
}
