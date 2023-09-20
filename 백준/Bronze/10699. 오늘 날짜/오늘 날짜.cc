#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    printf("%d-%02d-%02d", 1900 + t->tm_year, t->tm_mon + 1, t->tm_mday);

    return 0;
}
