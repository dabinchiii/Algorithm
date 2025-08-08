import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int INF = 10000;// ?
	static int n;
	static int[][] dist, ans;
	
	public static void main(String[] args) throws IOException {
		n = Integer.parseInt(br.readLine());
		dist = new int[n + 1][n + 1];
		ans = new int[n + 1][n + 1];
		
		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=1; j<=n; j++) {
				int num = Integer.parseInt(st.nextToken());
				
				if(num == 1) dist[i][j] = 1;
				else dist[i][j] = INF;
			}
		}
		
		solve();
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				System.out.print(ans[i][j] + " ");
			}
			System.out.println();
		}
	}

	private static void solve() {
		for(int k=1; k<=n; k++) {
			for(int i=1; i<=n; i++) {
				for(int j=1; j<=n; j++) {
					int d = dist[i][k] + dist[k][j];
					if(dist[i][j] > d) dist[i][j] = d;
				}
			}
		}
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				ans[i][j] = (dist[i][j] == INF) ? 0 : 1;
			}
		}
		return;
	}
}
