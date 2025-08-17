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
	
	static int n, m;
	static char[][] board;
	static int ans;
	
	static int sr, sc;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException{
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		board = new char[n][m];
		
		for(int i=0; i<n; i++) {
			String line = br.readLine();
			for(int j=0; j<m; j++) {
				board[i][j] = line.charAt(j);
				
				if(board[i][j] == '0') { // 민식이 서 있는 곳
					sr = i;
					sc = j;
				}
				
			}
		}
		
		solve();
		
		System.out.println(ans);
	}

	private static void solve() {
		ans = -1;
		
		Queue<int[]> que = new LinkedList<>();
		boolean[][][] visited = new boolean[n][m][64];
		
		que.offer(new int[] {sr, sc, 0, 0});
		visited[sr][sc][0] = true;
		
		while(!que.isEmpty()) {
			int[] curr = que.poll();
			int r = curr[0];
			int c = curr[1];
			int t = curr[2];
			int k = curr[3];
			
			if(board[r][c] == '1') {
				ans = t;
				return;
			}
			
			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				int nt = t + 1;
				int nk = k;
				
				if(!check(nr, nc)) continue;
				if(board[nr][nc] == '#') continue;
				
				if(board[nr][nc] >= 'A' && board[nr][nc] <= 'Z') { // 문
					int idx = board[nr][nc] - 'A';
					if((k & (1 << idx)) == 0) continue; // 열쇠없음
				}
				if(board[nr][nc] >= 'a' && board[nr][nc] <= 'f') { // 열쇠
					int idx = board[nr][nc] - 'a';
					if((k & (1 << idx)) == 0) {
						nk |= (1 << idx);
					}
				}
				
				if(visited[nr][nc][nk]) continue;
				
				que.offer(new int[] {nr, nc, nt, nk});
				visited[nr][nc][nk] = true;
			}
		}
		
		return;
	}
	static boolean check(int r, int c) {
		return r >= 0 && r < n && c >= 0 && c < m;
	}
	
}
