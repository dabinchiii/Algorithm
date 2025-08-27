import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

class Main{
	
	static int N, M;
	static ArrayList<Integer>[] g;
	static int[] inDegree; // 정점 별 진입차수 
	static int[] ans;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		g = new ArrayList[N + 1];
		for(int i=1; i<=N; i++) {
			g[i] = new ArrayList<>();
		}
		
		inDegree = new int[N + 1];
		ans = new int[N + 1];
		
		int A, B;
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			A = Integer.parseInt(st.nextToken());
			B = Integer.parseInt(st.nextToken());
			
			g[A].add(B);
			inDegree[B]++;
		}
		
		solve();
		
		StringBuilder sb = new StringBuilder();
		for(int i=1; i<=N; i++) {
			sb.append(ans[i] + " ");
		}
		System.out.println(sb.toString());
	}
	
	static void solve() {
		Queue<Integer> q = new LinkedList<>();
		
		for(int i=1; i<=N; i++) {
			if(inDegree[i] == 0) q.offer(i); // 진입 차수가 0인 정점을 큐에 넣는다. 
		}
		
		int round = 0;
		while(true) {
			int cnt = q.size();
			if(cnt == 0) break;
			
			round++;
			
			for(int i=0; i<cnt; i++) {
				int curr = q.poll();
				ans[curr] = round;
				
				for(int nxt : g[curr]) {
					if(--inDegree[nxt] == 0) q.offer(nxt);
				}
			}
		}
	}
}