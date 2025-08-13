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

public class Solution {

	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringTokenizer st;

	static int N, K;
	static int[][] board;
	static int ans;
	
	static ArrayList<int[]> s;
	static int maxH;
	
	static int[][] dist;
	
	static int[] dr = {-1, 1, 0, 0};
	static int[] dc = {0, 0, -1, 1};
	
	public static void main(String[] args)  throws IOException{
		int T;
		T = Integer.parseInt(br.readLine());
		for(int t=1; t<=T; t++) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			
			board = new int[N][N];
			dist = new int[N][N];
			s = new ArrayList<>();
			
			maxH = -1;
			for(int i=0; i<N; i++) {
				st = new StringTokenizer(br.readLine());
				for(int j=0; j<N; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if(board[i][j] > maxH) {
						maxH = board[i][j];
						s.clear();
					}
					if(board[i][j] == maxH) {
						s.add(new int[] {i, j});
					}
				}
			}
			
			solve();
			
			bw.write("#" + t + " " + ans + "\n");
		}
		
		bw.flush();
		bw.close();
	}
	
	static void solve() {
		ans = -1;
		
		for(int i=0; i<N; i++) {
			Arrays.fill(dist[i], -1);;
		}
		for(int[] curr : s) {
			dist[curr[0]][curr[1]] = 1;
			dfs(curr[0], curr[1], 1, 0);
			dist[curr[0]][curr[1]] = -1;
		}
		
	}
	
	static void dfs(int r, int c, int len, int dg) {
		ans = Math.max(ans,  len);
//		printDist();
		
		for(int d=0; d<4; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			
			if(!check(nr, nc)) continue;
			if(dist[nr][nc] != -1) continue;
			
			int tmp = dist[nr][nc];
			if(board[nr][nc] < board[r][c]) {
				dist[nr][nc] = len + 1;
				dfs(nr, nc, len + 1, dg);
				dist[nr][nc] = tmp;
			}
			else if(dg == 0) {
				for(int i=1; i<=K; i++) {
					if(board[nr][nc] - i >= board[r][c]) continue;
					board[nr][nc] -= i;
					dist[nr][nc] = len + 1;
					dfs(nr, nc, len + 1, 1);
					dist[nr][nc] = tmp;
					board[nr][nc] += i;
				}
			}
			
		}
	}
	
	static boolean check(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < N;
	}
	
	static void printDist() {
		for(int i=0; i<N; i++) {
			for(int j=0; j<N; j++) {
				System.out.print(dist[i][j] + " ");
			}
			System.out.println();
		}
		
		System.out.println("======");
	}
}
