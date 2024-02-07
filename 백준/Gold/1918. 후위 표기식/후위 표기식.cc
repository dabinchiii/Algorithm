#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    map<char, int> prior;
    prior['+'] = prior['-'] = 1;
    prior['*'] = prior['/'] = 2;

    stack<char> st;
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            cout << str[i];
            continue;
        }

        if(str[i] == '('){
            st.push(str[i]);
        }
        else if(str[i] == ')'){
            while(st.top() != '('){
                cout << st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && prior[str[i]] <= prior[st.top()]){
                cout << st.top();
                st.pop();
            }
            st.push(str[i]);
        }
    }

    while(!st.empty()){
        cout << st.top();
        st.pop();
    }

    return 0;
}
