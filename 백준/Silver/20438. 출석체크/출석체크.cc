#include <iostream>
#include <queue>

using namespace std;

int n, k, q, m;
bool isDoze[5003], isChecked[5003];
int pSum[5001];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> k >> q >> m;
    
    int x;
    for(int i=0; i<k; i++){
        cin >> x;
        isDoze[x] = true;
    }
    
    for(int i=0; i<q; i++){
        cin >> x;
        
        if(isDoze[x]) continue;
        
        int curr = x;
        while(curr <= n + 2){
            if(!isDoze[curr]){
                isChecked[curr] = true;
            }
            curr += x;
        }
    }

    for(int i=3; i<=n + 2; i++){
        pSum[i] = pSum[i - 1];
        if(!isChecked[i]) pSum[i]++;
    }
    
    int s, e;
    for(int i=0; i<m; i++){
        cin >> s >> e;
        cout << pSum[e] - pSum[s - 1] << '\n';
    }
    
    return 0;
}
