#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

int N, M, K;
ll arr[1000000];
ll *tree;

ll makeTree(int treeIdx, int start, int end){
    if(start == end){ // 리프 노드
        return tree[treeIdx] = arr[start];
    }
    
    int mid = (start + end) / 2;
    ll leftRes = makeTree(treeIdx * 2, start, mid);
    ll rightRes = makeTree(treeIdx * 2 + 1, mid + 1, end);
    
    return tree[treeIdx] = leftRes + rightRes;
}
void update(int treeIdx, int start, int end, int idx, ll diff){
    if(start > idx || end < idx) return; // 완전 벗어난 범위. start~end에 idx가 포함되지 않음
    
    // 어쨋든 범위 내에 있는 거라면, 영향을 받아서 sum이 diff만큼 증가한다.
    tree[treeIdx] += diff;
    
    if(start == end) return; // 리프 노드면 끝
    
    int mid = (start + end) / 2;
    update(treeIdx * 2, start, mid, idx, diff);
    update(treeIdx * 2 + 1, mid + 1, end, idx, diff);
    
    return;
}
ll getSum(int treeIdx, int left, int right, int start, int end){
    if(right < start || left > end){ // 완전히 범위에서 벗어남
        return 0;
    }
    
    if(start >= left && end <= right){ // 완전히 포함됨
        return tree[treeIdx];
    }
    
    int mid = (start + end) / 2;
    ll leftRes = getSum(treeIdx * 2, left, right, start, mid);
    ll rightRes = getSum(treeIdx * 2 + 1, left, right, mid + 1, end);
    
    return leftRes + rightRes;
}
int main(){
    cin >> N >> M >> K;
    int h = ceil(log2(N));
    tree = new ll[1 << (h + 1)];
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    makeTree(1, 0, N - 1);
    
    int a, b;
    ll c;
    for(int i=0; i<M + K; i++){
        cin >> a >> b >> c;
        
        if(a == 1){ // b번째 수를 c로 바꿈
            update(1, 0, N - 1, b - 1, c - arr[b - 1]);
            arr[b - 1] = c;
        }
        else{ // b번째 수부터 c번째 수의 합 출력
            cout << getSum(1, b - 1, c - 1, 0, N - 1) << '\n';
        }
    }
    
    return 0;
}
