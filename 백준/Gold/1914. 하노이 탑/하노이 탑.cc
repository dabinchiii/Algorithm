#include <iostream>
#include <algorithm>

#define MAX_N 20

using namespace std;

void hanoi(int from, int tmp, int to, int curr){
    if(curr == 1){
        printf("%d %d\n", from, to);
        return;
    }
    
    hanoi(from, to, tmp, curr - 1);
    printf("%d %d\n", from, to);
    hanoi(tmp, from, to, curr - 1);
    
    return;
}

string my2Pow(int N){
    string res = "1";
    int carry = 0, sum;
    for(int i=0; i<N; i++){
        string tmp = "";
        
        for(int j=0; j<res.size(); j++){
            sum = ((res[j] - '0') << 1) + carry;
            carry = 0;
            
            if(sum >= 10){
                ++carry;
                sum %= 10;
            }
            
            tmp.push_back('0' + sum);
        }
        
        if(carry){
            tmp.push_back('1');
            carry = 0;
        }
        
        res = tmp;
    }
    
    int len = (int)res.size();
    int curr;
    
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
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    
    cout << my2Pow(N) << '\n';
    if(N <= 20) hanoi(1, 2, 3, N);
    
    return 0;
}
