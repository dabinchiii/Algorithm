#include <bits/stdc++.h>

using namespace std;

void solve1(string str){
    // 카멜
    string camel = str;

    // 스네이크
    string snake;
    for(int i=0; i<str.length(); i++){
        if(str[i] >= 'A' && str[i] <= 'Z'){
            snake.push_back('_');
            snake.push_back(tolower(str[i]));
        }
        else{
            snake.push_back(str[i]);
        }
    }

    // 파스칼
    string pascal;
    pascal.push_back(toupper(str[0]));
    pascal += str.substr(1);

    cout << camel << '\n' << snake << '\n' << pascal;
}
void solve2(string str){
    // 카멜
    string camel;
    for(int i=0; i<str.length(); i++){
        if(str[i] == '_'){
            i++;
            camel.push_back(toupper(str[i]));
        }
        else{
            camel.push_back(str[i]);
        }
    }

    // 스네이크
    string snake = str;

    // 파스칼
    string pascal;
    pascal.push_back(toupper(camel[0]));
    pascal += camel.substr(1);

    cout << camel << '\n' << snake << '\n' << pascal;
}
void solve3(string str){
    // 카멜
    string camel;
    camel.push_back(tolower(str[0]));
    camel += str.substr(1);

    // 스네이크
    string snake;
    for(int i=0; i<camel.length(); i++){
        if(camel[i] >= 'A' && camel[i] <= 'Z'){
            snake.push_back('_');
            snake.push_back(tolower(camel[i]));
        }
        else{
            snake.push_back(camel[i]);
        }
    }

    // 파스칼
    string pascal = str;

    cout << camel << '\n' << snake << '\n' << pascal;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNum;
    cin >> caseNum;

    string str;
    cin >> str;

    if(caseNum == 1) solve1(str);
    else if(caseNum == 2) solve2(str);
    else solve3(str);

    return 0;
}
