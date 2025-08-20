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
	
	static int N;
	static int[][] board;
	static int ans;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException {
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		solve();
		
		System.out.println(ans);
	}
	
	static void solve() {
		ans = 100000;
		
		int id = 1;
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				if(board[i][j] == 1) {
					mark(i, j, ++id);
				}
				
				
			}
		}
	}
	
	static void mark(int sr, int sc, int id) {
		Queue<int[]> que = new LinkedList<>();
		Queue<int[]> water = new  LinkedList<>();
		boolean[][] visited = new boolean[N][N];
		
		que.offer(new int[] {sr, sc});
		visited[sr][sc] = true;
		board[sr][sc] = id;
		
		while(!que.isEmpty()) {
			int[] curr = que.poll();
			int r = curr[0];
			int c = curr[1];
			
			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				
				if(!check(nr, nc)) continue;
				if(visited[nr][nc]) continue;
				
				if(board[nr][nc] == 0) {
					visited[nr][nc] = true;
					water.offer(new int[] {nr, nc, 1});
					continue;
				}
				
				
				board[nr][nc] = id;
				que.offer(new int[] {nr, nc});
				visited[nr][nc] = true;
			}
		}
		
		if(id == 2) return;
		
		while(!water.isEmpty()) {
			int[] curr = water.poll();
			int r = curr[0];
			int c = curr[1];
			int dist = curr[2];
			
			if(dist > ans) continue;
			
			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				
				if(!check(nr, nc)) continue;
				if(visited[nr][nc]) continue;
				
				if(board[nr][nc] > 1) {
//					System.out.printf("%d -> %d: %d\n", id, board[nr][nc], dist);
					ans = Math.min(ans,  dist);
					return;
				}
				else if(board[nr][nc] == 0) {
					visited[nr][nc] = true;
					water.offer(new int[] {nr, nc, dist + 1});
				}
			}
		}
		
		return;
	}
	
	static boolean check(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}
}
