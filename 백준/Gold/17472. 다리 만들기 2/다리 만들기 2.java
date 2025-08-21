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
	
	static int N, M;
	static int[][] board;
	static int ans;
	
	static ArrayList<int[]>[] g;
	
	static int[] dr = {-1, 0, 1, 0};
	static int[] dc = {0, 1, 0, -1};
	
	public static void main(String[] args) throws IOException {
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		
		g = new ArrayList[8]; // 최대 6개의 섬 (2, 3, 4, 5, 6, 7)
		for(int i=2; i<=7; i++) {
			g[i] = new ArrayList<>();
		}
		
		for(int i=0; i<N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j=0; j<M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		solve();
		
		System.out.println(ans);
			
	}
	
	static void solve() {
		ans = 0;
		
		int id = 1;
		
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				if(board[i][j] == 1) {
					mark(i, j, ++id);
				}
			}
		}
		
		mst(id);
		
	}
	
	static void mst(int maxId) {
		PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[0] - o2[0]);
		boolean[] visited = new boolean[8];
		
		pq.offer(new int[] {0, 2}); // {거리, 섬}
		
		int total = 0, cnt = 0;
		while(!pq.isEmpty()) {
			int[] curr = pq.poll();
			int currD = curr[0];
			int currV = curr[1];
			
			if(visited[currV]) continue;
			visited[currV] = true;
			
			total += currD;
			cnt++;
			
			for(int[] nxt : g[currV]) {
				int nxtV = nxt[0];
				int nxtD = nxt[1];
				
				if(visited[nxtV]) continue;
				
				pq.offer(new int[] {nxtD, nxtV});
				
			}
		}
		
		if(cnt == maxId - 1) ans = total;
		else ans = -1;
	}
	static void mark(int sr, int sc, int id) {
		Queue<int[]> que = new LinkedList<>();
		Queue<int[]> bridge = new LinkedList<>();
		boolean[][] visited = new boolean[N][M];
		
		board[sr][sc] = id;
		que.offer(new int[] {sr, sc});
		visited[sr][sc] = true;
		
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
					bridge.offer(new int[] {nr, nc, 1, d});
					continue;
				}
				else if(board[nr][nc] == 1) {
					que.offer(new int[] {nr, nc});
					visited[nr][nc] = true;
					board[nr][nc] = id;
				}
			}
			
		}
		
		if(id == 2) return;
		
		boolean[] v2 = new boolean[8];
		
		while(!bridge.isEmpty()) {
			int[] curr = bridge.poll();
			int r = curr[0];
			int c = curr[1];
			int len = curr[2];
			int d = curr[3];
			
			int nr = r + dr[d];
			int nc = c + dc[d];
			
			if(!check(nr, nc)) continue;
			
			int value = board[nr][nc];
			if(value == 0) {
				bridge.offer(new int[] {nr, nc, len + 1, d});
				continue;
			}
			else if(value > 1 && !v2[value] && len >= 2) {
				g[id].add(new int[] {value, len});
				g[value].add(new int[] {id, len});
				v2[board[nr][nc]] = true;
			}
		}
	}
	
	static boolean check(int r, int c) {
		return r >= 0 && r < N && c >= 0 && c < M;
	}
}