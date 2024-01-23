#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    if(a.length() < b.length()) swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    while(a.length() > b.length()){
        b.push_back('0');
    }

    string Answer = "";
    int carry = 0, sum;
    for(int i=0; i<a.length(); i++){
        sum = carry + (a[i] - '0') + (b[i] - '0');
        carry = 0;
        if(sum > 1){
            sum -= 2;
            carry++;
        }
        Answer.push_back(sum + '0');
    }

    if(carry) Answer.push_back('1');

    reverse(Answer.begin(), Answer.end());
    for(int i=0; i<a.length(); i++){
        if(Answer[i] != '1' && i != a.length() - 1) continue;
        Answer = Answer.substr(i);
        break;
    }
    cout << Answer;

    return 0;
}
