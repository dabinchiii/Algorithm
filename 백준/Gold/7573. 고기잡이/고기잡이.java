import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, l, m;
	static int[][] arr;
	static int ans;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
//		System.setIn(new FileInputStream("Test4.txt"));

		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken()); // 너비
		l = Integer.parseInt(st.nextToken()); // 높이
		m = Integer.parseInt(st.nextToken());
		
		arr = new int[m][2];

		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			arr[i][0] = Integer.parseInt(st.nextToken());
			arr[i][1] = Integer.parseInt(st.nextToken());
		}
		
		solve();
		
		System.out.println(ans);
	}
	
	static void solve() {
		ans = -1;
		
		for(int i=0; i<m; i++){
			for(int j=0; j<m; j++) {
				for(int k=1; k<l/2; k++) {
					ans = Math.max(ans, calc(arr[i][0], arr[j][1], k, l/2 - k));
				}
			}
		}
	}
	
	static int calc(int r, int c, int netH, int netW) {
		int cnt = 0;
		for(int i=0; i<m; i++) {
			if(arr[i][0] >= r && arr[i][0] <= r + netH && arr[i][1] >= c && arr[i][1] <= c + netW) cnt++;
		}
		return cnt;
	}
}
