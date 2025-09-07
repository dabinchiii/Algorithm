#include <iostream>
#include <cmath>

#define INF 1000000001

#define min(x, y) (x) < (y) ? (x) : (y)
#define max(x, y) (x) > (y) ? (x) : (y)

using namespace std;

int N, M;
int arr[100000];
int *minTree, *maxTree;

void makeTree(int node, int start, int end){
    if(start == end){ // 리프
        minTree[node] = maxTree[node] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    makeTree(2 * node, start, mid);
    makeTree(2 * node + 1, mid + 1, end);
    
    minTree[node] = min(minTree[2 * node], minTree[2 * node + 1]);
    maxTree[node] = max(maxTree[2 * node], maxTree[2 * node + 1]);
    
    return;
}

pair<int, int> getRes(int node, int left, int right, int start, int end){
    if(start > right || end < left) return {INF, 0}; // 범위에 아예 포함되지 않음
    
    if(start >= left && end <= right){ // 완전히 포함됨
        return {minTree[node], maxTree[node]};
    }
    
    int mid = (start + end) / 2;
    pair<int, int> leftRes = getRes(2 * node, left, right, start, mid);
    pair<int, int> rightRes = getRes(2 * node + 1, left, right, mid + 1, end);
    
    return {min(leftRes.first, rightRes.first), max(leftRes.second, rightRes.second)};
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int h = ceil(log2(N)) + 1;
    minTree = new int[1 << h];
    maxTree = new int[1 << h];
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    makeTree(1, 0, N - 1);
    
    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        pair<int, int> res = getRes(1, a - 1, b - 1, 0, N - 1);
        printf("%d %d\n", res.first, res.second);
    }
    return 0;
}
