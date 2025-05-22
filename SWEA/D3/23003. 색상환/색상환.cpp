#include <iostream>
#include <map>

using namespace std;

map<string, int> colorCode;

void init(){
    int cnt = 0;
    colorCode["red"] = cnt++;
    colorCode["orange"] = cnt++;
    colorCode["yellow"] = cnt++;
    colorCode["green"] = cnt++;
    colorCode["blue"] = cnt++;
    colorCode["purple"] = cnt++;
    
    return;
}
char solve(){
    string strS, strT;
    cin >> strS >> strT;
    
    int s = colorCode[strS], t = colorCode[strT];
    
    if(s == t) return 'E';
    if((s + 1) % 6 == t || (t + 1) % 6 == s) return 'A';
    if((s + 3) % 6 == t || (t + 3) % 6 == s) return 'C';
    
    return 'X';
}

int main(){
    int T;
    cin >> T;
    
    init();
    
    for(int t=1; t<=T; t++){
        cout << solve() << '\n';
    }
    
    return 0;
}
