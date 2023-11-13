#include <bits/stdc++.h>

using namespace std;

string reverseWord(string word){
    string reversed = word;
    int len = word.length();
    for(int i=0; i<len / 2; i++){
        swap(reversed[i], reversed[len - 1 - i]);
    }
    return reversed;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    set<string> s;

    string AnswerWord = "";

    string word;
    for(int i=0; i<n; i++){
        cin >> word;

        int before = s.size();
        s.insert(word);
        s.insert(reverseWord(word));
        int after = s.size();

        if(after - before < 2){
            AnswerWord = word;
        }
    }

    int len = AnswerWord.length();
    cout << len << ' ' << AnswerWord[len/2];

    return 0;
}
