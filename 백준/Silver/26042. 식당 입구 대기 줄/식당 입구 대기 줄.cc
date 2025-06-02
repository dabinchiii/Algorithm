#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    queue<int> q;
    int maxL = -1, numBack = -1;
    
    int comm;
    for(int i=0; i<n; i++){
        cin >> comm;
        
        if(comm == 2){
            q.pop();
            continue;
        }
        
        int num;
        cin >> num;
        
        q.push(num);
        
        int len = (int)q.size();
        if(len > maxL){
            maxL = len;
            numBack = num;
        }
        else if(len == maxL){
            numBack = min(numBack, num);
        }
    }
    
    
    cout << maxL << ' ' << numBack;
    
    return 0;
}
