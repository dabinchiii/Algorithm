#include <iostream>
#include <vector>

#define MAX_N 1000000

using namespace std;

int n;
int card[MAX_N + 1];
bool num[MAX_N + 1];
int score[MAX_N + 1];

void solve(){
    
    for(int i=1; i<=MAX_N; i++){
        if(!num[i]) continue;
        
        for(int j=i + i; j<=MAX_N; j+=i){
            if(!num[j]) continue;
            
            score[i]++;
            score[j]--;
        }
    }
    
    return;
}

int main(){
    cin >> n;
    
    for(int i=1; i<=n; i++){
        cin >> card[i];
        num[card[i]] = true;
    }
    
    solve();

    for(int i=1; i<=n; i++){
        cout << score[card[i]] << ' ';
    }
    
    return 0;
}
