#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    
    for(int i=0; i<phone_book.size() - 1; i++){
        string &a = phone_book[i];
        string &b = phone_book[i + 1];
        if(b.compare(0, a.size(), a) == 0) return false;
    }
    
    return true;
}