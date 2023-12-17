#include <bits/stdc++.h>

using namespace std;

bool Answer;

struct TrieNode{
    bool isEnd;
    TrieNode* child[10];

    TrieNode(){
        isEnd = false;
        for(int i=0; i<10; i++) child[i] = NULL;
    }

    ~TrieNode() {
        for(int i=0; i<10; i++){
            if(child[i]) delete child[i];
        }
    }

    void insert(string& key, int index){
        if(index == key.length()){
            isEnd = true;
            return;
        }

        int next = key[index] - '0';
        if(child[next] == nullptr){
            child[next] = new TrieNode;
        }
        if(child[next]->isEnd) Answer = false;
        child[next]->insert(key, index + 1);

    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for(int t=0; t<T; t++){
        int n;
        cin >> n;

        vector<string> arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());

        Answer = true;
        TrieNode root;
        for(string number : arr){
            root.insert(number, 0);
        }

        cout << (Answer ? "YES" : "NO") << '\n';
    }

    return 0;
}
