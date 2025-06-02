#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    queue<pair<int, int>> q;
    vector<int> listA, listB, listC;
    
    int comm, a, b;
    for(int i=0; i<n; i++){
        cin >> comm;
        
        if(comm == 1){
            cin >> a >> b;
            q.push({a, b});
        }
        else{
            cin >> b;
            
            if(q.front().second == b){
                listA.push_back(q.front().first);
                q.pop();
            }
            else{
                listB.push_back(q.front().first);
                q.pop();
            }
            
        }
    }
    
    while(!q.empty()){
        listC.push_back(q.front().first);
        q.pop();
    }
    
    sort(listA.begin(), listA.end());
    sort(listB.begin(), listB.end());
    sort(listC.begin(), listC.end());
    
    if(listA.empty()){
        cout << "None";
    }
    else{
        for(int curr : listA) cout << curr << ' ';
    }
    cout << endl;
    
    if(listB.empty()){
        cout << "None";
    }
    else{
        for(int curr : listB) cout << curr << ' ';
    }
    cout << endl;
    
    if(listC.empty()){
        cout << "None";
    }
    else{
        for(int curr : listC) cout << curr << ' ';
    }
    cout << endl;
    
    return 0;
}
