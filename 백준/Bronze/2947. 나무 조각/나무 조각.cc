#include <iostream>

using namespace std;

int nums[5];

void print(){
    for(int i=0; i<5; i++) cout << nums[i] << ' ';
    cout << '\n';
    return;
}
int main(){
    for(int i=0; i<5; i++) cin >> nums[i];
    
    bool flag;
    do{
        flag = true;
        for(int i=1; i<5; i++){
            if(nums[i - 1] <= nums[i]) continue;
            
            swap(nums[i - 1], nums[i]);
            flag = false;
            
            print();
        }
        
    }while(!flag);
    
    return 0;
}
