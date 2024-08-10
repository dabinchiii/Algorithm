#include <bits/stdc++.h>

using namespace std;

bool isVowel[26];

void init(){
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i=0; i<5; i++){
        isVowel[vowel[i] - 'a'] = true;
    }
    return;
}

bool vowelTest(string str){
    for(int i=0; i<str.length(); i++){
        if(isVowel[str[i] - 'a']) return true;
    }
    return false;
}
bool tripleTest(string str){
    bool v[str.length()];
    for(int i=0; i<str.length(); i++){
        v[i] = isVowel[str[i] - 'a'];
    }

    for(int i=2; i<str.length(); i++){
        if(v[i] != v[i - 1]) continue;
        if(v[i - 1] != v[i - 2]) continue;
        return false;
    }
    return true;
}
bool doubleTest(string str){
    for(int i=1; i<str.length(); i++){
        if(str[i] != str[i - 1]) continue;
        if(str[i] == 'e' || str[i] == 'o') continue;
        return false;
    }
    return true;
}

bool eval(string pw){
    if(!vowelTest(pw)) return false;
    if(!tripleTest(pw)) return false;
    if(!doubleTest(pw)) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init();

    string pw;
    while(1){
        cin >> pw;
        if(pw == "end") break;

        cout << "<" << pw << "> is ";
        cout << (!eval(pw) ? "not " : "") << "acceptable.\n";
    }

    return 0;
}
