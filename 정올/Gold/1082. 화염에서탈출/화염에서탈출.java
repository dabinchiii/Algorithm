import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;
	
	static int R, C;
	static char[][] board;
	static int ans;
	
	static int dx, dy;
	static Queue<int[]> queJW, queFire;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args) throws IOException{
		st = new StringTokenizer(br.readLine());
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		
		board = new char[R][C];
		
		queJW = new LinkedList<>();
		queFire = new LinkedList<>();
		
		for(int i=0; i<R; i++) {
			String line = br.readLine();
			for(int j=0; j<C; j++) {
				board[i][j] = line.charAt(j);
				
				if(board[i][j] == '*') {
					queFire.offer(new int[] {i, j});
				}
				else if(board[i][j] == 'D') {
					dx = i;
					dy = j;
				}
				else if(board[i][j] == 'S') {
					board[i][j] = 'J';
					queJW.offer(new int[] {i, j, 0});
				}
			}
		}
		
		solve();
		
		if(ans != -1) System.out.println(ans);
		else System.out.println("impossible");
	}
	
	static void solve() {
		ans = -1;
		
		while(!queJW.isEmpty()) {
			// 재우 퍼뜨리기
			int cntJW = queJW.size();
			for(int i=0; i<cntJW; i++) {
				int[] curr = queJW.poll();
				int r = curr[0];
				int c = curr[1];
				int dist = curr[2];
				
				if(board[r][c] != 'J') continue;
				
				for(int d=0; d<4; d++) {
					int nr = r + dr[d];
					int nc = c + dc[d];
					
					if(!check(nr, nc)) continue;
					
					if(board[nr][nc] == 'D') {
						ans = dist + 1;
						return;
					}
					
					if(board[nr][nc] == '.') {
						board[nr][nc] = 'J';
						queJW.offer(new int[] {nr, nc, dist + 1});
					}
				}
				
			}
			
			// 불 퍼뜨리기
			int cntFire = queFire.size();
			for(int i=0; i<cntFire; i++) {
				int[] curr = queFire.poll();
				int r = curr[0];
				int c = curr[1];
				
				for(int d=0; d<4; d++) {
					int nr = r + dr[d];
					int nc = c + dc[d];
					
					if(!check(nr, nc)) continue;
					if(board[nr][nc] == '.' || board[nr][nc] == 'J') {
						board[nr][nc] = '*';
						queFire.offer(new int[] {nr, nc});
					}
				}
			}
//			print();
		}
		
	
	}
	
	static boolean check(int r, int c) {
		return r >= 0 && r < R && c >= 0 && c < C;
	}
	
	static void print() {
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				System.out.print(board[i][j]);
			}
			System.out.println();
			
		}
		System.out.println();
	}
}
