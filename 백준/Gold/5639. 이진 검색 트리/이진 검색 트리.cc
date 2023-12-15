#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void solve(int left, int right){
    if(left >= right) return;

    if(right - left == 1){ // 자식이 없는 경우
        cout << arr[left] << '\n';
        return;
    }

    int rightChild = left + 1;
    while(rightChild < right && arr[left] > arr[rightChild]){
        rightChild++;
    }

    // 후위 순회
    solve(left + 1, rightChild); // left subtree
    solve(rightChild, right); // right subtree
    cout << arr[left] << '\n'; // root
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    while(cin >> num){
        arr.push_back(num);
    }

    solve(0, arr.size());

    return 0;
}
