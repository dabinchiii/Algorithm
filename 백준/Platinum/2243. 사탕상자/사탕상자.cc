#include <iostream>

#define MAX_T (1 << 20)
#define MAX_T2 (1 << 21)

using namespace std;

int tree[MAX_T2];

void putCandy(int t, int dc){
    int i = t - 1;
    tree[i += MAX_T] += dc;
    while(i>>=1) tree[i] = tree[i<<1] + tree[i<<1 | 1];
    return;
}
int findCandy(int k){
    int i = 1;
    while(i < MAX_T){ // 리프가 아니라면
        if(tree[i<<1] >= k) i <<= 1;
        else{
            k -= tree[i<<1];
            i = i<<1 | 1;
        }
    }
    
    int res = i - MAX_T + 1;
    
    --tree[i];
    while(i>>=1) tree[i] = tree[i<<1] + tree[i<<1 | 1];
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b, c;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        
        if(a == 1){
            cout << findCandy(b) << '\n';
        }
        else{
            cin >> c;
            putCandy(b, c);
        }
    }
    
    return 0;
}
