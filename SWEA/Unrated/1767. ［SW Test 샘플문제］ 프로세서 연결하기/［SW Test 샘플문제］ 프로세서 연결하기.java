import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
 
public class Solution {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
     
    static int N;
    static int[][] board;
    static int ans;
    
    static ArrayList<int[]> core;
    static int maxConnected;
    
    static int[] dr = {-1, 1, 0, 0};
    static int[] dc = {0, 0, -1, 1};
    
    public static void main(String[] args) throws IOException {
    	int T;
    	T = Integer.parseInt(br.readLine());
    	for(int t=1; t<=T; t++) {
    		N = Integer.parseInt(br.readLine().trim());
    		board = new int[N][N];
    		core = new ArrayList<>();
    		
    		for(int i=0; i<N; i++) {
    			st = new StringTokenizer(br.readLine());
    			for(int j=0; j<N; j++) {
    				board[i][j] = Integer.parseInt(st.nextToken());
    				
    				if(board[i][j] == 0) continue;
    				if(i == 0 || i == N - 1 || j == 0 || j == N - 1) continue; // 이미 연결된 코어
    				
    				core.add(new int[] {i, j});
    			}
    		}
    		
    		solve();
    		
    		bw.write("#" + t + " " + ans + "\n");
    		
    	}
    	bw.flush();
    	bw.close();
    	
    	return;
	}
    
    static void solve() {
    	ans = 0;
    	maxConnected = 0;
    	
    	dfs(0, 0, 0);
    	
    	return;
    }
    static void dfs(int cnt, int cntConnected, int cntWire) {
    	if(cnt == core.size()) {
    		if(cntConnected > maxConnected) {
    			maxConnected = cntConnected;
    			ans = cntWire;
    		}
    		else if(cntConnected == maxConnected) {
    			if(cntWire < ans) {
    				ans = cntWire;
    			}
    		}
    		
//    		print();
    		
    		return;
    	}
    	
    	int r = core.get(cnt)[0];
    	int c = core.get(cnt)[1];
    	
    	for(int d=0; d<4; d++) {
    		if(!isAvailable(r, c, d)) continue;
    		int w = mark(r, c, d, 2);
    		dfs(cnt + 1, cntConnected + 1, cntWire + w);
    		mark(r, c, d, 0);
    	}
    	
    	dfs(cnt + 1, cntConnected, cntWire);
    	
    	return;
    }
    static boolean isAvailable(int r, int c, int d) {
    	int nr = r + dr[d];
		int nc = c + dc[d];
		
    	while(true) {
    		if(nr < 0 || nr >= N || nc < 0 || nc >= N) {
    			break;
    		}
    		if(board[nr][nc] > 0) return false;
    		
    		nr += dr[d];
    		nc += dc[d];
    	}
    	
    	return true;
    }
    static int mark(int r, int c, int d, int s) {
    	int cnt = 0;
    	int nr = r + dr[d];
		int nc = c + dc[d];
		
    	while(true) {
    		if(nr < 0 || nr >= N || nc < 0 || nc >= N) {
    			break;
    		}
    		board[nr][nc] = s;
    		cnt++;
    		
    		nr += dr[d];
    		nc += dc[d];
    	}
    	
    	return cnt;
    }
    
    static void print() {
    	
    	for(int i=0; i<N; i++) {
    		for(int j=0; j<N; j++) {
    			System.out.print(board[i][j] + " ");
    		}
    		System.out.println();
    	}
    }
    
}