#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> num;
    for(int i=1; i<=n; i++){
        num.push_back(i);
    }

    vector<int> Answer;
    int idx = k - 1;
    while(true){
        Answer.push_back(num[idx]);
        num.erase(num.begin() + idx);

        if(num.empty()) break;

        idx--;
        idx = (idx + k) % (int)num.size();
    }

    cout << "<" << Answer[0];
    for(auto it=Answer.begin() + 1; it!=Answer.end(); it++){
        cout << ", "<< *it;
    }
    cout << ">";

    return 0;
}
