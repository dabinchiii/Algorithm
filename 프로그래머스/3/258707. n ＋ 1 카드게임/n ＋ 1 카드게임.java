import java.util.Arrays;
import java.util.Iterator;
import java.util.TreeSet;

class Solution {
	
//	public static void main(String[] args) {
////		int ans = solution(4, new int[] {3, 6, 7, 2, 1, 10, 5, 9, 8, 12, 11, 4}); // 예시 1
////		int ans = solution(3, new int[] {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11, 12}); // 예시 2
////		int ans = solution(2, new int[] {5, 8, 1, 2, 9, 4, 12, 11, 3, 10, 6, 7}); // 예시 3
//		int ans = solution(10, new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18}); // 예시 4
//		
//		System.out.println(ans);
//	}
	public static int solution(int coin, int[] cards) {
		int ans = -1;
		
		int N = cards.length;
		int S = N + 1;
		int[] round = new int[N + 1]; // 카드가 나오는 라운드
		
		int cntPair0 = 0; // 현재 0원을 주고 낼 수 있는 카드쌍의 수
		int cntPair1 = 0; // 현재 1원을 주고 낼 수 있는 카드쌍의 수
		int cntPair2 = 0; // 현재 2원을 주고 낼 수 있는 카드쌍의 수
		
		// 각 카드가 등장하는 라운드 기록
		int r = 0;
		for(int i=0; i<N/3; i++) {
			round[cards[i]] = r;
		}
		r = 1;
		for(int i=N/3; i<N; i+=2) {
			round[cards[i]] = r;
			round[cards[i + 1]] = r;
			r++;
		}
		
		// 처음 뽑은 N/3개 카드 내에 존재하는 쌍의 수 계산
		for(int i=0; i<N/3; i++) {
			if(round[S - cards[i]] == 0) cntPair0++;
		}
		cntPair0 /= 2;
			
		int currIdx = N / 3, currCard;
		int pr; // 짝이 등장하는 라운드
		while(true) {
			if(currIdx >= N) {
				ans = round[cards[currIdx - 1]] + 1;
				break;
			}
			
			// 첫 번째 카드
			currCard = cards[currIdx];
			pr = round[S - currCard];
			if(pr == 0) {
				cntPair1++; // 이 시점 이후로 1원을 내고 {curr, S - curr} 쌍을 언제든지 낼 수 있음
			}
			else if(pr < round[currCard]) {
				cntPair2++; // 이 시점 이후로 2원을 내고 {curr, S - curr} 쌍을 언제든지 낼 수 있음
			}
			currIdx++;
			
			// 두 번째 카드
			currCard = cards[currIdx];
			pr = round[S - currCard];
			if(pr == 0) {
				cntPair1++; // 이 시점 이후로 1원을 내고 {curr, S - curr} 쌍을 언제든지 낼 수 있음
			}
			else if(pr <= round[currCard]) {
				cntPair2++; // 이 시점 이후로 2원을 내고 {curr, S - curr} 쌍을 언제든지 낼 수 있음
			}
			currIdx++;
			
			// 다음 라운드로 이동을 시도 (0원 소모 -> 1원 소모 -> 2원 소모 순으로 그리디하게 검토)
			if(cntPair0 > 0) {
				cntPair0--;
				continue; // 다음 라운드 이동
			}
			
			if(cntPair1 > 0 && coin >= 1) {
				cntPair1--;
				coin -= 1;
				continue; // 다음 라운드 이동
			}
			
			if(cntPair2 > 0 && coin >= 2) {
				cntPair2--;
				coin -= 2;
				continue; // 다음 라운드 이동
			}
			
			// 낼 수 있는 카드쌍이 없음
			ans = round[cards[currIdx - 1]];
			break;
		}
		
		
		return ans;
    }
}