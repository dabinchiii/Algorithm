import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, m, l, k;
	static int[][] arr;
	static int ans;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
//		System.setIn(new FileInputStream("Test4.txt"));

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); // 너비
		m = Integer.parseInt(st.nextToken()); // 높이
		l = Integer.parseInt(st.nextToken());
		k = Integer.parseInt(st.nextToken());
		
		arr = new int[k][2];
		
		for(int i=0; i<k; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		
		System.out.println(ans);
	}
	
	static void solve() {
		ans = -1;
		for(int i=0; i<k; i++) {
			for(int j=0; j<k; j++) {
				int r = arr[i][0];
				if(r + l > n) r = n - l;
				
				int c = arr[j][1];
				if(c + l > m) c = m - l;
				
				ans = Math.max(ans,  calc(r, c));
			}
		}
		ans = k - ans;
	}
	
	static int calc(int r, int c) {
		int cnt = 0;
		for(int i=0; i<k; i++) {
			if(arr[i][0] >= r && arr[i][0] <= r + l && arr[i][1] >= c && arr[i][1] <= c + l) cnt++;
		}
		
		return cnt;
	}
	
}
