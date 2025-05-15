#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int n;
string expr;
double num[26];
double ans;

bool isNum(char c){
    return (c >= 'A' && c <= 'Z');
}
double calc(char op, double num1, double num2){
    switch(op){
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
    }
    
    return -1;
}

void solve(){
    stack<double> s;
    
    for(int i=0; i<expr.length(); i++){
        char curr = expr[i];
        
        if(isNum(curr)){ // 피연산자
            s.push(num[curr - 'A']);
        }
        else{ // 연산자
            double num1, num2;
            
            num2 = s.top();
            s.pop();
            num1 = s.top();
            s.pop();
            
            double res = calc(curr, num1, num2);
            
            s.push(res);
        }
    }
    
    ans = s.top();
    
    return;
}

int main(){
    cin >> n >> expr;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }
    
    solve();
    
    cout << fixed;
    cout.precision(2);
    cout << ans;
    
    return 0;
}
