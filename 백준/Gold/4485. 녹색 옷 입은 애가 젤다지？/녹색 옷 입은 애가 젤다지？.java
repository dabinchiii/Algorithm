import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n;
	static int[][] arr;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException{
		int t=1;
		while(true){
			n = Integer.parseInt(br.readLine());
			if(n == 0) break;
			
			arr = new int[n + 1][n + 1];
			
			for(int i=1; i<=n; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=1; j<=n; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			int ans = solve();
			System.out.printf("Problem %d: %d\n", t++, ans);
		}
	}
	
	public static int solve() {
		int[][] dist = new int[n + 1][n + 1];
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				dist[i][j] = 15000000;
			}
		}
		
//		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b)-> a[0] - b[0]);
//		pq.offer(new int[] {arr[1][1], 1, 1});
		Queue<int[]> q = new LinkedList<>();
		q.offer(new int[] {1, 1});
		dist[1][1] = arr[1][1];
		
		while(!q.isEmpty()) {
			int[] curr = q.poll();
//			int currD = curr[0];
			int r = curr[0];
			int c = curr[1];
			
			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				
				if(!check(nr, nc)) continue;
				
				int nxtD = dist[r][c] + arr[nr][nc];
				
				if(dist[nr][nc] <= nxtD) continue;
				
				dist[nr][nc] = nxtD;
				q.offer(new int[] {nr, nc});
			}
		}
		
		return dist[n][n];
	}
	
	private static boolean check(int r, int c) {
		return r > 0 && r <= n && c > 0 && c <= n;
	}
}
