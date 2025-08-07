import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int w, h;
	static int n;
	static int[][] arr;
	static int ans;
	
	public static void main(String[] args) throws IOException{
		st = new StringTokenizer(br.readLine());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		n = Integer.parseInt(br.readLine());
		arr = new int[n + 1][3]; // arr[n]: 동근
		
		for(int i=0; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		
		System.out.println(ans);
	}

	private static void solve() {
		for(int i=0; i<=n; i++) {
			int a = arr[i][0];
			int b = arr[i][1];
			
			if(a == 1) { // 북쪽
				arr[i][2] = b;
			}
			else if(a == 2) { // 남쪽
				arr[i][2] = (2 * w + h) - b;
			}
			else if(a == 3) {
				arr[i][2] = (2 * w + 2 * h) - b;
			}
			else {
				arr[i][2] = w + b;
			}
		}
		
		int dg = arr[n][2]; // 동근 1차원 위치
		
		int sum = 0;
		for(int i=0; i<n; i++) {
			int x = Math.abs(dg - arr[i][2]);
			sum += Math.min(x, (2 * w + 2 * h) - x);
		}
		
		ans = sum;
		
		return;
	}
	
}
