#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(int &a, int &b){
    return a > b;
}
int main(){
    string num;
    cin >> num;
    
    vector<int> v;
    int sum = 0;
    for(int i=0; i<num.size(); i++){
        v.push_back(num[i] - '0');
        sum += v[i];
    }
    
    sort(v.begin(), v.end(), comp);
    
    if(v[num.size() - 1] != 0 || sum % 3 != 0) cout << -1;
    else{
        for(int i=0; i<v.size(); i++) cout << v[i];
    }
    
    return 0;
}
