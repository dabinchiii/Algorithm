#include <iostream>
#include <vector>

#define MAX_N 100000

using namespace std;

int n;
vector<int> currMin(3), currMax(3);
int ansMin, ansMax;



int main(){
    cin >> n;
    
    for(int i=0; i<3; i++){
        cin >> currMin[i];
        currMax[i] = currMin[i];
    }
    
    int a, b, c;
    vector<int> newMin(3), newMax(3);
    for(int i=1; i<n; i++){
        cin >> a >> b >> c;
        
        newMin[0] = a + min(currMin[0], currMin[1]); // OOX
        newMin[1] = b + min(currMin[0], min(currMin[1], currMin[2])); // OOO
        newMin[2] = c + min(currMin[1], currMin[2]); // XOO
        
        currMin = newMin;
        
        newMax[0] = a + max(currMax[0], currMax[1]);
        newMax[1] = b + max(currMax[0], max(currMax[1], currMax[2]));
        newMax[2] = c + max(currMax[1], currMax[2]);
        
        
        currMax = newMax;
    }
    
    ansMin = min(currMin[0], min(currMin[1], currMin[2]));
    ansMax = max(currMax[0], max(currMax[1], currMax[2]));
    
    cout << ansMax << ' ' << ansMin;
    
    
    return 0;
}
