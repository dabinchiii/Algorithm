#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    priority_queue<long long> q;

    int num;
    for(int i=0; i<n; i++){
        cin >> num;
        q.push(-num);
    }

    for(int i=0; i<m; i++){
        long long sum = q.top();
        q.pop();
        sum += q.top();
        q.pop();
        q.push(sum);
        q.push(sum);
    }

    long long Answer = 0;
    while(!q.empty()){
        Answer += -q.top();
        q.pop();
    }

    cout << Answer;

    return 0;
}
