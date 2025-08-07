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
	
	static int k, w, h;
	static int[][] board;
	static int ans;
	
	// 원숭이 이동
	static int[] dr4 = {-1, 1, 0, 0};
	static int[] dc4 = {0, 0, -1, 1};
	
	// 말 이동
	static int[] dr8 = {-2, -1, 1, 2, 2, 1, -1, -2};
	static int[] dc8 = {1, 2, 2, 1, -1, -2, -2, -1};
	
	public static void main(String[] args) throws IOException{
		k = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine());
		w = Integer.parseInt(st.nextToken());
		h = Integer.parseInt(st.nextToken());
		
		board = new int[h][w];
		
		for(int i=0; i<h; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j=0; j<w; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		solve();
		
		System.out.println(ans);
	}

	private static void solve() {
		ans = -1;
		
		Queue<int[]> que = new LinkedList<>();
		boolean[][][] visited = new boolean[h][w][k + 1];
		
		que.offer(new int[] {0, 0, 0, 0});
		visited[0][0][0] = true;
		
		while(!que.isEmpty()) {
			int[] curr = que.poll();
			int r = curr[0];
			int c = curr[1];
			int cnt = curr[2];
			int horse = curr[3];
			
			if(r == h - 1 && c == w - 1) {
				ans = cnt;
				return;
			}
			
			// 원숭이처럼 이동
			for(int d=0; d<4; d++) {
				int nr = r + dr4[d];
				int nc = c + dc4[d];
				
				if(!check(nr, nc)) continue;
				if(board[nr][nc] == 1) continue;
				if(visited[nr][nc][horse]) continue;
				
				
				que.offer(new int[] {nr, nc, cnt + 1, horse});
				visited[nr][nc][horse] = true;
			}
			
			if(horse >= k) continue; // 이미 k번 움직임
			
			// 말처럼 이동
			for(int d=0; d<8; d++) {
				int nr = r + dr8[d];
				int nc = c + dc8[d];
				
				if(!check(nr, nc)) continue;
				if(board[nr][nc] == 1) continue;
				if(visited[nr][nc][horse + 1]) continue;
				
				que.offer(new int[] {nr, nc, cnt + 1, horse + 1});
				visited[nr][nc][horse + 1] = true;
			}
		}
		
		return;
	}

	private static boolean check(int r, int c) {
		return r >=0 && r < h && c >= 0 && c < w;
	}
	
}
