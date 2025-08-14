import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.StringTokenizer;

public class Solution {
	static int n;
	static int[][] gdice;
	
	// 탐색에 사용
	static ArrayList<Integer> arrA, arrB; // 선택된 주사위
	static ArrayList<Integer> sumA, sumB;
	
	static int maxWin;
	static ArrayList<Integer> ans;

	public static int[] solution(int[][] dice) {
		n = dice.length;
		gdice = dice;
		
		arrA = new ArrayList<>();
		arrB = new ArrayList<>();
		sumA = new ArrayList<>();
		sumB = new ArrayList<>();
		ans = new ArrayList<>();
		
		combi(0, 0);
		
        int[] answer = ans.stream().mapToInt(i -> i + 1).toArray();
//        Arrays.sort(answer);
        return answer;
    }
	
	static void combi(int cnt, int start) { // A팀의 주사위 선택 (n/2개)
		if(cnt == n / 2) { // A팀 주사위 모두 선택됨
			// B팀 주사위는 A팀이 아닌 주사위
			arrB.clear();
			for(int i=0; i<n; i++) {
				if(!arrA.contains(i)) arrB.add(i);
			}
			
			// 현재 선택된 주사위들에 대해, 가능한 모든 경우의 주사위의 합 구함
			sumA.clear();
			permA(0, 0);
			Collections.sort(sumA);
			
			sumB.clear();
			permB(0, 0);
			Collections.sort(sumB);
			
//			System.out.println("A: " + arrA.toString());
//			System.out.println(sumA.toString());
//			
//			System.out.println("B: " + arrB.toString());
//			System.out.println(sumB.toString());
			
			int cntWin = 0;
			for(int x : sumA) {
				int idx = findLowerBound(x);
				cntWin += idx;
				
//				System.out.println("x: " + x + " idx: " + idx);
			}
			System.out.println("Awin: " + cntWin);
			if(cntWin > maxWin) {
				maxWin = cntWin;
				ans = (ArrayList<Integer>) arrA.clone();
			}
			return;
		}
		
		for(int i=start; i<n; i++) {
			arrA.add(i);
			combi(cnt + 1, i + 1);
			arrA.remove(arrA.size() - 1);
		}
		return;
	}
	
	private static int findLowerBound(int x) { // sumB에서 x보다 크거나 같은 첫 요소의 인덱스 반환
		int max = sumB.size();
		int min = 0;
		int mid = (min + max) / 2;
		while(min<max) {
			if(x > sumB.get(mid)) {
				min = mid + 1;
			}
			else {
				max = mid;
			}
			mid = (min + max) / 2;
		}
		return mid;
	}
	static void permA(int cnt, int sum) {
		if(cnt == n/2) {
			sumA.add(sum);
			return;
		}
		for(int i=0; i<6; i++) {
			permA(cnt + 1, sum + gdice[arrA.get(cnt)][i]);
		}
		return;
	}
	
	static void permB(int cnt, int sum) {
		if(cnt == n/2) {
			sumB.add(sum);
			return;
		}
		for(int i=0; i<6; i++) {
			permB(cnt + 1, sum + gdice[arrB.get(cnt)][i]);
		}
		return;
	}

}
