#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> neg, pos;

int main(){
    cin >> N >> M;
    
    int num;
    for(int i=0; i<N; i++){
        cin >> num;
        if(num < 0) neg.push_back(-num);
        else pos.push_back(num);
    }
    
    sort(neg.begin(), neg.end());
    sort(pos.begin(), pos.end());
    
    int ans = 0;
    int negP = (int)neg.size() - 1, posP = (int)pos.size() - 1;
    if(pos.empty() || (!neg.empty() && neg[negP] > pos[posP])){ // neg에 편도 넣는 경우
        ans += neg[negP];
        negP -= M;
    }
    else if(neg.empty() || (!pos.empty() && pos[posP] > neg[negP])){
        ans += pos[posP];
        posP -= M;
    }
    
    while(negP >= 0){
        ans += 2 * neg[negP];
        negP -= M;
    }
    while(posP >= 0){
        ans += 2 * pos[posP];
        posP -= M;
    }
    
    cout << ans;
    
    return 0;
}
