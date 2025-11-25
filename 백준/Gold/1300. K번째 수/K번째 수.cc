#include <iostream>
#include <cmath>

using namespace std;

long long N, K;
long long ans;

bool check(long long x) { // x보다 작은 수가 K개 미만인가?
    long long cnt = 0;
    for (int i = 1; i <= N; i++) cnt += min(N, (x - 1) / i);
    //cout << cnt << endl;
    return cnt < K;
}
bool isPossible(long long num) { // 보드에 존재하는 수인가?
    for (int i = 1; i <= N; i++) {
        if (num % i == 0 && num / i >= 1 && num / i <= N) return true;
    }
    return false;
}
void solve() {
    ans = -1;
    long long left = 1, right = N * N;
    while (left <= right) {
        long long mid = (left + right) / 2;

        //printf("left=%d, right=%d, mid=%d\n", left, right, mid);

        if (check(mid)) {
            if (isPossible(mid)) ans = max(ans, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return;
}

int main() {
    cin >> N >> K;
    solve();
    cout << ans;
    return 0;
}
