#include <iostream>

#define MAX_N 100000

using namespace std;

int N, K;
int arr[MAX_N];
int tree[2 * MAX_N];

char signCh[] = {'-', '0', '+'};

void makeTree(){
    for(int i=0; i<N; i++) tree[N + i] = arr[i];
    for(int i=N-1; i>0; i--) tree[i] = tree[i << 1] * tree[i << 1 | 1];
    return;
}
void update(int i, int x){
    tree[i += N] = x;
    while(i >>= 1) tree[i] = tree[i << 1] * tree[i << 1 | 1];
    return;
}
char query(int l, int r){ // [l, r)
    int result = 1;
    for(l += N, r += N; l != r; l >>= 1, r >>= 1){
        if(l & 1) result *= tree[l++];
        if(r & 1) result *= tree[--r];
    }
    return signCh[result + 1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while(cin >> N >> K){
        for(int i=0; i<N; i++){
            cin >> arr[i];
            if(arr[i] > 0) arr[i] = 1;
            else if(arr[i] < 0) arr[i] = -1;
        }
        
        makeTree();
        
        char comm;
        int a, b;
        for(int i=0; i<K; i++){
            cin >> comm >> a >> b;
            --a;
            if(comm == 'C'){
                if(b > 0) b = 1;
                else if(b < 0) b = -1;
                update(a, b);
            }
            else{
                cout << query(a, b);
            }
        }
        cout << '\n';
    }
    
    return 0;
}
