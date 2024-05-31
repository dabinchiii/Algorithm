#include <bits/stdc++.h>
#define MAX_LEN 10

using namespace std;

string str;
int num;
char seq[MAX_LEN];
bool visited[MAX_LEN];
int currPos = 0;
bool findAns;

void bt(int cnt){
    if(findAns) return;

    if(cnt == str.length()){
        currPos++;

        if(currPos == num){
            findAns = true;
            for(int i=0; i<str.length(); i++) cout << seq[i];
        }

        return;
    }

    for(int i=0; i<str.length(); i++){
        if(visited[i]) continue;

        seq[cnt] = str[i];
        visited[i] = true;
        bt(cnt + 1);
        visited[i] = false;
    }

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> str){
        cin >> num;

        currPos = 0;
        findAns = false;
        cout << str << ' ' << num << " = ";
        bt(0);

        if(!findAns) cout << "No permutation";
        cout << endl;
    }

    return 0;
}
