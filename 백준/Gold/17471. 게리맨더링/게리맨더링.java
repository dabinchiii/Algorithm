import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	
	static int n;
	static int[] pop;
	static ArrayList<Integer> g[];
	static int ans;
	
	static int[] p = {0, 1};
	static int[] arr;
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		n = Integer.parseInt(br.readLine());
		pop = new int[n + 1];
		arr = new int[n + 1];
		
		g = new ArrayList[n + 1];
		for(int i=1; i<=n; i++) g[i] = new ArrayList<>();
		
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++) {
			pop[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=1; i<=n; i++) {
			st = new StringTokenizer(br.readLine());
			int num = Integer.parseInt(st.nextToken());
			for(int j=0; j<num; j++) {
				g[i].add(Integer.parseInt(st.nextToken()));
			}
		}
		
		solve();
		
		System.out.println(ans);
	}
	
	static void solve() {
		ans = Integer.MAX_VALUE;
		perm(1, n);
		
		if(ans == Integer.MAX_VALUE) ans =-1;
	}
	
	static void perm(int cnt, int tot) {
		if(cnt == tot + 1) {
//			System.out.println(Arrays.toString(arr));
			check();
			return;
		}

		for(int i=0; i<2; i++) {
			arr[cnt] = p[i];
			perm(cnt + 1, tot);
		}
		return;
	}
	
	static void check() {
		boolean[] visited = new boolean[n + 1];
		int cnt = 0;
		for(int i=1; i<=n; i++) {
			if(visited[i]) continue;
			bfs(i, visited);
			cnt++;
		}
		
		if(cnt != 2) return;
		
		int sumA = 0, sumB = 0;
		for(int i=1; i<=n; i++) {
			if(arr[i] == 1) sumA += pop[i];
			else sumB += pop[i];
		}
		
		ans = Math.min(ans, Math.abs(sumA - sumB));
		
	}
	static void bfs(int start, boolean[] visited) {
		Queue<Integer> q = new LinkedList<>();
		
		q.offer(start);
		visited[start] = true;
		
		while(!q.isEmpty()) {
			int curr = q.poll();
			
			for(int i=0; i<g[curr].size(); i++) {
				int nxt = g[curr].get(i);
				if(arr[nxt] != arr[curr]) continue;
				if(visited[nxt]) continue;
				
				q.offer(nxt);
				visited[nxt] = true;
			}
		}
		
		
	}
}
