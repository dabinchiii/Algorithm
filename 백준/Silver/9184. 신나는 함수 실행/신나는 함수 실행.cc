#include <iostream>

using namespace std;


int w[21][21][21];

void makeTable(){
    for(int i=0; i<=20; i++){
        for(int j=0; j<=20; j++){
            w[0][i][j] = w[i][0][j] = w[i][j][0] = 1;
        }
    }
    
    for(int i=1; i<=20; i++){
        for(int j=1; j<=20; j++){
            for(int k=1; k<=20; k++){
                if(i < j && j < k){
                    w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
                }
                else{
                    w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];
                    
                }
            }
        }
    }
    
    return;
}
int ans(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        a = b = c = 0;
    }
    if(a > 20 || b > 20 || c > 20){
        a = b = c = 20;
    }
    
    return w[a][b][c];
}

int main(){
    makeTable();
    
    int a, b, c;
    while(true){
        cin >> a >> b >> c;
        
        if(a == -1 && b == -1 && c == -1) break;
        
        printf("w(%d, %d, %d) = %d\n", a, b, c, ans(a, b, c));
    }
    
    return 0;
}
