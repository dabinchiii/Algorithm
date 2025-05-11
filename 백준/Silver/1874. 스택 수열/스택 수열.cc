#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
int arr[100000];

int main(){
    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    
    stack<int> s;
    vector<char> ans;
    int currNum = 1;
    int p = 0;
    
    int cnt = 0;
    while(p < n && currNum <= n + 1){
        if(s.empty() || s.top() < arr[p]){
            s.push(currNum++);
            ans.push_back('+');
        }
        else if(s.top() == arr[p]){
            cnt++;
            s.pop();
            ans.push_back('-');
            p++;
        }
        else{
            break;
        }
    }
    
    if(cnt == n){
        for(char c : ans) cout << c << '\n';
    }
    else{
        cout << "NO";
    }
    
    return 0;
}
