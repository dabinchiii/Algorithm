#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for(int t=0; t<T; t++){
        string p, str;
        int n;

        cin >> p >> n >> str;

        deque<int> arr;

        string x = "";
        for(int i=0; i<str.length(); i++){
            if(str[i] >= '0' && str[i] <= '9'){
                x += str[i];
            }
            else{
                if(!x.empty()){
                    arr.push_back(stoi(x));
                    x = "";
                }
            }
        }

        bool error = false;
        bool isForward = true;
        for(int i=0; i<(int)p.length(); i++){
            if(p[i] == 'R'){
                isForward = !isForward;
            }
            else if(p[i] == 'D'){
                if(arr.empty()) {
                    error = true;
                    break;
                }
                else if(isForward) arr.pop_front();
                else arr.pop_back();
            }

        }

        if(error) cout << "error" << '\n';
        else{
            cout << "[";
            while(!arr.empty()){
                if(isForward){
                    cout << arr.front();
                    arr.pop_front();
                }
                else{
                    cout << arr.back();
                    arr.pop_back();
                }

                if(!arr.empty()) cout << ",";

            }
            cout << "]\n";
        }

    }

    return 0;
}
