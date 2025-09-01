import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
	
	static int N, M, K;
	static char[][] board;
	static int row1, col1, row2, col2;
	static int ans;
	
	// 상하좌우
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		board = new char[N][M];
		
		String line;
		for(int i=0; i<N; i++) {
			line = br.readLine();
			for(int j=0; j<M; j++) {
				board[i][j] = line.charAt(j);
			}
		}
		
		st = new StringTokenizer(br.readLine());
		row1 = Integer.parseInt(st.nextToken());
		col1 = Integer.parseInt(st.nextToken());
		row2 = Integer.parseInt(st.nextToken());
		col2 = Integer.parseInt(st.nextToken());
		--row1; --col1; --row2; --col2; // 1-based에서 0-based로 수정
		
		solve();
		
		System.out.println(ans);
	}
	
	static void solve() {
		ans = -1;
		
		final int INF = 1000001;
//		PriorityQueue<int[]> que = new PriorityQueue<>((a, b)->a[2]-b[2]);
		Queue<int[]> que = new LinkedList<>();
		int[][] dist = new int[N][M];
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				dist[i][j] = INF;
			}
		}
		
		que.offer(new int[] {row1, col1, 0});
		dist[row1][col1] = 0;
		
		while(!que.isEmpty()) {
			int[] curr = que.poll();
			int r = curr[0];
			int c = curr[1];
			int t = curr[2];
			
			if(dist[r][c] < t) continue;
			
			for(int d=0; d<4; d++) {
				int nr = r, nc = c;
				int nt = t + 1;
				for(int k=0; k<K; k++) { // 최대 K번
					nr += dr[d];
					nc += dc[d];
					
					if(!check(nr, nc)) break;
					if(board[nr][nc] == '#') break;
					if(dist[nr][nc] <= dist[r][c]) break;
					
					if(dist[nr][nc] > nt) {
						dist[nr][nc] = nt;
						que.offer(new int[] {nr, nc, nt});
					}
				}
			}
		}
		
		if(dist[row2][col2] == INF) ans = -1;
		else ans = dist[row2][col2];
		
		
//		System.out.println("dist");
//		for(int i=0; i<N; i++) {
//			for(int j=0; j<M; j++) {
//				System.out.print(dist[i][j] + " ");
//			}
//			System.out.println();
//		}
		
		return;
	}
	
	static boolean check(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < M;
	}
}
