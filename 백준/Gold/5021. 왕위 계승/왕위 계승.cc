#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <cmath>

#define MAX_N 150

using namespace std;

int N, M;
int lastIdx = 0;
map<string, int> nameToIdx; // idx는 1부터 시작
string names[MAX_N + 1];
vector<int> g[MAX_N + 1];
int inDegree[MAX_N + 1];
vector<int> list; // 왕위를 계승받기를 주장하는 사람들
string ans;

void solve(){
    vector<double> value(lastIdx + 1, 0);
    value[1] = (1 << 25);
    
    queue<int> q;
    for(int i=1; i<=lastIdx; i++){
        if(inDegree[i] == 0) q.push(i);
    }
    
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(int nxt : g[curr]){
            value[nxt] += (value[curr] / 2.0);
            if(--inDegree[nxt] == 0) q.push(nxt);
        }
    }

    
    double maxValue = -1;
    int maxIdx = -1;
    for(int curr : list){
        if(value[curr] > maxValue){
            maxValue = value[curr];
            maxIdx = curr;
        }
    }
    
    ans = names[maxIdx];
    
    return;
}

int main(){
    cin >> N >> M;
    
    string first; // 나라 세운 사람
    cin >> first;
    nameToIdx[first] = ++lastIdx;
    names[lastIdx] = first;
    
    string a, b, c;
    int idxA, idxB, idxC;
    for(int i=0; i<N; i++){
        cin >> a >> b >> c;
        if(nameToIdx[a]==0){
            nameToIdx[a] = ++lastIdx;
            names[lastIdx] = a;
        }
        if(nameToIdx[b]==0){
            nameToIdx[b] = ++lastIdx;
            names[lastIdx] = b;
        }
        if(nameToIdx[c]==0) {
            nameToIdx[c] = ++lastIdx;
            names[lastIdx] = c;
        }
        
        idxA = nameToIdx[a]; // 자식
        idxB = nameToIdx[b];
        idxC = nameToIdx[c];
        
        g[idxB].push_back(idxA);
        g[idxC].push_back(idxA);
        inDegree[idxA] += 2;
    }
    
    for(int i=0; i<M; i++){
        cin >> a;
        list.push_back(nameToIdx[a]);
    }
    
    solve();
    
    cout << ans;
    
    return 0;
}
