#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int k;
        cin >> k;

        int n = 1, num;
        vector<int> triNums;
        while(true){
            num = n * (n + 1) / 2;

            if(num > k) break;

            triNums.push_back(num);
            n++;
        }

        bool Answer = false;
        for(int i=0; i<triNums.size(); i++){
            for(int j=0; j<triNums.size(); j++){
                for(int l=0; l<triNums.size(); l++){
                    if(triNums[i] + triNums[j] + triNums[l] == k){
                        Answer = true;
                    }
                }
            }
        }

        cout << (Answer ? "1" : "0") << '\n';
    }

    return 0;
}
