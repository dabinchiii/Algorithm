#include <iostream>
#include <vector>

#define MAX_N 20

using namespace std;

void hanoi(int from, int tmp, int to, int curr){
    if(curr == 1){
        cout << from << ' ' << to << '\n';
        return;
    }
    
    hanoi(from, to, tmp, curr - 1);
    cout << from << ' ' << to << '\n';
    hanoi(tmp, from, to, curr - 1);
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    cout << (1 << N) - 1 << '\n';
    hanoi(1, 2, 3, N);
    
    return 0;
}
