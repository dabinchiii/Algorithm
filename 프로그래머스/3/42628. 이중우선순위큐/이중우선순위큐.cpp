#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

#define ERR -1

using namespace std;

unordered_map<int, int> cnt;
int sz; // 현재 요소 수
priority_queue<int> h1, h2;

bool isEmpty(){
    return sz == 0;
}
void insert(int num){
    h1.push(num);
    h2.push(-num);
    ++cnt[num];
    ++sz;
    
    return;
}
int deleteMax(){
    if(isEmpty()) return ERR;
    
    while(cnt[h1.top()] == 0) h1.pop();
    
    int res = h1.top();
    h1.pop();
    --cnt[res];
    --sz;
    
    return res;
}

int deleteMin(){
    if(isEmpty()) return ERR;
    
    while(cnt[-h2.top()] == 0) h2.pop();
    
    int res = -h2.top();
    --cnt[res];
    --sz;
    
    return res;
}
vector<int> solution(vector<string> operations) {
    for(string comm : operations){
        if(comm[0] == 'I') insert(stoi(comm.substr(2)));
        else if(comm[2] == '1') deleteMax();
        else deleteMin();
    }
    
    if(isEmpty()) return {0, 0};
                                  
    vector<int> ans(2);
    ans[0] = deleteMax();
    ans[1] = isEmpty() ? ans[0] : deleteMin();
    
    return ans;
}