#include <iostream>
#include <algorithm>

#define MAX_N 20

using namespace std;

void hanoi(int from, int tmp, int to, int curr){
    if(curr == 1){
        cout << from << ' ' << to << '\n';
        return;
    }
    
    hanoi(from, to, tmp, curr - 1);
    cout << from << ' ' << to << '\n';
    hanoi(tmp, from, to, curr - 1);
    
    return;
}

string my2Pow(int N){
    string res = "1", tmp;
    int carry, curr;
    
    // res에 2^N의 리버스 저장
    carry = 0;
    for(int i=0; i<N; i++){
        tmp = "";
        
        for(int j=0; j<res.size(); j++){
            curr = ((res[j] - '0') << 1) + carry;
            carry = 0;
            
            if(curr >= 10){
                ++carry;
                curr -= 10;
            }
            
            tmp.push_back('0' + curr);
        }
        
        if(carry){
            tmp.push_back('1');
            carry = 0;
        }
        
        res = tmp;
    }
    
    // 리버스된 res에 -1
    int len = (int)res.size();
    carry = 0;
    for(int i=0; i<len; i++){
        curr = res[i] - '0' + carry - 1;
        
        if(curr >= 0){
            res[i] = '0' + curr;
            break;
        }
        
        carry = -1;
        curr += 10;
        res[i] = '0' + curr;
    }
    
    if(res.back() == '0') res.pop_back();
    
    reverse(res.begin(), res.end());
    
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    cout << my2Pow(N) << '\n';
    if(N <= 20) hanoi(1, 2, 3, N);
    
    return 0;
}
