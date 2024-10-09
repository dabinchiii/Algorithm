#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[200];
int ans;

int cntZero, head, tail;
bool isRobot[200];
queue<int> q;

void updateTail(){
    tail = head + n - 1;
    tail %= 2 * n;

    return;
}
void moveBelt(){
    head += -1 + 2 * n;
    head %= 2 * n;

    updateTail();

    if(!q.empty() && q.front() == tail){
        isRobot[q.front()] = false;
        q.pop();
    }

    return;
}
void moveRobots(){
    int cntRobot = q.size();

    for(int i=0; i<cntRobot; i++){
        int curr = q.front();
        q.pop();

        int nxt = (curr + 1) % (2 * n);

        if(!isRobot[nxt] && a[nxt] >= 1){
            isRobot[curr] = false;
            isRobot[nxt] = true;

            a[nxt]--;
            if(a[nxt] == 0) cntZero++;

            if(nxt != tail) q.push(nxt);
        }
        else{
            q.push(curr);
        }
    }

    return;
}
void putOnHead(){
    if(a[head] == 0) return;

    q.push(head);

    isRobot[head] = true;

    a[head]--;
    if(a[head] == 0) cntZero++;

    return;
}

void solve(){
    head = 0;
    updateTail();

    while(cntZero < k){
        moveBelt();
        moveRobots();
        putOnHead();

        ans++;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i=0; i<2 * n; i++){
        cin >> a[i];
    }

    solve();

    cout << ans;

    return 0;
}
