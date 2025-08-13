import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n;
	static long ans;
//	static int[] nums = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	static int count;
	static ArrayList<Integer> arr;
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		arr = new ArrayList<>();
		solve();
		System.out.println(ans);
	}
	
	static void solve() {
		if(n == 0) {
			ans = 0;
			return;
		}
		if(n > 1022) {
			ans = -1;
			return;	
		}
		
		ans = -1L;
		count = 0;
		
		int digit = 1;
		while(digit <= 10) {
			for(int i=1; i<=9; i++) {
				arr.add(i);
				combi(1, digit);
				arr.remove(arr.size() - 1);
				if(ans != -1) return;
			}
			digit++;
		}
		
	}
	
	static void combi(int cnt, int digit) {
		if(cnt == digit) {
			count++;
//			String str2 = "";
//			for(int x : arr) str2 += x;
//			System.out.println(count + " : "  + str2);
			
			if(count == n) {
				String str = "";
				for(int x : arr) str += x;
				ans = Long.parseLong(str);
			}
			return;
		}
		
		for(int i=0; i<arr.get(arr.size() - 1); i++) {
			arr.add(i);
			combi(cnt + 1, digit);
			arr.remove(arr.size() - 1);
		}
		
		return;
	}
}
