import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, m, t, k;
	static int[][] arr;
	static int[] ans;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
//		System.setIn(new FileInputStream("Test4.txt"));

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); // 너비
		m = Integer.parseInt(st.nextToken()); // 높이
		t = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		arr = new int[t][2];
		
		for(int i=0; i<t; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		
		System.out.println(ans[0] + " " + ans[1] + "\n" + ans[2]);
	}
	
	static void solve() {
		ans = new int[] {-1, -1, -1};
		
		for(int i=0; i<t; i++) {
			for(int j=0; j<t; j++) {
				int r = arr[i][0];
				if(r + k > n) r = n - k;
				
				int c = arr[j][1];
				if(c + k > m) c = m - k;
				
				int cnt = calc(r, c);
				
				if(cnt > ans[2]) {
					ans = new int[] {r, c + k, cnt};
				}
			}
		}
	}
	
	static int calc(int r, int c) {
//		if(r + k > n || c + k > m) return -1;
		
		int cnt = 0;
		for(int i=0; i<t; i++) {
			if(arr[i][0] >= r && arr[i][0] <= r + k && arr[i][1] >= c && arr[i][1] <= c + k) cnt++;
		}
		
		return cnt;
	}
}
