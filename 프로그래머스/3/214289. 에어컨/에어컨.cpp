#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

#define INF 10000000

using namespace std;

int dp[1001][55];

int solution(int temp, int t1, int t2, int a, int b, vector<int> onboard) {
	int len = onboard.size();
	int diff = min(abs(t1 - temp), abs(t2 - temp));

	for (int i = 0; i < len; i++) {
		for (int j = 0; j <= diff + 2; j++) {
			dp[i][j] = INF;
		}
	}

	dp[0][diff + 1] = 0;

	for (int i = 0; i < len; i++) {
		if (onboard[i] == 0) {
			for (int j = 1; j <= diff + 1; j++) {
				if (dp[i][j] == INF) continue;

				// temp인 경우 => 0원 쓰고 유지 / a원 쓰고 1도 내려가기
				// 아닌 경우 => 0원 쓰고 1도 올라가기 / a원 쓰고 1도 내려가기 / b원 쓰고 유지

				if (j == diff + 1) {
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + a);
				}
				else {
					dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j]);
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + b);
					dp[i + 1][j - 1] = min(dp[i + 1][j - 1], dp[i][j] + a);
				}
			}
		}
		else {
			dp[i + 1][2] = min(dp[i + 1][2], dp[i][1]);

			dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b);
			dp[i + 1][1] = min(dp[i + 1][1], dp[i][0]);

			dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + b);
			dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a);
		}
	}
	int answer = INF;
	if (onboard[len - 1] == 1) {
		answer = min(dp[len - 1][0], dp[len - 1][1]);
	}
	else {
		for (int i = 0; i <= diff + 1; i++) answer = min(answer, dp[len - 1][i]);
	}

	return answer;
}