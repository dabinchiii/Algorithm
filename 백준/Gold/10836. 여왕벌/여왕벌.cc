#include <iostream>

#define MAX_M 700

using namespace std;

int M, N;
int psum[MAX_M << 1];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> M >> N;
    
    psum[0] = 1; // 초기값
    
    int c0, c1, c2;
    for(int i=0; i<N; i++){
        cin >> c0 >> c1 >> c2;
        ++psum[c0];
        ++psum[c0 + c1];
    }
    
    int last = (M << 1) - 1;
    for(int i=1; i<last; i++){
        psum[i] += psum[i - 1];
    }
    
    for(int i=0; i<M; i++){
        cout << psum[M - i - 1] << ' ';
        for(int j=last - M + 1; j<last; j++){
            cout << psum[j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
