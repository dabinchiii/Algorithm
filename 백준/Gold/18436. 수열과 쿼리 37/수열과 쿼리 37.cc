#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct treeNode{
    int odd, even;
    treeNode(){}
    treeNode(int odd, int even){
        this->odd = odd;
        this->even = even;
    }
};

treeNode operator+(treeNode &a, treeNode &b){
    return {a.odd + b.odd, a.even + b.even};
}

int N, M;
int arr[100001];
treeNode *tree;

void makeTree(int node, int start, int end){
    if(start == end){
        tree[node] = (arr[start] % 2 ? treeNode(1, 0) : treeNode(0, 1));
        return;
    }
    
    int mid = (start + end) / 2;
    makeTree(2 * node, start, mid);
    makeTree(2 * node + 1, mid + 1, end);
    
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    
    return;
}

void update(int node, int start, int end, int idx, int value){
    if(start > idx || end < idx) return;
    
    if(start == end){
        tree[node] = (value % 2 ? treeNode(1, 0) : treeNode(0, 1));
        return;
    }
    
    int mid = (start + end) / 2;
    if(idx >= start && idx <= mid) update(2 * node, start, mid, idx, value);
    if(idx > mid && idx <= end) update(2 * node + 1, mid + 1, end, idx, value);
    
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    
    return;
}

int getRes(int node, int start, int end, int left, int right, int r){ // r=1:홀, r=0:짝
    if(start > right || end < left) return 0;
    
    if(start >= left && end <= right) return (r ? tree[node].odd : tree[node].even);
    
    int mid = (start + end) / 2;
    int leftRes = getRes(2 * node, start, mid, left, right, r);
    int rightRes = getRes(2 * node + 1, mid + 1, end, left, right, r);
    
    return leftRes + rightRes;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for(int i=1; i<=N; i++) cin >> arr[i];
    
    int h = ceil(log2(N)) + 1;
    tree = new treeNode[1 << h];
    makeTree(1, 1, N);
    
    cin >> M;
    
    vector<int> ans;
    
    int q, a, b;
    for(int i=0; i<M; i++){
        cin >> q >> a >> b;
        
        if(q == 1){
            update(1, 1, N, a, b);
        }
        else if(q == 2){
            ans.push_back(getRes(1, 1, N, a, b, 0));
        }
        else{
            ans.push_back(getRes(1, 1, N, a, b, 1));
        }
    }
    
    for(int curr : ans) printf("%d\n", curr);
    
    return 0;
}
