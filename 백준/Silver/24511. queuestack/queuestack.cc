#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    int a[100000], b[100000];
    
    cin >> n;
    
    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<n; i++) cin >> b[i];
    
    queue<int> q;
    for(int i=n-1; i>=0; i--){
        if(a[i] == 1) continue;
        q.push(b[i]);
    }
    
    cin >> m;
    
    int num;
    for(int i=0; i<m; i++){
        cin >> num;
        q.push(num);
        
        cout << q.front() << ' ';
        q.pop();
    }
    
    
    return 0;
}
