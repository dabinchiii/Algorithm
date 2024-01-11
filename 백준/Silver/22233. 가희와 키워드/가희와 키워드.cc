#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<string> s;
    string keyword;
    for(int i=0; i<n; i++){
        cin >> keyword;
        s.insert(keyword);
    }

    string post;
    for(int i=0; i<m; i++){
        cin >> post;
        post.push_back(',');

        int start = 0;
        for(int j=0; j<post.length(); j++){
            if(post[j] != ',') continue;

            string token = post.substr(start, j - start);
            start = j + 1;

            auto it = s.find(token);
            if(it != s.end()){
                s.erase(it);
            }
        }

        cout << s.size() << '\n';
    }

    return 0;
}
