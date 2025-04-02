#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    char arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int x = 0, y = 0;
    int i=0;
    while(i < n){
        if(arr[i] == 'D') x++;
        else y++;
        
        if(abs(x - y) >= 2){
            
            break;
        }
        
        i++;
    }
    
    cout << x << ":" << y;
    
    return 0;
}