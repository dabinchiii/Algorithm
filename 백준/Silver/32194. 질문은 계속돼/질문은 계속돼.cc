#include <iostream>

#define MAX_N 200000

using namespace std;

int N;
int arr[MAX_N + 2][2];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    arr[1][0] = 0; // 가장 최근 X
    arr[1][1] = 1; // 가장 최근 O
    
    int comm, x, y;
    for(int i=2; i<=N + 1; i++){
        cin >> comm >> x >> y;
        
        if(comm == 1){ // x~y 모두 맞았냐?
            if(arr[y][0] < x){ // 그렇다 = y 시점에서 가장 최근 틀린 것이 x보다 이전이다.
                cout << "Yes\n";
                arr[i][0] = arr[i - 1][0];
                arr[i][1] = i;
            }
            else{
                cout << "No\n";
                arr[i][0] = i;
                arr[i][1] = arr[i - 1][1];
            }
        }
        else{ // x~y 모두 틀렸냐?
            if(arr[y][1] < x){ // 그렇다 = y 시점에서 가장 최근 맞은 것이 x보다 이전이다.
                cout << "Yes\n";
                arr[i][0] = arr[i - 1][0];
                arr[i][1] = i;
            }
            else{ // 아니다
                cout << "No\n";
                arr[i][0] = i;
                arr[i][1] = arr[i - 1][1];
            }
        }
    }
    
    return 0;
}
