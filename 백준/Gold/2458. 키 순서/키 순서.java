import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;


class Main
{
	static final int INF = 2500;
	static int N, M;
	static int[][] g, rg;
	static int ans;
	
	
	public static void main(String args[]) throws Exception
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		//int T = Integer.parseInt(br.readLine());
		//for(int test_case = 1; test_case <= T; test_case++)
		//{
			//N = Integer.parseInt(br.readLine());
			//M = Integer.parseInt(br.readLine());
			
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			
			g = new int[N + 1][N + 1];
			rg = new int[N + 1][N + 1];
			
			for(int i=1; i<=N; i++) {
				for(int j=1; j<=N; j++) {
					if(i != j) g[i][j] = rg[i][j] = INF;
				}
			}
			
			int a, b;
			for(int i=0; i<M; i++) {
				st = new StringTokenizer(br.readLine());
				a = Integer.parseInt(st.nextToken());
				b = Integer.parseInt(st.nextToken());
				
				g[a][b] = rg[b][a] = 1;
			}
			
			solve();
			
			//System.out.printf("#%d %d\n", test_case, ans);
			System.out.println(ans);
		//}
	}
	
	static void solve() {
		ans = 0;
		for(int k=1; k<=N; k++) {
			for(int u=1; u<=N; u++) {
				for(int v=1; v<=N; v++) {
					g[u][v] = Math.min(g[u][v], g[u][k] + g[k][v]);
					rg[u][v] = Math.min(rg[u][v], rg[u][k] + rg[k][v]);
				}
			}
		}
		
		
		for(int i=1; i<=N; i++) {
			int cnt = 0;
			for(int j=1; j<=N; j++) {
				if(i == j) continue;
				
				if(g[i][j] != INF) cnt++;
				if(rg[i][j] != INF) cnt++;
			}
			if(cnt == N - 1) ans++;
		}
		
	}

}