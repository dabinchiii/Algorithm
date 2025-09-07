#include <iostream>
#include <cmath>
#include <algorithm>

#define INF 1000000001

using namespace std;

int N, M;
int *tree;
int arr[100000];

void makeTree(int node, int start, int end){
    if(start == end){
        tree[node] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    makeTree(2 * node, start, mid);
    makeTree(2 * node + 1, mid + 1, end);
    
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
    
    return;
}

int getMin(int node, int start, int end, int left, int right){
    if(start > right || end < left) return INF; // 범위에 아예 포함되지 X
    
    if(start >= left && end <= right) return tree[node]; // 범위에 완전히 포함됨
    
    int mid = (start + end) / 2;
    int leftMin = getMin(2 * node, start, mid, left, right);
    int rightMin = getMin(2 * node + 1, mid + 1, end, left, right);
    
    return min(leftMin, rightMin);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    int h = ceil(log2(N)) + 1;
    tree = new int[1 << h];
    
    makeTree(1, 0, N - 1);
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        cout << getMin(1, 0, N - 1, a - 1, b - 1) << '\n';
    }
    
    return 0;
}
