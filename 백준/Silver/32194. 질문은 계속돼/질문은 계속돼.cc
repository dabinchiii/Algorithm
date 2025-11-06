#include <iostream>

#define MAX_N 200000

using namespace std;

struct Node{
    int lastX, lastO;
};

int N;
Node arr[MAX_N + 2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    arr[1] = {0, 1};
    
    int comm, x, y;
    for(int i=2; i<=N + 1; i++){
        cin >> comm >> x >> y;
        
        if(comm == 1){ // x~y 모두 맞았냐?
            if(arr[y].lastX < x){ // 그렇다 = y 시점에서 가장 최근 틀린 것이 x보다 이전이다.
                cout << "Yes\n";
                arr[i] = {arr[i - 1].lastX, i};
            }
            else{
                cout << "No\n";
                arr[i] = {i, arr[i - 1].lastO};
            }
        }
        else{ // x~y 모두 틀렸냐?
            if(arr[y].lastO < x){ // 그렇다 = y 시점에서 가장 최근 맞은 것이 x보다 이전이다.
                cout << "Yes\n";
                arr[i] = {arr[i - 1].lastX, i};
            }
            else{ // 아니다
                cout << "No\n";
                arr[i] = {i, arr[i - 1].lastO};
            }
        }
    }
    
    return 0;
}
