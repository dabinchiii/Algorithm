import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	static final int INF = Integer.MAX_VALUE;
	
	static int N, M;
	static ArrayList<int[]>[] g;
	static int start, end;
	static int[] dist;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		g = new ArrayList[N + 1];
		dist = new int[N + 1];
		
		for(int i=1; i<=N; i++) {
			g[i] = new ArrayList<>();
			dist[i] = INF;
		}
		
		int a, b, c;
		for(int i=0; i<M; i++) {
			st = new StringTokenizer(br.readLine());
			
			a = Integer.parseInt(st.nextToken());
			b = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			
			g[a].add(new int[] {b, c});
			//g[b].add(new int[] {a, c});
		}
		
		st = new StringTokenizer(br.readLine());
		start = Integer.parseInt(st.nextToken());
		end = Integer.parseInt(st.nextToken());
		
		dijkstra();
		
		System.out.println(dist[end]);
	}
	
	static void dijkstra() {
		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
		
		dist[start] = 0;
		pq.add(new int[]{start, 0});
		
		while(!pq.isEmpty()) {
			int[] curr = pq.poll();
			int currV = curr[0];
			int currD = curr[1];
			
			if(dist[currV] < currD) continue;
			
			for(int[] nxt : g[currV]) {
				int nxtV = nxt[0];
				int nxtD = currD + nxt[1];
				
				if(nxtD < dist[nxtV]) {
					dist[nxtV] = nxtD;
					pq.add(new int[] {nxtV, nxtD});
				}
			}
		}
		
	}
}
