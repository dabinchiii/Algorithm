import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int h, w;
	static int[][] board;
	static int initCnt;
	static int ansT, ansCnt;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException{
		st = new StringTokenizer(br.readLine());
		h = Integer.parseInt(st.nextToken());
		w = Integer.parseInt(st.nextToken());
		board = new int[h][w];
		
		for(int i=0; i<h; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<w; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if(board[i][j] == 1) initCnt++;
			}
		}
		
		solve();
		
		System.out.println(ansT);
		System.out.println(ansCnt);
	}

	private static void solve() {
		int t = 1;
		int currCnt = initCnt;
		
		while(true) {
			markEdge();
			//System.out.println();
			//printBoard();
			int cnt = currCnt - melt();
//			System.out.println();
//			printBoard();
			if(cnt == 0) {
				break;
			}
			
			currCnt = cnt;
			
			t++;
		}
		
		ansT = t;
		ansCnt = currCnt;
	}
	
	private static int melt() {
		int cnt = 0;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(board[i][j] != 2) continue;
				board[i][j] = 0;
				cnt++;
			}
		}
		
		return cnt;
	}

	private static void markEdge() {
		Queue<int[]> q = new LinkedList<>();
		boolean[][] visited = new boolean[h][w];
		
		q.offer(new int[] {0, 0});
		visited[0][0] = true;
		
		while(!q.isEmpty()) {
			int[] curr = q.poll();
			int r = curr[0];
			int c = curr[1];
			
			for(int d=0; d<4; d++) {
				int nr = r + dr[d];
				int nc = c + dc[d];
				
				if(!check(nr, nc) || visited[nr][nc]) continue;
				
				if(board[nr][nc] == 0) {
					q.offer(new int[] {nr, nc});
					visited[nr][nc] = true;
				}
				else { // 치즈 겉부분
					board[nr][nc] = 2;
					visited[nr][nc] = true;
				}
			}
		}
	}

	private static boolean check(int r, int c) {
		return r >= 0 && r < h && c >= 0 && c < w;
	}
	
	private static void printBoard() {
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
	}
}
