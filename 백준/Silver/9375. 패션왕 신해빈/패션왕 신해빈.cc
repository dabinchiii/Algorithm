#include <iostream>
#include <map>

using namespace std;

void solve(){
    map<string, int> m;
    int n;
    cin >> n;
    
    string a, b;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        m[b]++;
    }
    
    int ans = 1;
    
    for(pair<string, int> curr : m){
        ans *= curr.second + 1;
    }
    ans -= 1;
    
    cout << ans << '\n';
    
    return;
}
int main(){
    int T;
    cin >> T;
    for(int t=0; t<T; t++) solve();
    
    return 0;
}
