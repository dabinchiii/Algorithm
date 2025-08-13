import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int N, M;
	static int[][] board;
	static int ans;
	
	static ArrayList<int[]> cctv;
	
	// 0상 1하 2좌 3우
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	// 시계90: 상->우3 하->좌2 좌->상0 우->하1
	static int[] cw = {3, 2, 0, 1};
	
	// 반시계90: 상->좌2 하->우3 좌->하1 우->상0
	static int[] ccw = {2, 3, 1, 0};
	
	// 반대: 상->하1 하->상0 좌->우3 우->좌2
	static int[] opp = {1, 0, 3, 2};
	
	public static void main(String[] args)  throws IOException{
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		cctv = new ArrayList<>();
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j] >= 1 && board[i][j] <= 5) {
					cctv.add(new int[] {board[i][j], i, j});
				}
			}
			
			
		}
		solve();
		System.out.println(ans);
		
	}
	
	static void solve() {
		ans = 64;
		dfs(0, 0);
	}
	
	static void dfs(int cnt, int start) {
		if(cnt == cctv.size()) {
//			print();
			ans = Math.min(ans, cntBlind());
			return;
		}
		
		for(int i=start; i<cctv.size(); i++) {
			int[][] tmp = new int[N][M];
			for(int j=0; j<N; j++) tmp[j] = board[j].clone();
			
			int cid = cctv.get(i)[0];
			int sr = cctv.get(i)[1];
			int sc = cctv.get(i)[2];
			
			if(cid == 1) {
				for(int d=0; d<4; d++) {
					markSight(sr, sc, d);
					dfs(cnt + 1, i + 1);
					for(int j=0; j<N; j++) board[j] = tmp[j].clone();
				}
			}
			else if(cid == 2) {
				for(int d=0; d<4; d+=2) {
					markSight(sr, sc, d);
					markSight(sr, sc, opp[d]);
					dfs(cnt + 1, i + 1);
					for(int j=0; j<N; j++) board[j] = tmp[j].clone();
				}
				
			}
			else if(cid == 3) {
				for(int d=0; d<4; d++) {
					markSight(sr, sc, d);
					markSight(sr, sc, cw[d]);
					dfs(cnt + 1, i + 1);
					for(int j=0; j<N; j++) board[j] = tmp[j].clone();
				}
			}
			else if(cid == 4) {
				for(int d=0; d<4; d++) {
					markSight(sr, sc, d);
					markSight(sr, sc, cw[d]);
					markSight(sr, sc, ccw[d]);
					dfs(cnt + 1, i + 1);
					for(int j=0; j<N; j++) board[j] = tmp[j].clone();
				}
			}
			else if(cid == 5) {
				for(int d=0; d<4; d++) {
					markSight(sr, sc, d);
				}
				dfs(cnt + 1, i + 1);
				for(int j=0; j<N; j++) board[j] = tmp[j].clone();
			}
		}
	}
	
	static void markSight(int r, int c, int d) {
		while(true) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			
			if(!check(nr, nc)) break;
			if(board[nr][nc] == 6) break;
			
			board[nr][nc] = -1;
			
			r = nr;
			c = nc;
		}
	}
	static int cntBlind() {
		int cnt = 0;
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(board[i][j] == 0) cnt++;
			}
		}
		return cnt;
	}
	static boolean check(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < M;
	}
	
	static void print() {
		System.out.println("=====================\n");
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				System.out.print((board[i][j] != -1 ? board[i][j] + "" : "#") + " ");
			}
			System.out.println();
		}
		System.out.println("-> " + cntBlind());
	}
}
