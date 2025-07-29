import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;


public class Main {
	static int n, m;
	static int[][] arr;
	static int[][] visited;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		visited = new int[n][m];
		
		arr = new int[n][m];
		for(int i=0; i<n; i++) {
			String ss = br.readLine();
			char[] cs = ss.toCharArray();
			for(int j=0; j<m; j++) {
				arr[i][j] = cs[j] - '0';
			}
		}
		
		Queue<int[]> q = new LinkedList<>();
		visited[0][0] = 1;
		q.offer(new int[] {0, 0});
		
		while(!q.isEmpty()) {
			int[] curr = q.poll();
			int r = curr[0];
			int c = curr[1];
			
			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				if(!check(nr, nc)) continue;
				if(visited[nr][nc] != 0) continue;
				if(arr[nr][nc] == 0) continue;
				
				visited[nr][nc] = visited[r][c] + 1;
				q.offer(new int[] {nr, nc});
				
				
			}
		}
		
		System.out.println(visited[n - 1][m - 1]);
	}

	private static boolean check(int r, int c) {
		return r>=0 && r<n && c>=0 && c<m;
	}
}
