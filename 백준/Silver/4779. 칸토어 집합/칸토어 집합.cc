#include <iostream>
#include <cmath>

using namespace std;

int N;
string mem[21][2];

string kan(int k, int flag){
    if(k == 0) return flag ? "-" : " ";
    
    if(mem[k - 1][0].empty()) mem[k-1][0] = kan(k - 1, 0);
    if(mem[k - 1][1].empty()) mem[k - 1][1] = kan(k - 1, 1);
    
    return mem[k - 1][flag] + mem[k - 1][0] + mem[k - 1][flag];
}

int main(){
    while(cin >> N){
        string ans = kan(N, 1);
        cout << ans << '\n';
    }
    return 0;
}
