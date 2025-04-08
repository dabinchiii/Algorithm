#include <iostream>

using namespace std;

int n, x, k;
bool cup[200001];
int ans;

int main(){
    cin >> n >> x >> k;
    
    cup[x] = true;
    
    int a, b;
    for(int i=0; i<k; i++){
        cin >> a >> b;
        
        if(cup[a] || cup[b]){
            swap(cup[a], cup[b]);
        }
    }
    
    for(int i=1; i<=n; i++){
        if(cup[i]){
            ans = i;
            break;
        }
    }
    
    cout << ans;
    
    return 0;
}
