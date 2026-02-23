#include <iostream>
#include <algorithm>

#define MAX_N 20

using namespace std;

const int offset = '0' << 1;

string sum(string a, string b){
    string res = "";
    int curr, carry;
    
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    while(a.length() < b.length()) a.push_back('0');
    while(b.length() < a.length()) b.push_back('0');
    
    int len = (int)a.length();
    
    carry = 0;
    for(int i=0; i<len; i++){
        curr = a[i] + b[i] - offset + carry;
        carry = 0;
        
        if(curr >= 10){
            ++carry;
            curr -= 10;
        }
        
        res.push_back('0' + curr);
    }
    
    if(carry) res.push_back('1');
    
    reverse(res.begin(), res.end());
        
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    cin >> a >> b;
    cout << sum(a, b);
    
    return 0;
}
