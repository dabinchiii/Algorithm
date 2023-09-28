#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int Answer = 0;
    int student, apple;
    for(int i=0; i<n; i++){
        cin >> student >> apple;
        Answer += apple % student;
    }

    cout << Answer;

    return 0;
}
