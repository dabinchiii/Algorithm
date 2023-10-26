#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    deque<int> dq;

    cin >> n;

    int command, x;
    for(int i=0; i<n; i++){
        cin >> command;

        switch(command){
        case 1: // 정수 X를 덱의 앞에 넣는다.
            cin >> x;
            dq.push_front(x);
            break;
        case 2: // 정수 X를 덱의 뒤에 넣는다.
            cin >> x;
            dq.push_back(x);
            break;
        case 3: // 덱에 정수가 있다면 맨 앞의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
            if(!dq.empty()){
                cout << dq.front() << '\n';
                dq.pop_front();
            }
            else cout << -1 << '\n';
            break;
        case 4: // 덱에 정수가 있다면 맨 뒤의 정수를 빼고 출력한다. 없다면 -1을 대신 출력한다.
            if(!dq.empty()){
                cout << dq.back() << '\n';
                dq.pop_back();
            }
            else cout << -1 << '\n';
            break;
        case 5: // 덱에 들어있는 정수의 개수를 출력한다.
            cout << (int)dq.size() << '\n';
            break;
        case 6: // 덱이 비어있으면 1, 아니면 0을 출력한다.
            cout << (dq.empty() ? 1 : 0) << '\n';
            break;
        case 7: // 덱에 정수가 있다면 맨 앞의 정수를 출력한다. 없다면 -1을 대신 출력한다.
            cout << (!dq.empty() ? dq.front() : -1) << '\n';
            break;
        case 8: // 덱에 정수가 있다면 맨 뒤의 정수를 출력한다. 없다면 -1을 대신 출력한다.
            cout << (!dq.empty() ? dq.back() : -1) << '\n';
            break;

        }
    }

    return 0;
}
