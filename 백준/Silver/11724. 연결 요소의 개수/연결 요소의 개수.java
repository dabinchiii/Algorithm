import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n, m;
	static ArrayList<Integer>[] g;
	static int ans;
	
	static boolean[] visited;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
//		System.setIn(new FileInputStream("Test3.txt"));
		st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		g = new ArrayList[n + 1];
		for(int i=1; i<=n; i++) {
			g[i] = new ArrayList<>();
		}
		visited = new boolean[n + 1];
		
		int u, v;
		for(int i=0; i<m; i++) {
			st = new StringTokenizer(br.readLine());
			u = Integer.parseInt(st.nextToken());
			v = Integer.parseInt(st.nextToken());
			
			// 양방향
			g[u].add(v);
			g[v].add(u);
		}
		
		solve();
		
		System.out.println(ans);
	}
	
	static void solve() {
		for(int i=1; i<=n; i++) {
			if(visited[i]) continue;
			bfs(i);
			ans++;
		}
	}
	
	static void bfs(int s) {
		Queue<Integer> q = new LinkedList<>();
		
		visited[s] = true;
		q.offer(s);
		
		while(!q.isEmpty()) {
			int curr = q.poll();
			
			for(int i=0; i<g[curr].size(); i++) {
				int nxt = g[curr].get(i);
				
				if(visited[nxt]) continue;
				
				q.offer(nxt);
				visited[nxt] = true;
			}
		}
	}

}
